# Waveshare 24155 1.28 inch LCD display demo code port to STM32F072 microcontroller

version 1.0.1

## Introduction

This project ia a port on STM32F072 microcontroller of the Waveshare 1.28 inch LCD display demo code. The original code is written for the STM32F103 microcontroller.  
The original code is available at <https://www.waveshare.com/wiki/1.28inch_LCD_Module>  
This port is based on the original code and the STM32CubeF0 HAL library and is using the STM32CubeIDE.

## Hardware

The Waveshare 1.28 inch LCD display is a 240x240 pixel display with a ST7789V driver. The display is connected to the STM32F072 microcontroller using the SPI interface. The display is powered by 3.3V and the SPI interface is also 3.3V. The display is connected to the following pins of the STM32F072 microcontroller:

### LCD

![Waveshare 1.28 inch LCD display](/doc/img/1.28inch-Touch-LCD-details-5.jpg)

| Pin | Description |
| --- | --- |
| VCC | Power (3.3V / 5V input) |
| GND | Ground |
| MISO | SPI MISO pin |
| MOSI | SPI MOSI pin |
| SCLK | SPI Clock pin |
| LCS_CS | LCD Chip Selection, low active |
| LCS_DC | LCD Data/Command selection (high for data, low for command) |
| LCS_RST | LCD Reset, low active |
| LCS_BL | LCD Backlight |
| TP_SDA | TP Data pin |
| TP_SCL | TP Clock pin |
| TP_INT | TP Interrupt pin |
| TP_RST | TP Reset, low active |

### Nucleo-F072RB

![Nucleo-F072RB](/doc/img/nucleo-64.png)

[NUCLEO-F072RB](https://www.st.com/en/evaluation-tools/nucleo-f072rb.html)
is a development board with an STM32F072 microcontroller. The board has an integrated ST-LINK/V2-1 debugger/programmer. The board is powered by USB and has an Arduino Uno compatible pinout.  

![Nucleo-F072RB](/doc/img/nucleo-f072rb.png)

### How to connect the display to the Nucleo-F072RB

| 1.28inch Touch LCD | STM32 |
| --- | --- |
| VCC | 3.3V |
| GND | GND |
| MISO | PA6 |
| MOSI | PA7 |
| SCLK | PA5 |
| LCS_CS | PB6 |
| LCS_DC | PA8 |
| LCS_RST | PA9 |
| LCS_BL | PC7 |
| TP_SDA | PB9 |
| TP_SCL | PB8 |
| TP_INT | PB10 |
| TP_RST | PA10 |

![foto1](/doc/img/20240307_155414.jpg)
![foto2](/doc/img/20240307_155422.jpg)
![foto3](/doc/img/20240307_155431.jpg)
![foto4](/doc/img/20240307_155504.jpg)

## Software

### printf

The project uses the `printf` function to print messages to the serial port. The `printf` function is using the `USART2` peripheral. The `USART2` peripheral is connected to the `ST-LINK/V2-1` debugger/programmer and is used to communicate with the host computer. The `USART2` peripheral is configured to 115200 baud, 8 data bits, no parity, 1 stop bit.  

To use the `printf` function, the `stdio` library must be included in the project. The `stdio` library is included in the `retarget` library. The `retarget` library is included in the project and is used to redirect the `printf` function to the `USART2` peripheral.

Set following options in the `STM32CubeIDE` project settings:

![printf](/doc/img/printf.png)

![USART2](/doc/img/uart.png)

## Final result

The demo is rather slow on default settings.  

Uart output:

``` txt
---- Opened the serial port COM12 ----
LCD_1IN28_test Demo
LCD_1IN28_ Init and Clear...
Success:Detected CST816T.
CST816T Revision = 1
OK!
Paint_NewImage
Set Clear and Display Funtion
Paint_Clear
```
