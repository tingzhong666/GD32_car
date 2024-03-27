/**
 * auto_track.h
 * @tingzhong666
 * 2024-03-27 16:22:54
 */

#ifndef AUTO_TRACK_H
#define AUTO_TRACK_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "tracking.h"
#include "car.h"

    void task_auto_track(void);
    void task_auto_track_switch_set(FlagStatus v);
    FlagStatus task_auto_track_switch_get(void);

#ifdef __cplusplus
}
#endif

#endif
