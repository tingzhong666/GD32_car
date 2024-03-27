/**
 * test.h
 * @tingzhong666
 * 2024-03-13 16:14:49
 */

#ifndef TEST_H
#define TEST_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "gd32f4xx.h"

    FlagStatus testFlag_get(void);
    void testFlag_set(FlagStatus value);

#ifdef __cplusplus
}
#endif

#endif
