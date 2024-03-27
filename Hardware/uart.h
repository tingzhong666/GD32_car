/**
 * uart.h
 * @tingzhong666
 * 2024-03-19 22:41:36
 */

#ifndef UART_H
#define UART_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "gd32f4xx.h"
#include <stdio.h>
#include "string.h"
    typedef enum Bsp_uart_print
    {
        usart0 = USART0,
        usart2 = USART2,
    } Bsp_uart_print;

    void bsp_uart_init(void);
    void bsp_uart_print_set(enum Bsp_uart_print value);
    void bsp_usart2_ISR_set(void (*cb)(char *msg));

#ifdef __cplusplus
}
#endif

#endif
