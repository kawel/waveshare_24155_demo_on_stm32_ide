/**
 * @file transport.h
 * @author Paweł Kawula (pawel.kawula@kelectronics.pl)
 * @brief
 *
 * Copyright 2024 - KElectronics
 *
 * HISTORY:
 * Date      	By	Comments
 * ----------	---	---------------------------------------------------------
 */

#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <stdint.h>

#define UART_DELAY 1000


typedef int (*transport_t)(const uint8_t *buf, uint16_t len);

int transport_uart(const uint8_t *buf, uint16_t len);
int transport_uart_dma(const uint8_t *buf, uint16_t len);

#endif // TRANSPORT_H
