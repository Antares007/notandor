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
/// for each ioctl keep diffrent ifreq structure otherwise error
/// may come in sending(sendto )
int sock_raw;

#define DESTMAC0 0xF4
#define DESTMAC1 0x96
#define DESTMAC2 0x34
#define DESTMAC3 0x0A
#define DESTMAC4 0x0E
#define DESTMAC5 0x0B
#define DESTINATION_IP "192.168.240.225"
#define IFNAME "wlp2s0"

void get_eth_index(struct sockaddr_ll *sadr_ll) {
  struct ifreq ifreq_i;
  memset(&ifreq_i, 0, sizeof(ifreq_i));
  strncpy(ifreq_i.ifr_name, IFNAME, IFNAMSIZ - 1);
  if ((ioctl(sock_raw, SIOCGIFINDEX, &ifreq_i)) < 0)
    printf("error in index ioctl reading"), exit(1);
  printf("index=%d\n", ifreq_i.ifr_ifindex);
  sadr_ll->sll_ifindex = ifreq_i.ifr_ifindex;
}

void get_mac(struct ethhdr *eth, const char *ifname) {
  struct ifreq ifreq_c;
  memset(&ifreq_c, 0, sizeof(ifreq_c));
  strncpy(ifreq_c.ifr_name, ifname, IFNAMSIZ - 1);
  if ((ioctl(sock_raw, SIOCGIFHWADDR, &ifreq_c)) < 0)
    printf("error in SIOCGIFHWADDR ioctl reading");
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

  eth->h_dest[0] = DESTMAC0;
  eth->h_dest[1] = DESTMAC1;
  eth->h_dest[2] = DESTMAC2;
  eth->h_dest[3] = DESTMAC3;
  eth->h_dest[4] = DESTMAC4;
  eth->h_dest[5] = DESTMAC5;

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
void get_ip(struct iphdr *iph, int data_lengt) {
  struct ifreq ifreq_ip;
  memset(&ifreq_ip, 0, sizeof(ifreq_ip));
  strncpy(ifreq_ip.ifr_name, IFNAME, IFNAMSIZ - 1);
  if (ioctl(sock_raw, SIOCGIFADDR, &ifreq_ip) < 0) {
    printf("error in SIOCGIFADDR \n");
  }
  printf("Source IP: %s\n",
         inet_ntoa((((struct sockaddr_in *)&(ifreq_ip.ifr_addr))->sin_addr)));
  iph->ihl = 5;
  iph->version = 4;
  iph->tos = 16;
  iph->id = htons(4849);
  iph->ttl = 64;
  iph->protocol = 17;
  iph->saddr = inet_addr(
      inet_ntoa((((struct sockaddr_in *)&(ifreq_ip.ifr_addr))->sin_addr)));
  iph->daddr = inet_addr(DESTINATION_IP); // put destination IP address
  iph->tot_len = htons(data_lengt + sizeof(struct iphdr));
  iph->check =
      htons(checksum((unsigned short *)iph, (sizeof(struct iphdr) / 2)));
}

int main() {
  sock_raw = socket(AF_PACKET, SOCK_RAW, IPPROTO_RAW);
  if (sock_raw == -1)
    printf("error in socket");

  unsigned char *sendbuff[64] = {};
  int off = 0;
  get_mac((struct ethhdr *)(sendbuff + off), IFNAME);
  off += sizeof(struct ethhdr);
  get_ip((struct iphdr *)(sendbuff + off), 5);
  off += sizeof(struct iphdr);
  sendbuff[off++] = 0xaa;
  sendbuff[off++] = 0xbb;
  sendbuff[off++] = 0xcc;
  sendbuff[off++] = 0xdd;
  sendbuff[off++] = 0xee;

  struct sockaddr_ll sadr_ll;
  get_eth_index(&sadr_ll); // interface number
  sadr_ll.sll_halen = ETH_ALEN;
  sadr_ll.sll_addr[0] = DESTMAC0;
  sadr_ll.sll_addr[1] = DESTMAC1;
  sadr_ll.sll_addr[2] = DESTMAC2;
  sadr_ll.sll_addr[3] = DESTMAC3;
  sadr_ll.sll_addr[4] = DESTMAC4;
  sadr_ll.sll_addr[5] = DESTMAC5;

  printf("S:%d\n", ntohs(((struct iphdr *)(sendbuff + sizeof(struct ethhdr)))->tot_len));
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
