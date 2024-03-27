/**
 * tracking.h
 * @tingzhong666
 * 2024-03-24 13:20:30
 */

#ifndef TRACKING_H
#define TRACKING_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "gd32f4xx_libopt.h"

#define BSP_TRACKING1_IO GPIOC
#define BSP_TRACKING1_IO_RCU RCU_GPIOC
#define BSP_TRACKING1_PIN GPIO_PIN_7
#define BSP_TRACKING1_EXTI_LINE EXTI_7

#define BSP_TRACKING2_IO GPIOG
#define BSP_TRACKING2_IO_RCU RCU_GPIOG
#define BSP_TRACKING2_PIN GPIO_PIN_7
#define BSP_TRACKING2_EXTI_LINE EXTI_7

#define BSP_TRACKING3_IO GPIOB
#define BSP_TRACKING3_IO_RCU RCU_GPIOB
#define BSP_TRACKING3_PIN GPIO_PIN_15
#define BSP_TRACKING3_EXTI_LINE EXTI_8

#define BSP_TRACKING4_IO GPIOB
#define BSP_TRACKING4_IO_RCU RCU_GPIOB
#define BSP_TRACKING4_PIN GPIO_PIN_13
#define BSP_TRACKING4_EXTI_LINE EXTI_13

#define BSP_TRACKING5_IO GPIOB
#define BSP_TRACKING5_IO_RCU RCU_GPIOB
#define BSP_TRACKING5_PIN GPIO_PIN_11
#define BSP_TRACKING5_EXTI_LINE EXTI_11

    typedef enum
    {
        tracking1,
        tracking2,
        tracking3,
        tracking4,
        tracking5,
    } Bsp_tracking_num;

    void bsp_tracking_init(void);
    FlagStatus bsp_tracking_flag(Bsp_tracking_num bsp_tracking_num);

#ifdef __cplusplus
}
#endif

#endif
