#ifndef TRACE_CONFIG_H
#define TRACE_CONFIG_H

#include "stm32f7xx_hal.h"                      // "mcu/mcu.h" not working here!

extern "C" UART_HandleTypeDef huart1;           // Defined in main.c

#define USE_PLATFORM_F7_DISCO_GCC_TRACE         1

#define TRACE_UART_NUMBER                       0
#define TRACE_UART_HANDLE                       huart1
#define TRACE_UART_BAUD_RATE                    /* 115200, but given by STM32CubeMX tool configuration */
#define TRACE_UART_USE_TX_DMA                   false
#define TRACE_UART_CONSTRUCTOR_PARAMETERS       TRACE_UART_NUMBER, &TRACE_UART_HANDLE, TRACE_UART_USE_TX_DMA

#define TRACE_ADD_CRLF_SEQU                     0

#endif // TRACE_CONFIG_H
