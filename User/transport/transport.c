/**
 * @file transport.c
 * @author Paweł Kawula (pawel.kawula@kelectronics.pl)
 * @brief 
 * 
 * Copyright 2024 - KElectronics
*/

#include "transport.h"
#include "stm32f0xx.h"
#include "usart.h"

#include <stdbool.h>



int transport_uart(const uint8_t *buf, uint16_t len)
{
    return (int)HAL_UART_Transmit(&huart2, (uint8_t *)buf, len, UART_DELAY);
}


int transport_uart_dma(const uint8_t *buf, uint16_t len)
{
    return (int)HAL_UART_Transmit_DMA(&huart2, (uint8_t *)buf, len);
}

int transport_null(const uint8_t *buf, uint16_t len)
{
    (void)buf;
    (void)len;
    return 0;
}