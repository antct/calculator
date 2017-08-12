
#ifndef _stack_h
#define _stack_h
#include "genlib.h"

typedef struct stackCDT *stackADT;

stackADT NewStack(void);

void FreeStack(stackADT stack);

void PushStack1(stackADT stack, double *obj);

void PushStack2(stackADT stack, char *obj);

void *PopStack(stackADT stack);

bool IsemptyStack(stackADT stack);

void *TopStack(stackADT stack);

#endif
