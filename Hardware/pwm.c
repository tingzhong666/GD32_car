/**
 * pwm.c
 * @tingzhong666
 * 2024-03-16 16:33:07
 */
#include <pwm.h>

void bsp_timer_init(rcu_periph_enum rcu, uint32_t timer_periph)
{
    timer_parameter_struct timer_parameter;
    // 时钟
    rcu_periph_clock_enable(rcu);                         // 120m
    rcu_timer_clock_prescaler_config(RCU_TIMER_PSC_MUL2); // 120m*2=240m

    // 定时器
    timer_struct_para_init(&timer_parameter);
    timer_parameter.prescaler = 240 - 1; // 240m/240=1m
    timer_parameter.period = 100 - 1;    // 1m/100=10000hz=10khz

    timer_init(timer_periph, &timer_parameter);
    timer_enable(timer_periph);
    timer_auto_reload_shadow_enable(timer_periph);
}

void bsp_timer_output_init(uint32_t timer_periph, uint16_t channel)
{
    timer_oc_parameter_struct timer_oc_parameter;
    timer_channel_output_struct_para_init(&timer_oc_parameter);
    timer_oc_parameter.outputstate = TIMER_CCX_ENABLE;
    timer_oc_parameter.ocpolarity = TIMER_OC_POLARITY_HIGH;
    timer_channel_output_config(timer_periph, channel, &timer_oc_parameter);
    timer_channel_output_pulse_value_config(timer_periph, channel, 0);
    timer_channel_output_mode_config(timer_periph, channel, TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(timer_periph, channel, TIMER_OC_SHADOW_ENABLE);
}
void bsp_io_init(rcu_periph_enum periph, uint32_t gpio_periph, uint32_t pin)
{
    rcu_periph_clock_enable(periph);
    gpio_mode_set(gpio_periph, GPIO_MODE_AF, GPIO_PUPD_NONE, pin);
    gpio_output_options_set(gpio_periph, GPIO_OTYPE_PP, GPIO_OSPEED_MAX, pin);
    gpio_af_set(gpio_periph, GPIO_AF_2, pin);
}
void bsp_pwm_init()
{
    bsp_timer_init(PWM1_RCU, PWM1_TIMER);
    bsp_timer_output_init(PWM1_TIMER, TIMER_CH_0);
    bsp_timer_output_init(PWM1_TIMER, TIMER_CH_1);
    bsp_timer_output_init(PWM1_TIMER, TIMER_CH_2);
    bsp_timer_output_init(PWM1_TIMER, TIMER_CH_3);
    bsp_io_init(PWM1_CHANNEL0_RCU, PWM1_CHANNEL0_GPIO, PWM1_CHANNEL0_PIN);
    bsp_io_init(PWM1_CHANNEL1_RCU, PWM1_CHANNEL1_GPIO, PWM1_CHANNEL1_PIN);
    bsp_io_init(PWM1_CHANNEL2_RCU, PWM1_CHANNEL2_GPIO, PWM1_CHANNEL2_PIN);
    bsp_io_init(PWM1_CHANNEL3_RCU, PWM1_CHANNEL3_GPIO, PWM1_CHANNEL3_PIN);
}

void bsp_pwm_dutyRatio_edit(Pwm pwm, int dutyRatio)
{
    switch (pwm)
    {
    case pwm1:
        timer_channel_output_pulse_value_config(PWM1_TIMER, TIMER_CH_0, dutyRatio - 1 <= 0 ? 0 : dutyRatio - 1);
        break;
    case pwm2:
        timer_channel_output_pulse_value_config(PWM1_TIMER, TIMER_CH_1, dutyRatio - 1 <= 0 ? 0 : dutyRatio - 1);
        break;
    case pwm3:
        timer_channel_output_pulse_value_config(PWM1_TIMER, TIMER_CH_2, dutyRatio - 1 <= 0 ? 0 : dutyRatio - 1);
        break;
    case pwm4:
        timer_channel_output_pulse_value_config(PWM1_TIMER, TIMER_CH_3, dutyRatio - 1 <= 0 ? 0 : dutyRatio - 1);
        break;

    default:
        break;
    }
}
