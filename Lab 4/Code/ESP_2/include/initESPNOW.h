#ifndef INIT_ESP_NOW_H
#define INIT_ESP_NOW_H

void handleReceive(uint8_t *macAddress, uint8_t *data, uint8_t len);
void initESPNOW();

#endif // INIT_ESP_NOW_H
