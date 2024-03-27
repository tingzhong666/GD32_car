/**
 * car.h
 * @tingzhong666
 * 2024-03-19 21:33:20
 */

#ifndef CAR_H
#define CAR_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "pwm.h"

    void car_stop(void);
    void car_forward(uint8_t speed);
    void car_forward_2(uint8_t speedl, uint8_t speedr);
    void car_backward(uint8_t speed);
    void car_left(uint8_t speed);
    void car_right(uint8_t speed);
    void car_brake(void);

#ifdef __cplusplus
}
#endif

#endif
