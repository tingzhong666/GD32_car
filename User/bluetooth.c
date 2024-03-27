/**
 * bluetooth.c
 * @tingzhong666
 * 2024-03-23 13:55:18
 */
#include <bluetooth.h>

// 命令选项存储 [0]为命令 后9个为选项参数
char cmd[10][64] = {NULL};
void bluetooth_msgToCmd(char *msg)
{
    int i;
    strcpy(cmd[0], strtok(msg, " "));

    for (i = 1; i < sizeof(cmd) / sizeof(cmd[0]); i++)
    {
        strcpy(cmd[i], strtok(NULL, " "));
    }
}

void bluetooth_msg_handler(char *msg)
{
    int speed;
    bluetooth_msgToCmd(msg);
    sscanf(cmd[1], "%d", &speed);

    if (strcmp(cmd[0], "car_stop") == 0)
    {
        car_stop();
    }
    if (strcmp(cmd[0], "car_forward") == 0)
    {
        car_forward((uint8_t)speed);
    }
    if (strcmp(cmd[0], "car_backward") == 0)
    {
        car_backward((uint8_t)speed);
    }
    if (strcmp(cmd[0], "car_left") == 0)
    {
        car_left((uint8_t)speed);
    }
    if (strcmp(cmd[0], "car_right") == 0)
    {
        car_right((uint8_t)speed);
    }
    if (strcmp(cmd[0], "car_brake") == 0)
    {
        car_brake();
    }
    // 寻迹开关
    if (strcmp(cmd[0], "track") == 0)
    {
        // set || reset
        if (strcmp(cmd[1], "set") == 0)
        {
            task_auto_track_switch_set(SET);
        }
        else if(strcmp(cmd[1], "reset") == 0)
        {
            task_auto_track_switch_set(RESET);
        }
    }
}

void bluetooth_init()
{
    bsp_usart2_ISR_set(bluetooth_msg_handler);
}
