/**
 * ultrasonic.c
 * @tingzhong666
 * 2024-03-27 21:44:50
 */
#include <ultrasonic.h>

void bsp_ultrasonic_init()
{
    timer_parameter_struct timer_initpara;
    // == io
    // send
    rcu_periph_clock_enable(BSP_ULTRASONIC_SEND_IO_RCU);
    gpio_mode_set(BSP_ULTRASONIC_SEND_IO, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, BSP_ULTRASONIC_SEND_IO_PIN);
    gpio_output_options_set(BSP_ULTRASONIC_SEND_IO, GPIO_OTYPE_PP, GPIO_OSPEED_MAX, BSP_ULTRASONIC_SEND_IO_PIN);

    // rec
    rcu_periph_clock_enable(BSP_ULTRASONIC_REC_IO_RCU);
    gpio_mode_set(BSP_ULTRASONIC_REC_IO, GPIO_MODE_INPUT, GPIO_PUPD_PULLDOWN, GPIO_PIN_5);

    // == 定时器 70ms 测距一次 timer5rcu =APB1 = AHB/4 = SYSCLK/4 = 240m/4 =60mhz timer频率=60mhz/60000=1000
    rcu_periph_clock_enable(BSP_ULTRASONIC_TIMER_RCU);
    timer_struct_para_init(&timer_initpara);
    timer_initpara.prescaler = 60000;
    timer_initpara.period = 70;
    timer_init(BSP_ULTRASONIC_TIMER, &timer_initpara);
    timer_enable(BSP_ULTRASONIC_TIMER);

    timer_interrupt_enable(BSP_ULTRASONIC_TIMER, TIMER_INT_FLAG_UP);
    nvic_irq_enable(BSP_ULTRASONIC_TIMER_IRQN_TYPE, 1, 0);
}
// 接收标志
FlagStatus bsp_ultrasonic_recFlag_get()
{
    return gpio_input_bit_get(BSP_ULTRASONIC_REC_IO, BSP_ULTRASONIC_REC_IO_PIN);
}

// 发送声波 需要10us+
void bsp_ultrasonic_send()
{
    gpio_bit_set(BSP_ULTRASONIC_SEND_IO, BSP_ULTRASONIC_SEND_IO_PIN);
    bsp_uart_print_set(usart0);
    delay_1us(15);
    bsp_uart_print_set(usart0);
    gpio_bit_reset(BSP_ULTRASONIC_SEND_IO, BSP_ULTRASONIC_SEND_IO_PIN);
}

// 一次声波测距的完成标志
FlagStatus bsp_ultrasonic_rec_flag = RESET;
FlagStatus bsp_ultrasonic_rec_flag_get()
{
    return bsp_ultrasonic_rec_flag;
}
void bsp_ultrasonic_rec_flag_set(FlagStatus v)
{
    bsp_ultrasonic_rec_flag = v;
}
// 距离 cm
double distance = 0;
double bsp_ultrasonic_distance_get()
{
    return distance;
}

// 接收声波 测距 240mhz/12*1=50ns 检测精度为 1us 1us/50ns = 20个机器周期
void bsp_ultrasonic_rec_task()
{
    uint32_t time_us = 0;

    // 上一次的测距 还未处理
    if (bsp_ultrasonic_rec_flag == SET)
        return;

    if (bsp_ultrasonic_recFlag_get() == RESET)
        return;
    while (bsp_ultrasonic_recFlag_get() == SET)
    {
        time_us ++;
        delay_1us(1);
    }
    distance = TASK_SOUND_SPEED * time_us / 2 * 100 * 0.000001;
    bsp_ultrasonic_rec_flag = SET;
}

// 70ms 间隔发起一次测距
void TIMER5_DAC_IRQHandler()
{
    if (timer_interrupt_flag_get(BSP_ULTRASONIC_TIMER, TIMER_INT_FLAG_UP) == SET)
    {
        bsp_ultrasonic_send();
        timer_interrupt_flag_clear(BSP_ULTRASONIC_TIMER, TIMER_INT_FLAG_UP);
    }
}
