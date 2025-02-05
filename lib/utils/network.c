#include "network.h"

data_packet_t data = {    
    .visibility = 0.0f,
    .days = {
        {"Day", "cloudy", 0, 0}, 
        {"Day", "cloudy", 0, 0},
        {"Day", "cloudy", 0, 0},
        {"Day", "cloudy", 0, 0},
        {"Day", "cloudy", 0, 0}},
    .sunrise = "07:15",
    .sunset = "08:20",
    .location = "London, UK",
    .curr_desc = "clouds",
    .curr_time = "69:69",
    .curr_date = "Sunday,_September_27th",
    .temp = 0,
    .feel_temp = 0,
    .humidity = 0,
    .wind = 0,
    .pressure = 0,
    .aqi = 0,
    .uv = 0,
    .hours = {10, 20, 30, 40},
    .updated = false,
    .day = true,};
    
static struct netif ap_netif;
void udp_reciver(
                void *arg, 
                struct udp_pcb *pcb, 
                struct pbuf *p, 
                const ip_addr_t *addr, 
                u16_t port) {
    if(p){
        char *received = (char *) p->payload;
        uint8_t b1 = received[p->tot_len - 2];
        uint8_t b2 = received[p->tot_len - 1];

        uint16_t id = (((uint16_t) b1) << 8) | (((uint16_t) b2) & 0x00ff);

        uint16_t weather_id = (((uint16_t) *received) << 8) | (((uint16_t) *(received + 1)) & 0x0ff);

        // printf("received udp packet from %s:%d: %.*s\n", ipaddr_ntoa(addr), port, p->tot_len - 2, (received + 2));
        // printf("packet id: %d\n", id);

        if(!weather_id) {
            sscanf(received + 2, "%d %d %29s %d %d %f %d %29s %7s %7s %d %d %29s %29s %d\n", &data.temp, &data.feel_temp, data.curr_desc, &data.humidity, &data.aqi, &data.visibility, &data.pressure, data.location, data.sunrise, data.sunset, &data.uv, &data.wind, data.curr_date, data.curr_time, &data.day);
            printf("INFO: %d %s %d %d %f %d %s %s %s %d %d %d\n", data.temp, data.curr_desc, data.humidity, data.aqi, data.visibility, data.pressure, data.location, data.sunrise, data.sunset, data.uv, data.wind, data.day);
        } else if(weather_id < 6 && weather_id > 0) {
            day_info_t day_info;
            sscanf(received + 2, "%9s %29s %d %d", day_info.day, day_info.desc, &day_info.high, &day_info.low);
            data.days[weather_id - 1] = day_info;
            // printf("INFO: %3s %s %d %d\n", day_info.day, day_info.desc, day_info.high, day_info.low);
        } else if(weather_id == 7) {
            int *hours = data.hours;
            sscanf(received + 2, "%d %d %d %d", hours, hours + 1, hours + 2, hours + 3);
            // printf("INFO: %d %d %d %d\n", *hours, hours[1], hours[2], hours[3]);
        }

        if (!weather_id) {
            sscanf(received + 2, "%d %29s %d %d %f %d %29s", &data.temp, data.curr_desc, &data.humidity, &data.aqi, &data.visibility, &data.pressure, data.location);
            // printf("INFO: %d %s %d %d %f %d %s\n", data.temp, data.curr_desc, data.humidity, data.aqi, data.visibility, data.pressure, data.location);
        }

        data.updated = true;
        struct pbuf *response = pbuf_alloc(PBUF_TRANSPORT, p->tot_len, PBUF_RAM);
        if (response) {
            unsigned char send_bytes[2] = {b1, b2};
            memcpy(response->payload, send_bytes, 2);
            udp_sendto(pcb, response, addr, port);
            pbuf_free(response);
        }

        pbuf_free(p);
    }
}

uint8_t start_ap(void) {

    printf("Initializing PICO-W as AP...\n");
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

    return 0;
}