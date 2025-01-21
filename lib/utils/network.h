#ifndef NETWORK_H
#define NETWORK_H

#include "pico/cyw43_arch.h"

#include "lwipopts.h"
#include "lwip/pbuf.h"
#include "lwip/ip_addr.h"
#include "lwip/netif.h"
#include "lwip/dhcp.h"
#include "lwip/tcpip.h"

#define AP_SSID "xX_uwu_pico_ap_uwu_Xx"
#define AP_PASSWORD "uwu_pico_ap_i_wonder_who_connects_123_uwu"
#define AP_IP "192.168.4.1"
#define AP_NETMASK "255.255.255.0"
#define AP_GATEWAY "192.168.4.1"

#define UDP_PORT 10000
#define BUFFER_SIZE 512 // packet size

typedef struct {

} data_packet;

void udp_reciver(void *arg, struct udp_pcb *pcb, struct pbuf *p, const ip_addr_t *addr, u16_t port);
uint8_t start_ap(void);

#endif