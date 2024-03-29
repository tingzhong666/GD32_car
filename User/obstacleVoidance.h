/**
 * obstacleVoidance.h
 * @tingzhong666
 * 2024-03-27 21:57:01
 */

#ifndef OBSTACLEVOIDANCE_H
#define OBSTACLEVOIDANCE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "gd32f4xx.h"
#include <ultrasonic.h>
#include <systick.h>
#include "car.h"
#include "uart.h"

    void task_obstacleVoidance(void);

#ifdef __cplusplus
}
#endif

#endif
