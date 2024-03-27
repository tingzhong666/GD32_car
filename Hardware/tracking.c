/**
 * tracking.c
 * @tingzhong666
 * 2024-03-24 13:20:11
 */
#include <tracking.h>

// RESET 为有黑线
FlagStatus bsp_tracking_1_flag = SET;
FlagStatus bsp_tracking_2_flag = SET;
FlagStatus bsp_tracking_3_flag = SET;
FlagStatus bsp_tracking_4_flag = SET;
FlagStatus bsp_tracking_5_flag = SET;

void bsp_tracking_init()
{
    // rcu
    rcu_periph_clock_enable(BSP_TRACKING1_IO_RCU);
    rcu_periph_clock_enable(BSP_TRACKING2_IO_RCU);
    rcu_periph_clock_enable(BSP_TRACKING3_IO_RCU);
    rcu_periph_clock_enable(BSP_TRACKING4_IO_RCU);
    rcu_periph_clock_enable(BSP_TRACKING5_IO_RCU);
    // IO输入 这里上下拉注意
    gpio_mode_set(BSP_TRACKING1_IO, GPIO_MODE_INPUT, GPIO_PUPD_NONE, BSP_TRACKING1_PIN);
    gpio_mode_set(BSP_TRACKING2_IO, GPIO_MODE_INPUT, GPIO_PUPD_NONE, BSP_TRACKING2_PIN);
    gpio_mode_set(BSP_TRACKING3_IO, GPIO_MODE_INPUT, GPIO_PUPD_NONE, BSP_TRACKING3_PIN);
    gpio_mode_set(BSP_TRACKING4_IO, GPIO_MODE_INPUT, GPIO_PUPD_NONE, BSP_TRACKING4_PIN);
    gpio_mode_set(BSP_TRACKING5_IO, GPIO_MODE_INPUT, GPIO_PUPD_NONE, BSP_TRACKING5_PIN);
    // IO外部中断
    exti_init(BSP_TRACKING1_EXTI_LINE, EXTI_INTERRUPT, EXTI_TRIG_FALLING);
    exti_init(BSP_TRACKING2_EXTI_LINE, EXTI_INTERRUPT, EXTI_TRIG_FALLING);
    exti_init(BSP_TRACKING3_EXTI_LINE, EXTI_INTERRUPT, EXTI_TRIG_FALLING);
    exti_init(BSP_TRACKING4_EXTI_LINE, EXTI_INTERRUPT, EXTI_TRIG_FALLING);
    exti_init(BSP_TRACKING5_EXTI_LINE, EXTI_INTERRUPT, EXTI_TRIG_FALLING);

    exti_interrupt_enable(BSP_TRACKING1_EXTI_LINE);
    exti_interrupt_enable(BSP_TRACKING2_EXTI_LINE);
    exti_interrupt_enable(BSP_TRACKING3_EXTI_LINE);
    exti_interrupt_enable(BSP_TRACKING4_EXTI_LINE);
    exti_interrupt_enable(BSP_TRACKING5_EXTI_LINE);
}

void EXTI5_9_IRQHandler()
{
    // 1 和 2 中断线一样的
    if (exti_interrupt_flag_get(BSP_TRACKING1_EXTI_LINE) == SET)
    {
        bsp_tracking_1_flag = gpio_input_bit_get(BSP_TRACKING1_IO, BSP_TRACKING1_PIN);
        bsp_tracking_2_flag = gpio_input_bit_get(BSP_TRACKING2_IO, BSP_TRACKING2_PIN);
        exti_interrupt_flag_clear(BSP_TRACKING1_EXTI_LINE);
    }
    if (exti_interrupt_flag_get(BSP_TRACKING3_EXTI_LINE) == SET)
    {
        bsp_tracking_3_flag = gpio_input_bit_get(BSP_TRACKING3_IO, BSP_TRACKING3_PIN);
        exti_interrupt_flag_clear(BSP_TRACKING3_EXTI_LINE);
    }
}

void EXTI10_15_IRQHandler()
{
    if (exti_interrupt_flag_get(BSP_TRACKING4_EXTI_LINE) == SET)
    {
        bsp_tracking_4_flag = gpio_input_bit_get(BSP_TRACKING4_IO, BSP_TRACKING4_PIN);
        exti_interrupt_flag_clear(BSP_TRACKING4_EXTI_LINE);
    }
    if (exti_interrupt_flag_get(BSP_TRACKING5_EXTI_LINE) == SET)
    {
        bsp_tracking_5_flag = gpio_input_bit_get(BSP_TRACKING5_IO, BSP_TRACKING5_PIN);
        exti_interrupt_flag_clear(BSP_TRACKING5_EXTI_LINE);
    }
}

FlagStatus bsp_tracking_flag(Bsp_tracking_num bsp_tracking_num)
{
    switch (bsp_tracking_num)
    {
    case tracking1:
        return bsp_tracking_1_flag;
    case tracking2:
        return bsp_tracking_2_flag;
    case tracking3:
        return bsp_tracking_3_flag;
    case tracking4:
        return bsp_tracking_4_flag;
    case tracking5:
        return bsp_tracking_5_flag;
    }
}
