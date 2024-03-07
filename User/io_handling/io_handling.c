/**
 * @file io_handling.c
 * @author Paweł Kawula (pawel.kawula@kelectronics.pl)
 * @brief
 *
 * Copyright 2024 - KElectronics
 */

#include "io_handling.h"
#include <stdint.h>
#include <stdio.h>

#define BUFFER_SIZE 128
static char buffer[BUFFER_SIZE];

static int null_handler(const uint8_t *buf, uint16_t len);

static volatile io_handler handler_ = null_handler;

static int null_handler(const uint8_t *buf, uint16_t len)
{
    (void)buf;
    (void)len;
    return 0;
}

/* First version of printf handler, writing string by string */
PUTCHAR_PROTOTYPE
{
    static uint16_t index = 0;

    // Write data to buffer until EOS is received
    if (ch != '\n' && index < BUFFER_SIZE - 1)
    {
        buffer[index++] = (char)ch;
    }
    else
    {
        // EOS received or buffer full, transmit data
        if (ch == '\n' && index < BUFFER_SIZE - 1)
        {
            buffer[index++] = (char)ch;
        }

        handler_((uint8_t *)buffer, index);

        // Reset index for next string
        index = 0;
    }

    return ch;
}

/* Second version of printf handler, writing sign by sign */
/* PUTCHAR_PROTOTYPE
{
  handler_((uint8_t *)&ch, 1);
  return ch;
} */

void io_handling_register_handler(io_handler handler)
{
    if (handler == NULL)
    {
        return;
    }

    handler_ = handler;
}

void io_handling_unregister_handler(void)
{
    handler_ = null_handler;
}
