#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"


typedef struct
{
    Stack Stack_Data;
    Stack Stack_MinData;//¸¨ÖúÕ»
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate()
{
    MinStack* NewStack = (MinStack*)malloc(sizeof(MinStack));
    InitStack(&NewStack->Stack_Data);
    InitStack(&NewStack->Stack_MinData);
    return NewStack;
}

void minStackPush(MinStack* obj, int x)
{
    StackPush(&obj->Stack_Data, x);

    if (StackEmpty(&obj->Stack_MinData))
    {
        StackPush(&obj->Stack_MinData, x);
    }
    else
    {
        if (x <= StackTopData(&obj->Stack_MinData))
        {
            StackPush(&obj->Stack_MinData, x);
        }
    }
}

void minStackPop(MinStack* obj)
{
    int aim = StackTopData(&obj->Stack_Data);
    StackPop(&obj->Stack_Data);

    if (StackTopData(&obj->Stack_MinData) == aim)
    {
        StackPop(&obj->Stack_MinData);
    }
}

int minStackTop(MinStack* obj)
{
    return StackTopData(&obj->Stack_Data);
}

int minStackMin(MinStack* obj)
{
    return StackTopData(&obj->Stack_MinData);
}

void minStackFree(MinStack* obj)
{
    StackDestory(&obj->Stack_Data);
    StackDestory(&obj->Stack_MinData);
}

//***---------------------------------------------------

void test(void)
{
    MinStack* minStack = minStackCreate();
    minStackPush(minStack, 85);
    minStackPush(minStack, -99);
    minStackPush(minStack, 67);
    printf("%d\n", minStackMin(minStack));
    minStackPush(minStack, -27);
    minStackPush(minStack, 61);
    minStackPush(minStack, -97);
    minStackPush(minStack, -27);
    minStackPush(minStack, 35);
    printf("%d\n", minStackTop(minStack));
    minStackPush(minStack, 99);
    minStackPush(minStack, -66);
    printf("%d\n", minStackMin(minStack));
    minStackPush(minStack, -89);
    printf("%d\n", minStackMin(minStack));


}

int main()
{
    test();
    return 0;
}