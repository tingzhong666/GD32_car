/*!
    \file    main.c
    \brief   led spark with systick

    \version 2023-06-25, V3.1.0, firmware for GD32F4xx
*/

/*
    Copyright (c) 2023, GigaDevice Semiconductor Inc.

    Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice, this
       list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice,
       this list of conditions and the following disclaimer in the documentation
       and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its contributors
       may be used to endorse or promote products derived from this software without
       specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
OF SUCH DAMAGE.
*/

#include "gd32f4xx.h"
#include "systick.h"
#include <stdio.h>
#include "main.h"
#include "led.h"
#include "test.h"
#include "pwm.h"
#include "car.h"
#include "uart.h"
#include "bluetooth.h"
#include "auto_track.h"

int main(void)
{
    // ===== BSP
    systick_config();

    nvic_priority_group_set(NVIC_PRIGROUP_PRE2_SUB2);

    led_init();

    // test_init();
    // test_on();

    bsp_pwm_init();
    // 80%以上才能动 折算为4V 实际3.7V 0.3的误差
    // bsp_pwm_dutyRatio_edit(pwm1, 80);
    // bsp_pwm_dutyRatio_edit(pwm2, 80);
    // bsp_pwm_dutyRatio_edit(pwm3, 80);
    // bsp_pwm_dutyRatio_edit(pwm4, 80);

    bsp_uart_init();
    bsp_uart_print_set(usart0);
    printf("gd32 running...\n");

    bsp_uart_print_set(usart2);
    printf("mcu debug bluetooth test\n");

    // ==== APP
    // car_forward(80);
    // car_backward(80);
    // car_left(80);
    // car_right(80);
    bluetooth_init();
    while (1)
    {
        // led_switch(led1);
        // delay_1ms(1000);
        led_switch(led2);
        delay_1ms(100);
        // led_switch(led3);
        // delay_1ms(1000);
        // led_switch(led4);
        // delay_1ms(1000);
        if (testFlag_get() == SET)
        {
            led_switch(led1);
            delay_1ms(100);
        }
        task_auto_track();
    }
}
