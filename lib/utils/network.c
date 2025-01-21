#include "network.h"

#ifdef _PICO_CYW43_ARCH_H
    #define LED_GPIO_PUT cyw43_arch_gpio_put 
#else
    #define LED_GPIO_PUT gpio_put
#endif

static struct netif ap_netif;
void udp_reciver(
                void *arg, 
                struct udp_pcb *pcb, 
                struct pbuf *p, 
                const ip_addr_t *addr, 
                u16_t port) {
    if(p){
        printf("Received UDP packet from %s:%d: %.*s\n", ipaddr_ntoa(addr), port, p->tot_len, (char *)p->payload);

        struct pbuf *response = pbuf_alloc(PBUF_TRANSPORT, p->tot_len, PBUF_RAM);
        if (response) {
            memcpy(response->payload, "Acknowledged\n", 13);
            udp_sendto(pcb, response, addr, port);
            pbuf_free(response);
        }

        pbuf_free(p);
    }
}

uint8_t start_ap(void) {
    const uint8_t LED_PIN = CYW43_WL_GPIO_LED_PIN;

    printf("Initializing PICOW as AP...\n");
    if (cyw43_arch_init()) {
        printf("Failed to init wifi\n");
        return 1;
    }

    cyw43_arch_enable_ap_mode(AP_SSID, AP_PASSWORD, CYW43_AUTH_WPA2_AES_PSK);
    printf("AP SSID: %s\n", AP_SSID);
    
    ip4_addr_t ipaddr, netmask, gateway;
    IP4_ADDR(&ipaddr, 192, 168, 4, 1);
    IP4_ADDR(&netmask, 255, 255, 255, 0);
    IP4_ADDR(&gateway, 192, 168, 4, 1);

    netif_add(&ap_netif, &ipaddr, &netmask, &gateway, NULL, NULL, NULL);
    netif_set_up(&ap_netif);

    printf("AP mode running at %s\n", AP_IP);
    
    struct udp_pcb *server = udp_new();
    if (!server) {
        printf("Failed to create UDP server\n");
        return 1;
    }

    udp_bind(server, IP_ADDR_ANY, UDP_PORT);
    udp_recv(server, udp_reciver, NULL);

    printf("UDP server listening on port %d\n", UDP_PORT);
    while (1) {
        // cyw43_arch_poll(); // Poll for WiFi events
        LED_GPIO_PUT(LED_PIN, 1);
        sleep_ms(250);
        LED_GPIO_PUT(LED_PIN, 0);
        sleep_ms(1000);
    }

    return 0;
}