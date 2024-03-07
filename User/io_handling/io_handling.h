/**
 * @file io_handling.h
 * @author Paweł Kawula (pawel.kawula@kelectronics.pl)
 * @brief Implementation of IO handling
 * 
 * Copyright 2024 - KElectronics
 * 
 * HISTORY:
 * Date      	By	Comments
 * ----------	---	---------------------------------------------------------
*/

#ifndef IO_HANDLING_H
#define IO_HANDLING_H

#include <stdint.h>
#include <stdio.h>


#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif

typedef int (*io_handler)(const uint8_t *buf, uint16_t len);

void io_handling_register_handler(io_handler handler);

void io_handling_unregister_handler(void);

#endif // IO_HANDLING_H
