/**
 * pwm.h
 * @tingzhong666
 * 2024-03-16 16:33:30
 */

#ifndef PWM_H
#define PWM_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "gd32f4xx_timer.h"
#include "gd32f4xx_rcu.h"
#include "gd32f4xx_gpio.h"

#define PWM1
#define PWM1_RCU RCU_TIMER2
#define PWM1_TIMER TIMER2

#define PWM1_CHANNEL0_RCU RCU_GPIOA
#define PWM1_CHANNEL0_GPIO GPIOA
#define PWM1_CHANNEL0_PIN GPIO_PIN_6

#define PWM1_CHANNEL1_RCU RCU_GPIOA
#define PWM1_CHANNEL1_GPIO GPIOA
#define PWM1_CHANNEL1_PIN GPIO_PIN_7

#define PWM1_CHANNEL2_RCU RCU_GPIOB
#define PWM1_CHANNEL2_GPIO GPIOB
#define PWM1_CHANNEL2_PIN GPIO_PIN_0

#define PWM1_CHANNEL3_RCU RCU_GPIOB
#define PWM1_CHANNEL3_GPIO GPIOB
#define PWM1_CHANNEL3_PIN GPIO_PIN_1

    typedef enum
    {
        pwm1,
        pwm2,
        pwm3,
        pwm4
    } Pwm;

    void bsp_pwm_init(void);
    void bsp_pwm_dutyRatio_edit(Pwm, int dutyRatio);

#ifdef __cplusplus
}
#endif

#endif
