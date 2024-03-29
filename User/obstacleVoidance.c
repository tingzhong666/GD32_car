/**
 * obstacleVoidance.c
 * @tingzhong666
 * 2024-03-27 21:56:46
 * 避障
 */
#include <obstacleVoidance.h>
#include "test.h"

void task_obstacleVoidance()
{
    if (bsp_ultrasonic_rec_flag_get() == SET)
    {
        bsp_uart_print_set(usart0);
        printf("%f\n", bsp_ultrasonic_distance_get());
        if (bsp_ultrasonic_distance_get() < 5)
        {
            // 转弯
            car_left(80);
            delay_1ms(1000);
            car_brake();
            car_stop();
        }

        bsp_ultrasonic_rec_flag_set(RESET);
    }
}
