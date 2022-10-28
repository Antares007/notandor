/* Note: run this program as root user
 * Author:Subodh Saxena
 */
#include <errno.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/types.h>

#include <net/if.h>
#include <netinet/if_ether.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/udp.h>

#include <linux/if_packet.h>

#include <arpa/inet.h>
#include <stdlib.h>
int get_eth_index(int sock_raw, const char *ifname) {
  struct ifreq ifreq_i = {0};
  strncpy(ifreq_i.ifr_name, ifname, IFNAMSIZ - 1);
  if ((ioctl(sock_raw, SIOCGIFINDEX, &ifreq_i)) < 0)
    printf("error in index ioctl reading"), exit(1);
  printf("index=%d\n", ifreq_i.ifr_ifindex);
  return ifreq_i.ifr_ifindex;
}
void get_mac(int sock_raw, struct ethhdr *eth, const char *ifname,
             unsigned char dmac[6]) {
  struct ifreq ifreq_c;
  memset(&ifreq_c, 0, sizeof(ifreq_c));
  strncpy(ifreq_c.ifr_name, ifname, IFNAMSIZ - 1);

  if ((ioctl(sock_raw, SIOCGIFHWADDR, &ifreq_c)) < 0)
    printf("error in SIOCGIFHWADDR ioctl reading"), exit(1);

  printf("Mac= %.2X-%.2X-%.2X-%.2X-%.2X-%.2X\n",
         (unsigned char)(ifreq_c.ifr_hwaddr.sa_data[0]),
         (unsigned char)(ifreq_c.ifr_hwaddr.sa_data[1]),
         (unsigned char)(ifreq_c.ifr_hwaddr.sa_data[2]),
         (unsigned char)(ifreq_c.ifr_hwaddr.sa_data[3]),
         (unsigned char)(ifreq_c.ifr_hwaddr.sa_data[4]),
         (unsigned char)(ifreq_c.ifr_hwaddr.sa_data[5]));

  printf("ethernet packaging start ... \n");

  eth->h_source[0] = (unsigned char)(ifreq_c.ifr_hwaddr.sa_data[0]);
  eth->h_source[1] = (unsigned char)(ifreq_c.ifr_hwaddr.sa_data[1]);
  eth->h_source[2] = (unsigned char)(ifreq_c.ifr_hwaddr.sa_data[2]);
  eth->h_source[3] = (unsigned char)(ifreq_c.ifr_hwaddr.sa_data[3]);
  eth->h_source[4] = (unsigned char)(ifreq_c.ifr_hwaddr.sa_data[4]);
  eth->h_source[5] = (unsigned char)(ifreq_c.ifr_hwaddr.sa_data[5]);

  eth->h_dest[0] = dmac[0];
  eth->h_dest[1] = dmac[1];
  eth->h_dest[2] = dmac[2];
  eth->h_dest[3] = dmac[3];
  eth->h_dest[4] = dmac[4];
  eth->h_dest[5] = dmac[5];

  eth->h_proto = htons(ETH_P_IP); // 0x800

  printf("ethernet packaging done.\n");
}
unsigned short checksum(unsigned short *buff, int _16bitword) {
  unsigned long sum;
  for (sum = 0; _16bitword > 0; _16bitword--)
    sum += htons(*(buff)++);
  do {
    sum = ((sum >> 16) + (sum & 0xFFFF));
  } while (sum & 0xFFFF0000);
  return (~sum);
}
void get_ip(int sock_raw, const char *ifname, int data_len, struct iphdr *iph) {
  struct ifreq ifreq_ip;
  memset(&ifreq_ip, 0, sizeof(ifreq_ip));
  strncpy(ifreq_ip.ifr_name, ifname, IFNAMSIZ - 1);
  if (ioctl(sock_raw, SIOCGIFADDR, &ifreq_ip) < 0)
    printf("error in SIOCGIFADDR \n"), exit(1);
  const char *sipa =
      inet_ntoa((((struct sockaddr_in *)&(ifreq_ip.ifr_addr))->sin_addr));
  printf("Source IP: %s\n", sipa);
  iph->ihl = 5;
  iph->version = 4;
  iph->tos = 16;
  iph->id = htons(4849);
  iph->ttl = 64;
  iph->protocol = 14;
  iph->saddr = inet_addr(sipa);
  iph->daddr = inet_addr("192.168.240.225");

  iph->tot_len = htons(data_len + sizeof(struct iphdr));
  iph->check =
      htons(checksum((unsigned short *)iph, (sizeof(struct iphdr) / 2)));
}

int main() {
  int sock_raw = socket(AF_PACKET, SOCK_RAW, IPPROTO_RAW);
  if (sock_raw == -1)
    printf("error in socket");

  unsigned char sendbuff[64] = {0};

  unsigned char dmac[] = {0xF4, 0x96, 0x34, 0x0A, 0x0E, 0x0B};

  struct ethhdr *eth = (struct ethhdr *)(sendbuff);
  int total_len = 0;

  const char *IFNAME = "wlp2s0";
  get_mac(sock_raw, eth, IFNAME, dmac);
  total_len += sizeof(struct ethhdr);
  struct iphdr *iph = (struct iphdr *)(sendbuff + total_len);
  get_ip(sock_raw, IFNAME, 5, iph);
  total_len += sizeof(struct iphdr);
  sendbuff[total_len++] = 0xaa;
  sendbuff[total_len++] = 0xbb;
  sendbuff[total_len++] = 0xcc;
  sendbuff[total_len++] = 0xdd;
  sendbuff[total_len++] = 0xee;

  struct sockaddr_ll sadr_ll;
  sadr_ll.sll_ifindex = get_eth_index(sock_raw, IFNAME);
  sadr_ll.sll_halen = ETH_ALEN;
  sadr_ll.sll_addr[0] = dmac[0];
  sadr_ll.sll_addr[1] = dmac[1];
  sadr_ll.sll_addr[2] = dmac[2];
  sadr_ll.sll_addr[3] = dmac[3];
  sadr_ll.sll_addr[4] = dmac[4];
  sadr_ll.sll_addr[5] = dmac[5];

  printf("S:%d\n",
         ntohs(((struct iphdr *)(sendbuff + sizeof(struct ethhdr)))->tot_len));
  printf("sending...\n");
  while (1) {
    int send_len = sendto(
        sock_raw, sendbuff,
        ntohs(((struct iphdr *)(sendbuff + sizeof(struct ethhdr)))->tot_len) +
            sizeof(struct ethhdr),
        0, (const struct sockaddr *)&sadr_ll, sizeof(struct sockaddr_ll));
    if (send_len < 0) {
      printf("error in sending....sendlen=%d....errno=%d\n", send_len, errno);
      return -1;
    }
  }
}
