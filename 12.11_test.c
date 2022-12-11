#define _CRT_SECURE_NO_WARNINGS 1


#include<stdbool.h>
#include<stdio.h>

//int Sum(int n)
//{
//	int sum = 0;
//	_Bool flag = (n > 0) && (sum = n + Sum(n - 1));//&&的断路特征
//	return sum;
//}
//
////int Sum(int n)
////{
////if (n > 0)
////{
////return n + Sum(n - 1);
////}
////else
////{
////return 0;
////}
////}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Sum(n);
//	printf("%d\n", ret);
//	return 0;
//}

//用栈实现队列
//typedef struct
//{
//    //由两个栈构成的队列
//    ST s1;
//    ST s2;
//} MyQueue;
//
//
//MyQueue* myQueueCreate()
//{
//    MyQueue* M = (MyQueue*)malloc(sizeof(MyQueue));
//    if (M == NULL)
//    {
//        perror("CreatQueue:");
//        exit(-1);
//    }
//
//    StackInit(&M->s1);
//    StackInit(&M->s2);
//
//    return M;
//}
//
//void myQueuePush(MyQueue* obj, int x)
//{
//    //若s1不为空则放入s1，否则放入s2
//    if (!StackEmpty(&obj->s1))
//    {
//        StackPush(&obj->s1, x);
//    }
//    else
//    {
//        StackPush(&obj->s2, x);
//    }
//
//    //假设s1为STpush,s2为STpop
//    //StackPush(&obj->s1, x);//-----------
//}
//
//int myQueuePop(MyQueue* obj)
//{
//    ST* empty = &obj->s1;
//    ST* noempty = &obj->s2;
//    if (!StackEmpty(&obj->s1))
//    {
//        empty = &obj->s2;
//        noempty = &obj->s2;
//    }
//
//    //倒数据
//    while (StackSize(noempty) > 1)
//    {
//        StackPush(empty, StackTopData(noempty));
//        StackPop(noempty);
//    }
//    int top = StackTopData(noempty);
//    StackPop(noempty);
//
//    //倒回元素
//    while (!StackEmpty(empty))
//    {
//        StackPush(noempty, StackTopData(empty));
//        StackPop(empty);
//    }
//
//    return top;
//
//    //若STpop不为空，则popSTpop中的元素
//    // if(!StackEmpty(&obj->s2))
//    // {
//    //     int top = StackTopData(&obj->s2);
//    //     StackPop(&obj->s2);
//    //     return top;
//    // }
//    // //若STpop为空，则现将STpush中的元素倒入STpop
//    // else
//    // {
//    //     while(!StackEmpty(&obj->s1))
//    //     {
//    //         StackPush(&obj->s2, StackTopData(&obj->s1));
//    //         StackPop(&obj->s1);
//    //     }
//    //     int top = StackTopData(&obj->s2);
//    //     StackPop(&obj->s2);
//    //     return top;
//    // }
//}
//
//int myQueuePeek(MyQueue* obj)
//{
//    ST* empty = &obj->s1;
//    ST* noempty = &obj->s2;
//    if (!StackEmpty(&obj->s1))
//    {
//        empty = &obj->s2;
//        noempty = &obj->s2;
//    }
//
//    //倒数据
//    while (StackSize(noempty) > 1)
//    {
//        StackPush(empty, StackTopData(noempty));
//        StackPop(noempty);
//    }
//
//    int top = StackTopData(noempty);
//
//    //倒回元素
//    while (!StackEmpty(empty))
//    {
//        StackPush(noempty, StackTopData(empty));
//        StackPop(empty);
//    }
//
//    return top;
//
//    //若STpop不为空，则popSTpop中的元素
//    // if(!StackEmpty(&obj->s2))
//    // {
//    //     int top = StackTopData(&obj->s2);
//    //     //StackPop(&obj->s2);
//    //     return top;
//    // }
//    // //若STpop为空，则现将STpush中的元素倒入STpop
//    // else
//    // {
//    //     while(!StackEmpty(&obj->s1))
//    //     {
//    //         StackPush(&obj->s2, StackTopData(&obj->s1));
//    //         StackPop(&obj->s1);
//    //     }
//    //     int top = StackTopData(&obj->s2);
//    //     //StackPop(&obj->s2);
//    //     return top;
//    // }
//}
//
//bool myQueueEmpty(MyQueue* obj)
//{
//    return StackEmpty(&obj->s1) && StackEmpty(&obj->s2);
//}
//
//void myQueueFree(MyQueue* obj)
//{
//    StackDestory(&obj->s1);
//    StackDestory(&obj->s2);
//
//    free(obj);
//}

typedef struct
{
    ST StackIn;
    ST StackOut;
} MyQueue;


MyQueue* myQueueCreate()
{
    MyQueue* NewQueue = (MyQueue*)malloc(sizeof(MyQueue));
    StackInit(&NewQueue->StackIn);
    StackInit(&NewQueue->StackOut);
    return NewQueue;
}

void myQueuePush(MyQueue* obj, int x)
{
    StackPush(&obj->StackIn, x);
}

int myQueuePop(MyQueue* obj)
{
    if (!StackEmpty(&obj->StackOut))
    {
        int top = StackTopData(&obj->StackOut);
        StackPop(&obj->StackOut);
        return top;
    }
    else
    {
        //倒数据
        while (!StackEmpty(&obj->StackIn))
        {
            StackPush(&obj->StackOut, StackTopData(&obj->StackIn));
            StackPop(&obj->StackIn);
        }
    }

    int top = StackTopData(&obj->StackOut);
    StackPop(&obj->StackOut);
    return top;
}

int myQueuePeek(MyQueue* obj)
{
    if (!StackEmpty(&obj->StackOut))
    {
        //StackOut不为空，直接返回其栈顶元素
        //记录栈顶元素后不要误pop
        int top = StackTopData(&obj->StackOut);
        return top;
    }
    else
    {
        //StackOut为空，将数据倒入StackOut中，再返回其栈顶元素
        while (!StackEmpty(&obj->StackIn))
        {
            StackPush(&obj->StackOut, StackTopData(&obj->StackIn));
            StackPop(&obj->StackIn);
        }
        int top = StackTopData(&obj->StackOut);
        //直接返回
        return top;
    }
}

bool myQueueEmpty(MyQueue* obj)
{
    return StackEmpty(&obj->StackIn) && StackEmpty(&obj->StackOut);
}

void myQueueFree(MyQueue* obj)
{
    StackDestory(&obj->StackIn);
    StackDestory(&obj->StackOut);
    free(obj);
    obj = NULL;
}