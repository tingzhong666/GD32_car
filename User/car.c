/**
 * car.c
 * @tingzhong666
 * 2024-03-19 21:30:41
 */
#include "car.h"

// 停止
void car_stop()
{
    bsp_pwm_dutyRatio_edit(pwm1, 0);
    bsp_pwm_dutyRatio_edit(pwm2, 0);
    bsp_pwm_dutyRatio_edit(pwm3, 0);
    bsp_pwm_dutyRatio_edit(pwm4, 0);
}
// 前进 4驱 理论60-100 实际80-100
void car_forward(uint8_t speed)
{
    car_stop();
    bsp_pwm_dutyRatio_edit(pwm1, speed);
    bsp_pwm_dutyRatio_edit(pwm3, speed);
}
void car_forward_2(uint8_t speedl, uint8_t speedr)
{
    car_stop();
    bsp_pwm_dutyRatio_edit(pwm1, speedl);
    bsp_pwm_dutyRatio_edit(pwm3, speedr);
}
// 后退 4驱
void car_backward(uint8_t speed)
{
    car_stop();
    bsp_pwm_dutyRatio_edit(pwm2, speed);
    bsp_pwm_dutyRatio_edit(pwm4, speed);
}
// 左转
void car_left(uint8_t speed)
{
    car_stop();
    bsp_pwm_dutyRatio_edit(pwm1, speed);
    bsp_pwm_dutyRatio_edit(pwm4, speed);
}
// 右转
void car_right(uint8_t speed)
{
    car_stop();
    bsp_pwm_dutyRatio_edit(pwm2, speed);
    bsp_pwm_dutyRatio_edit(pwm3, speed);
}
// 刹车
void car_brake()
{
    car_stop();
    bsp_pwm_dutyRatio_edit(pwm1, 100);
    bsp_pwm_dutyRatio_edit(pwm2, 100);
    bsp_pwm_dutyRatio_edit(pwm3, 100);
    bsp_pwm_dutyRatio_edit(pwm4, 100);
}
