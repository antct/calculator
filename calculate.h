#include "stack.h"
#include <stdio.h>
#include <math.h>
#define E 2.718281828
double MR;
int cn;
double *x;
double ans;
char text[100];

int isnumber(char c);
int isletter(char c);
int issymbol(char c);
char *scan(char *k);
int trans(char *a);
void process(stackADT stack, char *out);
double fact(double n);
double *calculate(char c);
