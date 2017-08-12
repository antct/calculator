#include "graphics.h"
#include "extgraph.h"
#include "genlib.h"
#include "strlib.h"
#include "conio.h"
#include <stdlib.h>
#include <stddef.h>
#include <windows.h>
#include <olectl.h>
#include <mmsystem.h>
#include <wingdi.h>
#include <ole2.h>
#include <ocidl.h>
#include <winuser.h>
#include "math.h"
#include <stdio.h>
#include <string.h>
#define TIMER_BLINK500 1
#define TIMER_BLINK1000 2
int flag;
int flag2;
int flag3;
int flag4;
double maxy;
double maxx;
double lenth;
int cn;
double *x;
double *xo;
double *y;
double oldx;
double oldy;
double cx, cy;
double ox, oy;
int index;
int iindex;
double alinput;
char text[100];
char final[100];
char eqnfinal[100];
bool k1;
bool k2;
bool k3;
bool k4;
bool k5;
int k6;
bool k7;
bool k8;
double oox, ooy;
int klen, textlen;
double ans;
int n;
int ac;
const int mseconds500;
const int mseconds1000;
bool inAarc(double mx, double my, double rx, double ry, double r);
bool inState(double mx, double my, double rx, double ry, double a, double b);
void ClearFunction(void);
void Clear(void);
void restore(void);
void isFull(void);
void DrawTextS(int a, int b);
void DrawTextSS(int a, int b);
void DrawTextSSS(int a, int b);
void FullLeft(void);
void FullRight(void);
void error(void);
void Flash(void);
