/**
 * test.c
 * @tingzhong666
 * 2024-03-13 16:13:31
 */
#include <test.h>

FlagStatus testFlag = RESET;

FlagStatus testFlag_get()
{
    return testFlag;
}

void testFlag_set(FlagStatus value)
{
    testFlag = value;
}
