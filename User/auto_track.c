/**
 * auto_track.c
 * @tingzhong666
 * 2024-03-27 16:22:42
 */
#include <auto_track.h>

// 是否启动自动寻迹
FlagStatus task_auto_track_switch = RESET;

void task_auto_track_switch_set(FlagStatus v)
{
    task_auto_track_switch = v;
}
FlagStatus task_auto_track_switch_get()
{
    return task_auto_track_switch;
}

void task_auto_track()
{
    if (task_auto_track_switch == RESET)
        return;
    // 没有黑线
    if (bsp_tracking_flag(tracking1) == SET &&
        bsp_tracking_flag(tracking2) == SET &&
        bsp_tracking_flag(tracking3) == SET &&
        bsp_tracking_flag(tracking4) == SET &&
        bsp_tracking_flag(tracking5) == SET)
    {
        car_brake();
    }
    // 很宽的黑线
    if (bsp_tracking_flag(tracking1) == RESET &&
        bsp_tracking_flag(tracking2) == RESET &&
        bsp_tracking_flag(tracking3) == RESET &&
        bsp_tracking_flag(tracking4) == RESET &&
        bsp_tracking_flag(tracking5) == RESET)
    {
        car_forward(80);
    }
    // 01111 差速左转
    if (bsp_tracking_flag(tracking1) == RESET &&
        bsp_tracking_flag(tracking2) == SET &&
        bsp_tracking_flag(tracking3) == SET &&
        bsp_tracking_flag(tracking4) == SET &&
        bsp_tracking_flag(tracking5) == SET)
    {
        car_forward_2(80, 100);
    }
    // 10111 差速左转
    if (bsp_tracking_flag(tracking1) == SET &&
        bsp_tracking_flag(tracking2) == RESET &&
        bsp_tracking_flag(tracking3) == SET &&
        bsp_tracking_flag(tracking4) == SET &&
        bsp_tracking_flag(tracking5) == SET)
    {
        car_forward_2(80, 100);
    }
    // 11011
    if (bsp_tracking_flag(tracking1) == SET &&
        bsp_tracking_flag(tracking2) == SET &&
        bsp_tracking_flag(tracking3) == RESET &&
        bsp_tracking_flag(tracking4) == SET &&
        bsp_tracking_flag(tracking5) == SET)
    {
        car_forward(80);
    }
    // 11101 差速右转
    if (bsp_tracking_flag(tracking1) == SET &&
        bsp_tracking_flag(tracking2) == SET &&
        bsp_tracking_flag(tracking3) == SET &&
        bsp_tracking_flag(tracking4) == RESET &&
        bsp_tracking_flag(tracking5) == SET)
    {
        car_forward_2(100, 80);
    }
    // 11110 差速右转
    if (bsp_tracking_flag(tracking1) == SET &&
        bsp_tracking_flag(tracking2) == SET &&
        bsp_tracking_flag(tracking3) == SET &&
        bsp_tracking_flag(tracking4) == SET &&
        bsp_tracking_flag(tracking5) == RESET)
    {
        car_forward_2(100, 80);
    }
    // 00111 差速左转
    if (bsp_tracking_flag(tracking1) == RESET &&
        bsp_tracking_flag(tracking2) == RESET &&
        bsp_tracking_flag(tracking3) == SET &&
        bsp_tracking_flag(tracking4) == SET &&
        bsp_tracking_flag(tracking5) == SET)
    {
        car_forward_2(80, 100);
    }
    // 10011 差速左转
    if (bsp_tracking_flag(tracking1) == SET &&
        bsp_tracking_flag(tracking2) == RESET &&
        bsp_tracking_flag(tracking3) == RESET &&
        bsp_tracking_flag(tracking4) == SET &&
        bsp_tracking_flag(tracking5) == SET)
    {
        car_forward_2(80, 100);
    }
    // 11001 差速右转
    if (bsp_tracking_flag(tracking1) == SET &&
        bsp_tracking_flag(tracking2) == SET &&
        bsp_tracking_flag(tracking3) == RESET &&
        bsp_tracking_flag(tracking4) == RESET &&
        bsp_tracking_flag(tracking5) == SET)
    {
        car_forward_2(100, 80);
    }
    // 11100 差速右转
    if (bsp_tracking_flag(tracking1) == SET &&
        bsp_tracking_flag(tracking2) == SET &&
        bsp_tracking_flag(tracking3) == SET &&
        bsp_tracking_flag(tracking4) == RESET &&
        bsp_tracking_flag(tracking5) == RESET)
    {
        car_forward_2(100, 80);
    }
    // 00011 差速左转
    if (bsp_tracking_flag(tracking1) == SET &&
        bsp_tracking_flag(tracking2) == SET &&
        bsp_tracking_flag(tracking3) == SET &&
        bsp_tracking_flag(tracking4) == RESET &&
        bsp_tracking_flag(tracking5) == RESET)
    {
        car_forward_2(80, 100);
    }
    // 10001
    if (bsp_tracking_flag(tracking1) == SET &&
        bsp_tracking_flag(tracking2) == RESET &&
        bsp_tracking_flag(tracking3) == RESET &&
        bsp_tracking_flag(tracking4) == RESET &&
        bsp_tracking_flag(tracking5) == SET)
    {
        car_forward(80);
    }
    // 11000 差速右转
    if (bsp_tracking_flag(tracking1) == SET &&
        bsp_tracking_flag(tracking2) == SET &&
        bsp_tracking_flag(tracking3) == RESET &&
        bsp_tracking_flag(tracking4) == RESET &&
        bsp_tracking_flag(tracking5) == RESET)
    {
        car_forward_2(100, 80);
    }
    // 00001 差速左转
    if (bsp_tracking_flag(tracking1) == SET &&
        bsp_tracking_flag(tracking2) == SET &&
        bsp_tracking_flag(tracking3) == RESET &&
        bsp_tracking_flag(tracking4) == RESET &&
        bsp_tracking_flag(tracking5) == RESET)
    {
        car_forward_2(80, 100);
    }
    // 10000 差速右转
    if (bsp_tracking_flag(tracking1) == SET &&
        bsp_tracking_flag(tracking2) == SET &&
        bsp_tracking_flag(tracking3) == RESET &&
        bsp_tracking_flag(tracking4) == RESET &&
        bsp_tracking_flag(tracking5) == RESET)
    {
        car_forward_2(100, 80);
    }
}
