#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <ctype.h>

typedef char StackDataType;

typedef struct Stack
{
    StackDataType* data;
    int capacity;
    int top;
}Stack;

void StackInit(Stack* ps)
{
    assert(ps);
    ps->data = (StackDataType*)malloc(sizeof(StackDataType) * 20);
    assert(ps->data);
    ps->capacity = 20;
    ps->top = 0;
}

void StackDestory(Stack* ps)
{
    assert(ps);
    free(ps->data);
    ps->data = NULL;
    ps->capacity = 0;
    ps->top = 0;
}

bool StackEmpty(Stack* ps)
{
    assert(ps);
    return ps->top == 0;
}

void StackPush(Stack* ps, StackDataType x)
{
    assert(ps);
    if (ps->top == ps->capacity)
    {
        StackDataType* tmp = NULL;
        tmp = (StackDataType*)realloc(ps->data,
            sizeof(StackDataType) * (2 * ps->capacity));
        if (tmp != NULL) {
            ps->data = tmp;
            ps->capacity *= 2;
        }
        else {
            perror("StackPush::realloc");
        }
    }
    (ps->data)[ps->top] = x;
    ps->top++;
}

void StackPop(Stack* ps)
{
    assert(ps);
    assert(!StackEmpty(ps));
    ps->top--;
}

int StackSize(Stack* ps)
{
    return ps->top;
}

StackDataType StackTop(Stack* ps)
{
    assert(ps);
    assert(!StackEmpty(ps));
    return (ps->data)[ps->top - 1];
}

/*-------------------------------------------------*/

void ReversePolish(char* s)
{
    Stack s1;
    StackInit(&s1);
    Stack s2;
    StackInit(&s2);
    while (*s)
    {
        char elem = *s;
        if (elem != ' ')
        {
            if (isdigit(elem))
            {
                StackPush(&s2, elem);
            }
            else if (elem == '(')
            {
                StackPush(&s1, elem);
            }
            else if (elem == ')')
            {
                while (StackTop(&s1) != '(')
                {
                    StackPush(&s2, StackTop(&s1));
                    StackPop(&s1);
                }
                StackPop(&s1);
            }
            else if (elem == '+')
            {
                if (StackEmpty(&s1) || StackTop(&s1) == '(') {
                    StackPush(&s1, elem);
                }
                else
                {
                    while (!StackEmpty(&s1) && StackTop(&s1) == '-')
                    {
                        StackPush(&s2, StackTop(&s1));
                        StackPop(&s1);
                    }
                    StackPush(&s1, elem);
                }
            }
            else
            {
                if (StackEmpty(&s1) || StackTop(&s1) == '(') {
                    StackPush(&s1, elem);
                }
                else
                {
                    while (!StackEmpty(&s1) && StackTop(&s1) == '+')
                    {
                        StackPush(&s2, StackTop(&s1));
                        StackPop(&s1);
                    }
                    StackPush(&s1, elem);
                }
            }
        }
        s++;
    }
    while (!StackEmpty(&s1))
    {
        StackPush(&s2, StackTop(&s1));
        StackPop(&s1);
    }

}

int main()
{
    char s[20] = " 2-1 + 2 ";
    ReversePolish(s);
    return 0;
}