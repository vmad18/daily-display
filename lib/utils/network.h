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

#define WIFI_SSID     "SECRET"
#define WIFI_PASSWORD "SECRET"

#define UDP_PORT 10000
#define BUFFER_SIZE 512 // packet size

#ifdef _PICO_CYW43_ARCH_H
    #define LED_GPIO_PUT cyw43_arch_gpio_put 
    const uint8_t LED_PIN = CYW43_WL_GPIO_LED_PIN;
#else
    #define LED_GPIO_PUT gpio_put
#endif

typedef struct {
    int low; 
    int high;
    char day[10];
    char desc[30];
} day_info_t;

typedef struct {
    int temp;
    int feel_temp;
    int humidity;
    int wind;
    int pressure;
    int aqi;
    int uv;
    int hours[4];
    int day;        
    float visibility;  
    day_info_t days[5];
    bool updated;
    char sunrise[8];
    char sunset[8]; 
    char location[30];
    char curr_desc[30];
    char curr_date[30];  
    char curr_time[30];  
} data_packet_t;


extern data_packet_t data;

void udp_reciver(void *arg, struct udp_pcb *pcb, struct pbuf *p, const ip_addr_t *addr, u16_t port);
uint8_t start_ap(void);

#endif