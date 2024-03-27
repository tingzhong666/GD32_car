/**
 * LED.h
 * @tingzhong666
 * 2024-03-12 22:36:41
 */

#ifndef LED_H
#define LED_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "gd32f4xx_rcu.h"
#include "gd32f4xx_gpio.h"

    typedef enum Led
    {
        led1,
        led2,
        led3,
        led4
    } Led;
    typedef enum Status
    {
        on,
        off
    } Status;

#define LED1
#define LED1_GPIO GPIOE
#define LED1_PIN GPIO_PIN_3
#define LED1_RCU RCU_GPIOE
#define LED1_GPIO_MODE GPIO_MODE_OUTPUT
#define LED1_GPIO_PULL_UP_DOWN GPIO_PUPD_NONE
#define LED1_GPIO_OTYPE GPIO_OTYPE_PP
#define LED1_GPIO_SPEED GPIO_OSPEED_2MHZ

#define LED2
#define LED2_GPIO GPIOD
#define LED2_PIN GPIO_PIN_7
#define LED2_RCU RCU_GPIOD
#define LED2_GPIO_MODE GPIO_MODE_OUTPUT
#define LED2_GPIO_PULL_UP_DOWN GPIO_PUPD_NONE
#define LED2_GPIO_SPEED GPIO_OSPEED_2MHZ
#define LED2_GPIO_OTYPE GPIO_OTYPE_PP

#define LED3
#define LED3_GPIO GPIOG
#define LED3_PIN GPIO_PIN_3
#define LED3_RCU RCU_GPIOG
#define LED3_GPIO_MODE GPIO_MODE_OUTPUT
#define LED3_GPIO_PULL_UP_DOWN GPIO_PUPD_NONE
#define LED3_GPIO_SPEED GPIO_OSPEED_2MHZ
#define LED3_GPIO_OTYPE GPIO_OTYPE_PP

#define LED4
#define LED4_GPIO GPIOA
#define LED4_PIN GPIO_PIN_5
#define LED4_RCU RCU_GPIOA
#define LED4_GPIO_MODE GPIO_MODE_OUTPUT
#define LED4_GPIO_PULL_UP_DOWN GPIO_PUPD_NONE
#define LED4_GPIO_SPEED GPIO_OSPEED_2MHZ
#define LED4_GPIO_OTYPE GPIO_OTYPE_PP

    void led_init(void);
    void led_on(Led);
    void led_off(Led);
    void led_switch(Led);
    Status led_status(Led);

#ifdef __cplusplus
}
#endif

#endif
