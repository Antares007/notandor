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

  printf("Sour MAC: %.2X-%.2X-%.2X-%.2X-%.2X-%.2X ",
         (unsigned char)(ifreq_c.ifr_hwaddr.sa_data[0]),
         (unsigned char)(ifreq_c.ifr_hwaddr.sa_data[1]),
         (unsigned char)(ifreq_c.ifr_hwaddr.sa_data[2]),
         (unsigned char)(ifreq_c.ifr_hwaddr.sa_data[3]),
         (unsigned char)(ifreq_c.ifr_hwaddr.sa_data[4]),
         (unsigned char)(ifreq_c.ifr_hwaddr.sa_data[5]));

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
void get_ip(int sock_raw, const char *ifname, int data_len, struct iphdr *iph,
            const char *daddr) {
  struct ifreq ifreq_ip;
  memset(&ifreq_ip, 0, sizeof(ifreq_ip));
  strncpy(ifreq_ip.ifr_name, ifname, IFNAMSIZ - 1);
  if (ioctl(sock_raw, SIOCGIFADDR, &ifreq_ip) < 0)
    printf("error in SIOCGIFADDR \n"), exit(1);
  const char *sipa =
      inet_ntoa((((struct sockaddr_in *)&(ifreq_ip.ifr_addr))->sin_addr));
  printf("Sour IP: %s\n", sipa);
  iph->ihl = 5;
  iph->version = 4;
  iph->tos = 16;
  iph->id = htons(4849);
  iph->ttl = 64;
  iph->protocol = 14;
  iph->saddr = inet_addr(sipa);
  iph->daddr = inet_addr(daddr);

  iph->tot_len = htons(data_len + sizeof(struct iphdr));
  iph->check =
      htons(checksum((unsigned short *)iph, (sizeof(struct iphdr) / 2)));
}

int main(int argc, char **argv) {
  unsigned char dmac[] = {0XCA, 0XE8, 0X7E, 0X50, 0XE0, 0XAA};
  const char *dipa = "192.168.240.224";
  if (argc > 1)
    dipa = argv[1];
  if (argc > 2) {
    const static unsigned char map[] = {
        ['0'] = 0x0, ['1'] = 0x1, ['2'] = 0x2, ['3'] = 0x3, ['4'] = 0x4,
        ['5'] = 0x5, ['6'] = 0x6, ['7'] = 0x7, ['8'] = 0x8, ['9'] = 0x9,
        ['a'] = 0xa, ['b'] = 0xb, ['c'] = 0xc, ['d'] = 0xd, ['e'] = 0xe,
        ['f'] = 0xf, //
        ['A'] = 0XA, ['B'] = 0XB, ['C'] = 0XC, ['D'] = 0XD, ['E'] = 0XE,
        ['F'] = 0XF,
    };
    memset(dmac, 0, 6);
    for (int i = 0; i < 12; i++)
      dmac[i / 2] |= map[(int)argv[2][i]] << (i + 1) % 2 * 4;
  }
  printf("Dest MAC: %.2X-%.2X-%.2X-%.2X-%.2X-%.2X Dest IP: %s\n", dmac[0], dmac[1],
         dmac[2], dmac[3], dmac[4], dmac[5], dipa);
  int sock_raw = socket(AF_PACKET, SOCK_RAW, IPPROTO_RAW);
  if (sock_raw == -1)
    printf("error in socket"), exit(1);

  unsigned char sendbuff[64] = {0};

  //{0XF4, 0X96, 0X34, 0X0A, 0X0E, 0X0B};

  struct ethhdr *eth = (struct ethhdr *)(sendbuff);
  int total_len = 0;

  const char *IFNAME = "wlp2s0";
  get_mac(sock_raw, eth, IFNAME, dmac);
  total_len += sizeof(struct ethhdr);
  struct iphdr *iph = (struct iphdr *)(sendbuff + total_len);
  get_ip(sock_raw, IFNAME, 5, iph, dipa);
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
