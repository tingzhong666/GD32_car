/**
 * led.c
 * @tingzhong666
 * 2024-03-12 22:19:48
 */
#include <led.h>

void led_init()
{
    // 时钟
    rcu_periph_clock_enable(LED1_RCU);
    rcu_periph_clock_enable(LED2_RCU);
    rcu_periph_clock_enable(LED3_RCU);
    rcu_periph_clock_enable(LED4_RCU);

    // IO外设
    gpio_mode_set(LED1_GPIO, LED1_GPIO_MODE, LED1_GPIO_PULL_UP_DOWN, LED1_PIN);
    gpio_mode_set(LED2_GPIO, LED2_GPIO_MODE, LED2_GPIO_PULL_UP_DOWN, LED2_PIN);
    gpio_mode_set(LED3_GPIO, LED3_GPIO_MODE, LED3_GPIO_PULL_UP_DOWN, LED3_PIN);
    gpio_mode_set(LED4_GPIO, LED4_GPIO_MODE, LED4_GPIO_PULL_UP_DOWN, LED4_PIN);

    gpio_output_options_set(LED1_GPIO, LED1_GPIO_OTYPE, LED1_GPIO_SPEED, LED1_PIN);
    gpio_output_options_set(LED2_GPIO, LED2_GPIO_OTYPE, LED2_GPIO_SPEED, LED2_PIN);
    gpio_output_options_set(LED3_GPIO, LED3_GPIO_OTYPE, LED3_GPIO_SPEED, LED3_PIN);
    gpio_output_options_set(LED4_GPIO, LED4_GPIO_OTYPE, LED4_GPIO_SPEED, LED4_PIN);
}

// 开
void led_on(Led led)
{
    switch (led)
    {
    case led1:
        gpio_bit_write(LED1_GPIO, LED1_PIN, SET);
        break;
    case led2:
        gpio_bit_write(LED2_GPIO, LED2_PIN, SET);
        break;
    case led3:
        gpio_bit_write(LED3_GPIO, LED3_PIN, SET);
        break;
    case led4:
        gpio_bit_write(LED4_GPIO, LED4_PIN, SET);
        break;

    default:
        break;
    }
}

// 关
void led_off(Led led)
{
    switch (led)
    {
    case led1:
        gpio_bit_write(LED1_GPIO, LED1_PIN, RESET);
        break;
    case led2:
        gpio_bit_write(LED2_GPIO, LED2_PIN, RESET);
        break;
    case led3:
        gpio_bit_write(LED3_GPIO, LED3_PIN, RESET);
        break;
    case led4:
        gpio_bit_write(LED4_GPIO, LED4_PIN, RESET);
        break;

    default:
        break;
    }
}

// 切换
void led_switch(Led led)
{
    switch (led)
    {
    case led1:
        led_status(led1) == on ? led_off(led1) : led_on(led1);
        break;
    case led2:
        led_status(led2) == on ? led_off(led2) : led_on(led2);
        break;
    case led3:
        led_status(led3) == on ? led_off(led3) : led_on(led3);
        break;
    case led4:
        led_status(led4) == on ? led_off(led4) : led_on(led4);
        break;

    default:
        break;
    }
}

Status led_status(Led led)
{
    FlagStatus status;
    switch (led)
    {
    case led1:
        status = gpio_output_bit_get(LED1_GPIO, LED1_PIN);
        break;
    case led2:
        status = gpio_output_bit_get(LED2_GPIO, LED2_PIN);
        break;
    case led3:
        status = gpio_output_bit_get(LED3_GPIO, LED3_PIN);
        break;
    case led4:
        status = gpio_output_bit_get(LED4_GPIO, LED4_PIN);
        break;

    default:
        break;
    }

    return status == SET ? on : off;
}
