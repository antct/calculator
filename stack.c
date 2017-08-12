
#include <stdio.h>
#include "genlib.h"
#include "stack.h"

#define MaxStackSize 1000

struct stackCDT
{
    void *array[MaxStackSize];
    int top;
};

stackADT NewStack(void)
{
    stackADT stack;

    stack = New(stackADT);
    stack->top = -1;
    return (stack);
}

void FreeStack(stackADT stack)
{
    FreeBlock(stack);
}

void PushStack1(stackADT stack, double *obj)
{
    if (stack->top == MaxStackSize - 1)
    {
        Error("Pushstack called on a full stack");
    }
    double *a;
    a = New(double *);
    *a = *obj;
    stack->array[++stack->top] = a;
}

void PushStack2(stackADT stack, char *obj)
{
    if (stack->top == MaxStackSize - 1)
    {
        Error("Pushstack called on a full stack");
    }
    char *a;
    a = New(char *);
    *a = *obj;
    stack->array[++stack->top] = a;
}

void *PopStack(stackADT stack)
{
    void *result;

    if (stack->top == -1)
    {
        Error("�������");
    }
    result = stack->array[stack->top--];
    return (result);
}

bool IsemptyStack(stackADT stack)
{
    return (stack->top == -1);
}

void *TopStack(stackADT stack)
{
    void *result;

    if (stack->top == -1)
        return (NULL);
    result = stack->array[stack->top];
    return (result);
}
