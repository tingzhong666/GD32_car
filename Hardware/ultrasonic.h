/**
 * ultrasonic.h
 * @tingzhong666
 * 2024-03-27 21:45:04
 */

#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "gd32f4xx.h"
#include "uart.h"
#include "systick.h"

// send PD1
#define BSP_ULTRASONIC_SEND_IO_RCU RCU_GPIOD
#define BSP_ULTRASONIC_SEND_IO GPIOD
#define BSP_ULTRASONIC_SEND_IO_PIN GPIO_PIN_1

// rec PD5
#define BSP_ULTRASONIC_REC_IO_RCU RCU_GPIOD
#define BSP_ULTRASONIC_REC_IO GPIOD
#define BSP_ULTRASONIC_REC_IO_PIN GPIO_PIN_5

// 声音速度 m/s
#define TASK_SOUND_SPEED 340

// 定时器 70ms测距一次
#define BSP_ULTRASONIC_TIMER_RCU RCU_TIMER5
#define BSP_ULTRASONIC_TIMER TIMER5
#define BSP_ULTRASONIC_TIMER_IRQN_TYPE TIMER5_DAC_IRQn

    void bsp_ultrasonic_init(void);
    void bsp_ultrasonic_rec_task(void);

    FlagStatus bsp_ultrasonic_rec_flag_get(void);
    void bsp_ultrasonic_rec_flag_set(FlagStatus v);

    double bsp_ultrasonic_distance_get(void);
#ifdef __cplusplus
}
#endif

#endif
