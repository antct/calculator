#include "graphics.h"
#include "extgraph.h"
#include "genlib.h"
#include "strlib.h"
#include "conio.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stddef.h>
#include <windows.h>
#include <olectl.h>
#include <mmsystem.h>
#include <wingdi.h>
#include <ole2.h>
#include <ocidl.h>
#include <winuser.h>
#include "outline.h"
#include "calculate.h"
#include "eqn.h"
#include "assistance.h"
#include "statement.h"

void MouseEventProcess(int x, int y, int button, int event);
void TimerEventProcess(int timerID);
void KeyboardEventProcess(int key, int event);
void CharEventProcess(char c);
void CharPut(char c);

void Main()
{
	SetWindowSize(3.6, 6.0);
	InitGraphics();
	SetWindowTitle("������");
	DrawOutline();
	registerMouseEvent(MouseEventProcess);
	registerCharEvent(CharEventProcess);
	registerTimerEvent(TimerEventProcess);
	registerKeyboardEvent(KeyboardEventProcess);
	cx = 3.6;
	cy = 6.0;
	oox = ox = 0.4;
	ooy = oy = 0.88 * cy;
	xo = New(double *);
	xf = New(double *); //Ϊ�˱���ָ�ԭֵ
	Clear();
}

void KeyboardEventProcess(int key, int event)
{
	int i;
	result = New(double *);
	x = New(double *);
	y = New(double *);
	xx = New(double *);
	yy = New(double *);
	sum = New(double *);
	aa = New(double *);
	bb = New(double *);
	cc = New(double *);
	dd = New(double *);
	char temp;
	if (flag)
		switch (event)
		{
		case KEY_DOWN:
			switch (key)
			{
			case VK_RETURN:
				SetEraseMode(1);
				MovePen(3.2 - TextStringWidth(final), 0.8 * cy);
				DrawTextString(final);
				SetEraseMode(0);
				cn = 0;
				if (!k1 && !k2 && !k3 && !k4 && !k5 && !k6 && !k7 && !k8)
				{
					result = calculate('\0');
					ans = *result;
					sprintf(final, "%.*f", ac, *result);
					MovePen(3.2 - TextStringWidth(final), 0.8 * cy);
					if (!flag4)
						DrawTextString(final);
					cancelTimer(TIMER_BLINK500);
				}
				else if (k1 && !k2 && !k3 && !k4 && !k5 && !k6 && !k7 && !k8)
				{
					result = calculate('\0');
					ans = *result;
					ac = ans;
					cancelTimer(TIMER_BLINK500);
					MovePen(ox, oy);
					SetEraseMode(1);
					DrawLine(0, 0.13);
					SetEraseMode(1);
					MovePen(oox - TextStringWidth("����nλС��:"), oy);
					DrawTextString("����nλС��:");
					sprintf(final, "%.*f", ac, *result);
					DrawTextSS(index, textlen - iindex);
					SetEraseMode(0);
					cn = 0;
					n = 0;
					ox = 0.4;
					ans = 0;
					oox = 0.4;
					startTimer(TIMER_BLINK500, mseconds500);
					klen = 0;
					textlen = 0;
					memset(text, '\0', sizeof(text));
					memset(final, '\0', sizeof(final));
					k1 = !k1;
				}
				else if (!k1 && k2 && !k3 && !k4 && !k5 && !k6 && !k7 && !k8)
				{
					cancelTimer(TIMER_BLINK500);
					cn = 0;
					x = calculate(',');
					y = calculate('\0');
					cn = 0;
					x = calculate(',');
					*x = *x * 1.000000001;
					yy = calculate('\0');
					*result = (*yy - *y) / (*x - *x / 1.000000001);
					sprintf(final, "%.*f", ac, *result);
					MovePen(3.2 - TextStringWidth(final), 0.8 * cy);
					if (!flag4)
						DrawTextString(final);
				}
				else if (!k1 && !k2 && k3 && !k4 && !k5 && !k6 && !k7 && !k8)
				{
					cancelTimer(TIMER_BLINK500);
					cn = 0;
					xo = calculate(',');
					xf = calculate(',');
					lenth = *xf - *xo;
					for (i = 1; i <= 10000; i++)
					{
						cn = 0;
						x = calculate(',');
						x = calculate(',');
						*x = *xo + lenth * (double)(i - 0.5) / 10000.0;
						y = calculate('\0');
						*sum += *y * lenth / 10000.0;
					}
					sprintf(final, "%.*f", ac, *sum);
					MovePen(3.2 - TextStringWidth(final), 0.8 * cy);
					if (!flag4)
						DrawTextString(final);
				}
				else if (!k1 && !k2 && !k3 && k4 && !k5 && !k6 && !k7 && !k8)
				{
					result = calculate('\0');
					Clear();
					MovePen(oox, ooy);
					if (*result == 1)
					{
						startTimer(TIMER_BLINK500, mseconds500);
						k4 = FALSE;
					}
					else if (*result == 2)
					{
						DrawTextString("���̴���(1-3):");
						ox += TextStringWidth("���̴���(1-3):");
						oox += TextStringWidth("���̴���(1-3):");
						alinput = TextStringWidth("���̴���(1-3):");
						startTimer(TIMER_BLINK500, mseconds500);
						k5 = TRUE;
						k4 = FALSE;
					}
					else if (*result == 3)
					{
						DrawTextString("[a,b],f(x):");
						ox += TextStringWidth("[a,b],f(x):");
						oox += TextStringWidth("[a,b],f(x):");
						alinput = TextStringWidth("[a,b],f(x):");
						startTimer(TIMER_BLINK500, mseconds500);
						k7 = TRUE;
						k4 = FALSE;
					}
					else
					{
						error();
					}
				}
				else if (!k1 && !k2 && !k3 && !k4 && k5 && !k6 && !k7 && !k8)
				{
					result = calculate('\0');
					Clear();
					MovePen(oox, ooy);
					if (*result == 1)
					{
						Clear();
						MovePen(oox, oy);
						DrawTextString("ax+b=0 a,b:");
						ox += TextStringWidth("ax+b=0 a,b:");
						oox += TextStringWidth("ax+b=0 a,b:");
						alinput += TextStringWidth("ax+b=0 a,b:");
						startTimer(TIMER_BLINK500, mseconds500);
						k6 = 1;
						k5 = FALSE;
					}
					if (*result == 2)
					{
						Clear();
						MovePen(oox, oy);
						DrawTextString("ax^2+bx+c=0 a,b,c:");
						ox += TextStringWidth("ax^2+bx+c=0 a,b,c:");
						oox += TextStringWidth("ax^2+bx+c=0 a,b,c:");
						alinput += TextStringWidth("ax^2+bx+c=0 a,b,c:");
						startTimer(TIMER_BLINK500, mseconds500);
						k6 = 2;
						k5 = FALSE;
					}
					if (*result == 3)
					{
						Clear();
						MovePen(oox, oy);
						DrawTextString("ax^3+bx^2+cx+d=0 a,b,c,d:");
						ox += TextStringWidth("ax^3+bx^2+cx+d=0 a,b,c,d:");
						oox += TextStringWidth("ax^3+bx^2+cx+d=0 a,b,c,d:");
						alinput += TextStringWidth("ax^3+bx^2+cx+d=0 a,b,c,d:");
						startTimer(TIMER_BLINK500, mseconds500);
						k6 = 3;
						k5 = FALSE;
					}
				}
				else if (!k1 && !k2 && !k3 && !k4 && !k5 && k6 && !k7 && !k8)
				{
					if (k6 == 1)
					{
						cancelTimer(TIMER_BLINK500);
						aa = calculate(',');
						bb = calculate('\0');
						eqn1(aa, bb);
						MovePen(3.2 - TextStringWidth(eqnfinal), 0.8 * cy);
						if (!flag4)
							DrawTextString(eqnfinal);
					}
					if (k6 == 2)
					{
						cancelTimer(TIMER_BLINK500);
						aa = calculate(',');
						bb = calculate(',');
						cc = calculate('\0');
						eqn2(aa, bb, cc);
						MovePen(3.2 - TextStringWidth(eqnfinal), 0.8 * cy);
						if (!flag4)
							DrawTextString(eqnfinal);
					}
					if (k6 == 3)
					{
						cancelTimer(TIMER_BLINK500);
						aa = calculate(',');
						bb = calculate(',');
						cc = calculate(',');
						dd = calculate('\0');
						eqn3(aa, bb, cc, dd);
						MovePen(3.2 - TextStringWidth(eqnfinal), 0.8 * cy);
						if (!flag4)
							DrawTextString(eqnfinal);
					}
				}
				else if (!k1 && !k2 && !k3 && !k4 && !k5 && !k6 && k7 && !k8)
				{
					cancelTimer(TIMER_BLINK500);
					cn = 0;
					maxx = 0;
					maxy = 0;
					xo = calculate(',');
					xf = calculate(',');
					lenth = *xf - *xo;
					for (i = 1; i <= 2000; i++)
					{
						cn = 0;
						x = calculate(',');
						x = calculate(',');
						*x = *xo + lenth * (double)(i - 0.5) / 2000.0;
						y = calculate('\0');
						if (*y > maxy)
							maxy = *y;
					}
					maxx = max(fabs(*xo), fabs(*xf));
					ClearFunction();
					flag2 = 1;
				}
				else if (!k1 && !k2 && !k3 && !k4 && !k5 && !k6 && !k7 && k8)
				{
					cancelTimer(TIMER_BLINK500);
					xo = calculate(',');
					xf = calculate(',');
					lenth = *xf - *xo;
					for (i = *xo; i <= *xf; i++)
					{
						cn = 0;
						x = calculate(',');
						x = calculate(',');
						*x = i;
						y = calculate('\0');
						*sum += *y;
					}
					sprintf(final, "%.*f", ac, *sum);
					MovePen(3.2 - TextStringWidth(final), 0.8 * cy);
					if (!flag4)
						DrawTextString(final);
				}
				break;
			case VK_LEFT:
				restore();
				if (n == textlen)
					break;
				n++;
				MovePen(ox, oy);
				SetEraseMode(1);
				DrawLine(0, 0.13);
				DrawTextS(index, textlen - iindex);
				ox = ox + (TextStringWidth(text + klen) - TextStringWidth(text + (klen--) - 1));
				FullLeft();
				MovePen(ox, oy);
				Flash();
				startTimer(TIMER_BLINK500, mseconds500);
				break;
			case VK_RIGHT:
				restore();
				if (n == 0)
					break;
				if (n-- <= 0)
					break;
				MovePen(ox, oy);
				SetEraseMode(1);
				DrawLine(0, 0.13);
				DrawTextS(index, textlen - iindex);
				ox = ox + (TextStringWidth(text + klen++) - TextStringWidth(text + klen));
				FullRight();
				MovePen(ox, oy);
				Flash();
				startTimer(TIMER_BLINK500, mseconds500);
				break;
			case VK_DELETE:
			case VK_BACK:
				restore();
				if (klen == 0)
					break;
				MovePen(ox, oy);
				SetEraseMode(1);
				DrawLine(0, 0.13);
				DrawTextSS(index, textlen - iindex);
				ox += (TextStringWidth(text + klen) - TextStringWidth(text + (klen--) - 1));
				SetEraseMode(0);
				textlen--;
				if (klen < textlen)
				{
					for (i = klen + 1; i <= textlen; i++)
					{
						temp = text[i];
						text[i - 1] = temp;
					}
					text[textlen] = '\0';
				}
				if (klen == textlen)
				{
					text[textlen] = '\0';
				}
				if (!index)
				{
					if (iindex && !index)
						iindex--;
					DrawTextS(index, textlen - iindex);
					MovePen(ox, oy);
				}
				else
				{
					if (index >= 1)
						index--;
					if (iindex && !index)
						iindex--;
					DrawTextS(index, textlen - iindex);
					ox = oox + TextStringWidth(text + index) - TextStringWidth(text + klen);
				}
				Flash();
				startTimer(TIMER_BLINK500, mseconds500);
				break;
			case VK_F1:
				system("start help.txt");
				break;
			}
		}
}

void MouseEventProcess(int x, int y, int button, int event)
{
	double mx, my;
	int i, j;
	mx = ScaleXInches(x);
	my = ScaleYInches(y);
	switch (event)
	{
	case BUTTON_DOWN:
		if (button == RIGHT_BUTTON)
		{
			if (inState(mx, my, 0.3 + 0.52 * 4, 0.42 * cy, 0.4, 0.22))
			{
				MR = 0;
				SetEraseMode(1);
				MovePen(0.4, 0.91 * cy);
				DrawTextString("M");
				SetEraseMode(0);
			}
		}
		if (button == LEFT_BUTTON)
		{
			if (inAarc(mx, my, 3.3 - 0.15, 0.7 * cy, 0.15))
			{
				if (flag == 1)
				{
					Clear();
					SetEraseMode(1);
					MovePen(0.4, 0.91 * cy);
					DrawTextString("M");
					MR = 0;
					SetEraseMode(0);
					if (flag2)
						cancelTimer(TIMER_BLINK500);
					flag = 0;
				}
				else
				{
					startTimer(TIMER_BLINK500, mseconds500);
					flag = 1;
				}
			}
			if (inAarc(mx, my, 3.3 - 0.575 - 0.15, 0.7 * cy, 0.15))
			{
				system("start help.txt");
			}
			if (inAarc(mx, my, 0.3 + 0.15, 0.7 * cy, 0.15) && flag)
			{
				Clear();
				MovePen(ox, oy);
				DrawTextString("1:����ģʽ  2:����ģʽ  3:��ͼģʽ:");
				ox += TextStringWidth("1:����ģʽ  2:����ģʽ  3:��ͼģʽ:");
				oox += TextStringWidth("1:����ģʽ  2:����ģʽ  3:��ͼģʽ:");
				alinput = TextStringWidth("1:����ģʽ  2:����ģʽ  3:��ͼģʽ:");
				startTimer(TIMER_BLINK500, mseconds500);
				k4 = TRUE;
			}
			if (inAarc(mx, my, 0.3 + 0.875 - 0.15, 0.7 * cy, 0.15) && flag)
			{
				Clear();
				MovePen(ox, oy);
				DrawTextString("����nλС��:");
				ox += TextStringWidth("����nλС��:");
				oox += TextStringWidth("����nλС��:");
				alinput = TextStringWidth("����nλС��:");
				k1 = TRUE;
				startTimer(TIMER_BLINK500, mseconds500);
			}
			if (inState(mx, my, 0.3 + 0 * 0.62, (0.14) * cy, 0.52, 0.25))
			{
				c = '0';
				CharPut(c);
			}
			if (inState(mx, my, 0.3 + 1 * 0.62, (0.14) * cy, 0.52, 0.25))
			{
				c = 'u';
				CharPut(c);
			}
			for (i = 2; i <= 4; i++)
			{
				for (j = 1; j <= 3; j++)
				{
					if (inState(mx, my, 0.3 + (j - 1) * 0.62, (0.14 + (i - 1) * 0.07) * cy, 0.52, 0.25))
					{
						c = *(a + 2 * j + (i - 2) * 6);
						CharPut(c);
					}
				}
			}
			if (inState(mx, my, 1.7 - 0.2598, 0.7 * cy - 0.15, 0.2598, 0.3))
			{
				c = 'z';
				CharPut(c);
			}
			if (inState(mx, my, 1.9, 0.7 * cy - 0.15, 0.2598, 0.3))
			{
				c = 'v';
				CharPut(c);
			}
			if (inState(mx, my, 0.3 + 3 * 0.62, (0.14 + 0.21) * cy, 0.52, 0.25))
			{
				c = '#';
				CharPut(c);
			}
			if (inState(mx, my, 0.3 + 3 * 0.62, (0.14 + 0.07) * cy, 0.52, 0.25))
			{
				c = '+';
				CharPut(c);
			}
			if (inState(mx, my, 0.3 + 4 * 0.62, (0.14 + 0.07) * cy, 0.52, 0.25))
			{
				c = '-';
				CharPut(c);
			}
			if (inState(mx, my, 0.3 + 3 * 0.62, (0.14 + 0.14) * cy, 0.52, 0.25))
			{
				c = '*';
				CharPut(c);
			}
			if (inState(mx, my, 0.3 + 4 * 0.62, (0.14 + 0.14) * cy, 0.52, 0.25))
			{
				c = '/';
				CharPut(c);
			}
			if (inState(mx, my, 0.3 + 2 * 0.62, 0.14 * cy, 0.52, 0.25))
			{
				c = ',';
				CharPut(c);
			}
			if (inState(mx, my, 0.3 + 0.52 * 2, 0.42 * cy, 0.4, 0.22))
			{
				c = '(';
				CharPut(c);
			}
			if (inState(mx, my, 0.3 + 0.52 * 3, 0.42 * cy, 0.4, 0.22))
			{
				c = ')';
				CharPut(c);
			}
			if (inState(mx, my, 0.3, 0.6 * cy, 0.4, 0.22))
			{
				c = 'e';
				CharPut(c);
			}

			if (inState(mx, my, 0.3 + 0.52 * 2, 0.6 * cy, 0.4, 0.22))
			{
				c = '!';
				CharPut(c);
			}
			if (inState(mx, my, 0.3 + 0.52 * 3, 0.6 * cy, 0.4, 0.22))
			{
				Clear();
				MovePen(ox, oy);
				DrawTextString("��");
				MovePen(oox + 0.14, oy);
				DrawTextString("(x=a,b)f(x):");
				ox += 0.14 + TextStringWidth("(x=a,b)f(x):");
				oox += 0.14 + TextStringWidth("(x=a,b)f(x):");
				alinput = 0.14 + TextStringWidth("(x=a,b)f(x):");
				k8 = TRUE;
				startTimer(TIMER_BLINK500, mseconds500);
			}
			if (inState(mx, my, 0.3 + 0.52 * 4, 0.6 * cy, 0.4, 0.22))
			{
				Clear();
				MovePen(ox, oy);
				DrawTextString("df/dx|x=a:");
				ox += TextStringWidth("df/dx|x=a:");
				oox += TextStringWidth("df/dx|x=a:");
				alinput = TextStringWidth("df/dx|x=a:");
				k2 = TRUE;
				startTimer(TIMER_BLINK500, mseconds500);
			}
			if (inState(mx, my, 0.3 + 0.52 * 1, 0.6 * cy, 0.4, 0.22))
			{
				c = 'x';
				CharPut(c);
			}
			if (inState(mx, my, 0.3, 0.54 * cy, 0.4, 0.22))
			{
				c = 's';
				CharPut(c);
				c = 'i';
				CharPut(c);
				c = 'n';
				CharPut(c);
				c = '(';
				CharPut(c);
				c = ')';
				CharPut(c);
				c = 'z';
				CharPut(c);
			}
			if (inState(mx, my, 0.3 + 0.52, 0.54 * cy, 0.4, 0.22))
			{
				c = 'c';
				CharPut(c);
				c = 'o';
				CharPut(c);
				c = 's';
				CharPut(c);
				c = '(';
				CharPut(c);
				c = ')';
				CharPut(c);
				c = 'z';
				CharPut(c);
			}
			if (inState(mx, my, 0.3 + 0.52 * 2, 0.54 * cy, 0.4, 0.22))
			{
				c = 't';
				CharPut(c);
				c = 'a';
				CharPut(c);
				c = 'n';
				CharPut(c);
				c = '(';
				CharPut(c);
				c = ')';
				CharPut(c);
				c = 'z';
				CharPut(c);
			}
			if (inState(mx, my, 0.3 + 0.52 * 3, 0.54 * cy, 0.4, 0.22))
			{
				c = 'a';
				CharPut(c);
				c = 's';
				CharPut(c);
				c = 'i';
				CharPut(c);
				c = 'n';
				CharPut(c);
				c = '(';
				CharPut(c);
				c = ')';
				CharPut(c);
				c = 'z';
				CharPut(c);
			}
			if (inState(mx, my, 0.3 + 0.52 * 4, 0.54 * cy, 0.4, 0.22))
			{
				c = 'a';
				CharPut(c);
				c = 'c';
				CharPut(c);
				c = 'o';
				CharPut(c);
				c = 's';
				CharPut(c);
				c = '(';
				CharPut(c);
				c = ')';
				CharPut(c);
				c = 'z';
				CharPut(c);
			}
			if (inState(mx, my, 0.3 + 0.52 * 5, 0.54 * cy, 0.4, 0.22))
			{
				c = 'a';
				CharPut(c);
				c = 't';
				CharPut(c);
				c = 'a';
				CharPut(c);
				c = 'n';
				CharPut(c);
				c = '(';
				CharPut(c);
				c = ')';
				CharPut(c);
				c = 'z';
				CharPut(c);
			}
			if (inState(mx, my, 0.3, 0.48 * cy, 0.4, 0.22))
			{
				c = 'l';
				CharPut(c);
				c = 'o';
				CharPut(c);
				c = 'g';
				CharPut(c);
				c = '(';
				CharPut(c);
				c = ',';
				CharPut(c);
				c = ')';
				CharPut(c);
				c = 'z';
				CharPut(c);
				c = 'z';
				CharPut(c);
			}
			if (inState(mx, my, 0.3 + 0.52, 0.48 * cy, 0.4, 0.22))
			{
				c = 'l';
				CharPut(c);
				c = 'n';
				CharPut(c);
				c = '(';
				CharPut(c);
				c = ')';
				CharPut(c);
				c = 'z';
				CharPut(c);
			}
			if (inState(mx, my, 0.3 + 0.52 * 2, 0.48 * cy, 0.4, 0.22))
			{
				c = '[';
				CharPut(c);
				c = ']';
				CharPut(c);
				c = 'z';
				CharPut(c);
			}
			if (inState(mx, my, 0.3 + 0.52 * 3, 0.48 * cy, 0.4, 0.22))
			{
				c = '|';
				CharPut(c);
				c = '|';
				CharPut(c);
				c = 'z';
				CharPut(c);
			}
			if (inState(mx, my, 0.3 + 0.52 * 4, 0.48 * cy, 0.4, 0.22))
			{
				c = 'm';
				CharPut(c);
				c = 'a';
				CharPut(c);
				c = 'x';
				CharPut(c);
				c = '(';
				CharPut(c);
				c = ',';
				CharPut(c);
				c = ')';
				CharPut(c);
				c = 'z';
				CharPut(c);
				c = 'z';
				CharPut(c);
			}
			if (inState(mx, my, 0.3 + 0.52 * 5, 0.48 * cy, 0.4, 0.22))
			{
				c = 'm';
				CharPut(c);
				c = 'i';
				CharPut(c);
				c = 'n';
				CharPut(c);
				c = '(';
				CharPut(c);
				c = ',';
				CharPut(c);
				c = ')';
				CharPut(c);
				c = 'z';
				CharPut(c);
				c = 'z';
				CharPut(c);
			}
			if (inState(mx, my, 0.3 + 0.52 * 0, 0.42 * cy, 0.4, 0.22))
			{
				c = '^';
				CharPut(c);
			}
			if (inState(mx, my, 0.3 + 0.52 * 1, 0.42 * cy, 0.4, 0.22))
			{
				c = '%';
				CharPut(c);
			}
			if (inState(mx, my, 0.3 + 4 * 0.62, 0.14 * cy, 0.52, 0.25))
			{
				c = '=';
				CharPut(c);
			}
			if (inState(mx, my, 0.3 + 3 * 0.62, 0.14 * cy, 0.52, 0.25))
			{
				c = 'A';
				CharPut(c);
				c = 'n';
				CharPut(c);
				c = 's';
				CharPut(c);
				restore();
			}
			if (inState(mx, my, 0.3 + 0.52 * 4, 0.42 * cy, 0.4, 0.22))
			{
				MR = ans;
				MovePen(0.4, 0.91 * cy);
				DrawTextString("M");
			}
			if (inState(mx, my, 0.3 + 0.52 * 5, 0.42 * cy, 0.4, 0.22))
			{
				c = 'M';
				CharPut(c);
				restore();
			}
			if (inState(mx, my, 0.3 + 4 * 0.62, 0.35 * cy, 0.52, 0.25))
			{
				Clear();
				startTimer(TIMER_BLINK500, mseconds500);
			}
			if (inState(mx, my, 0.3 + 0.52 * 5, 0.6 * cy, 0.4, 0.22))
			{
				Clear();
				MovePen(oox, oy);
				DrawTextString("��");
				MovePen(oox + 0.10, oy);
				DrawTextString("(a,b)f(x)dx:");
				ox += 0.10 + TextStringWidth("(a,b)f(x)dx:");
				oox += 0.10 + TextStringWidth("(a,b)f(x)dx:");
				alinput = 0.10 + TextStringWidth("(a,b)f(x)dx:");
				k3 = TRUE;
				startTimer(TIMER_BLINK500, mseconds500);
			}
		}
	}
}

void CharPut(char c)
{
	x = New(double *);
	y = New(double *);
	xx = New(double *);
	yy = New(double *);
	sum = New(double *);
	aa = New(double *);
	bb = New(double *);
	cc = New(double *);
	dd = New(double *);
	registerTimerEvent(TimerEventProcess);
	int i, flagp;
	char temp;
	result = New(double *);
	MovePen(ox, oy);
	SetEraseMode(1);
	DrawLine(0, 0.13);
	SetEraseMode(0);
	switch (c)
	{
	case '=':
		SetEraseMode(1);
		MovePen(3.2 - TextStringWidth(final), 0.8 * cy);
		DrawTextString(final);
		SetEraseMode(0);
		cn = 0;
		if (!k1 && !k2 && !k3 && !k4 && !k5 && !k6 && !k7 && !k8)
		{
			result = calculate('\0');
			ans = *result;
			sprintf(final, "%.*f", ac, *result);
			MovePen(3.2 - TextStringWidth(final), 0.8 * cy);
			if (!flag4)
				DrawTextString(final);
			cancelTimer(TIMER_BLINK500);
		}
		else if (k1 && !k2 && !k3 && !k4 && !k5 && !k6 && !k7 && !k8)
		{
			result = calculate('\0');
			ans = *result;
			ac = ans;
			cancelTimer(TIMER_BLINK500);
			MovePen(ox, oy);
			SetEraseMode(1);
			DrawLine(0, 0.13);
			SetEraseMode(1);
			MovePen(oox - TextStringWidth("����nλС��:"), oy);
			DrawTextString("����nλС��:");
			sprintf(final, "%.*f", ac, *result);
			DrawTextSS(index, textlen - iindex);
			SetEraseMode(0);
			cn = 0;
			n = 0;
			ox = 0.4;
			ans = 0;
			oox = 0.4;
			startTimer(TIMER_BLINK500, mseconds500);
			klen = 0;
			textlen = 0;
			memset(text, '\0', sizeof(text));
			memset(final, '\0', sizeof(final));
			k1 = !k1;
		}
		else if (!k1 && k2 && !k3 && !k4 && !k5 && !k6 && !k7 && !k8)
		{
			cancelTimer(TIMER_BLINK500);
			cn = 0;
			x = calculate(',');
			y = calculate('\0');
			cn = 0;
			x = calculate(',');
			*x = *x * 1.000000001;
			yy = calculate('\0');
			*result = (*yy - *y) / (*x - *x / 1.000000001);
			sprintf(final, "%.*f", ac, *result);
			MovePen(3.2 - TextStringWidth(final), 0.8 * cy);
			if (!flag4)
				DrawTextString(final);
		}
		else if (!k1 && !k2 && k3 && !k4 && !k5 && !k6 && !k7 && !k8)
		{
			cancelTimer(TIMER_BLINK500);
			cn = 0;
			xo = calculate(',');
			xf = calculate(',');
			lenth = *xf - *xo;
			for (i = 1; i <= 20000; i++)
			{
				cn = 0;
				x = calculate(',');
				x = calculate(',');
				*x = *xo + lenth * (double)(i - 0.5) / 20000.0;
				y = calculate('\0');
				*sum += *y * lenth / 20000.0;
			}
			sprintf(final, "%.*f", ac, *sum);
			MovePen(3.2 - TextStringWidth(final), 0.8 * cy);
			if (!flag4)
				DrawTextString(final);
		}
		else if (!k1 && !k2 && !k3 && k4 && !k5 && !k6 && !k7 && !k8)
		{
			result = calculate('\0');
			Clear();
			MovePen(oox, ooy);
			if (*result == 1)
			{
				startTimer(TIMER_BLINK500, mseconds500);
				k4 = FALSE;
			}
			else if (*result == 2)
			{
				DrawTextString("���̴���(1-3):");
				ox += TextStringWidth("���̴���(1-3):");
				oox += TextStringWidth("���̴���(1-3):");
				alinput = TextStringWidth("���̴���(1-3):");
				startTimer(TIMER_BLINK500, mseconds500);
				k5 = TRUE;
				k4 = FALSE;
			}
			else if (*result == 3)
			{
				DrawTextString("[a,b],f(x):");
				ox += TextStringWidth("[a,b],f(x):");
				oox += TextStringWidth("[a,b],f(x):");
				alinput = TextStringWidth("[a,b],f(x):");
				startTimer(TIMER_BLINK500, mseconds500);
				k7 = TRUE;
				k4 = FALSE;
			}
			else
			{
				error();
			}
		}
		else if (!k1 && !k2 && !k3 && !k4 && k5 && !k6 && !k7 && !k8)
		{
			result = calculate('\0');
			Clear();
			MovePen(oox, ooy);
			if (*result == 1)
			{
				Clear();
				MovePen(oox, oy);
				DrawTextString("ax+b=0 a,b:");
				ox += TextStringWidth("ax+b=0 a,b:");
				oox += TextStringWidth("ax+b=0 a,b:");
				alinput = TextStringWidth("ax+b=0 a,b:");
				startTimer(TIMER_BLINK500, mseconds500);
				k6 = 1;
				k5 = FALSE;
			}
			if (*result == 2)
			{
				Clear();
				MovePen(oox, oy);
				DrawTextString("ax^2+bx+c=0 a,b,c:");
				ox += TextStringWidth("ax^2+bx+c=0 a,b,c:");
				oox += TextStringWidth("ax^2+bx+c=0: a,b,c");
				alinput = TextStringWidth("ax^2+bx+c=0: a,b,c");
				startTimer(TIMER_BLINK500, mseconds500);
				k6 = 2;
				k5 = FALSE;
			}
			if (*result == 3)
			{
				Clear();
				MovePen(oox, oy);
				DrawTextString("ax^3+bx^2+cx+d=0 a,b,c,d:");
				ox += TextStringWidth("ax^3+bx^2+cx+d=0 a,b,c,d:");
				oox += TextStringWidth("ax^3+bx^2+cx+d=0 a,b,c,d:");
				alinput = TextStringWidth("ax^3+bx^2+cx+d=0 a,b,c,d:");
				startTimer(TIMER_BLINK500, mseconds500);
				k6 = 3;
				k5 = FALSE;
			}
		}
		else if (!k1 && !k2 && !k3 && !k4 && !k5 && k6 && !k7 && !k8)
		{
			if (k6 == 1)
			{
				cancelTimer(TIMER_BLINK500);
				aa = calculate(',');
				bb = calculate('\0');
				eqn1(aa, bb);
				MovePen(3.2 - TextStringWidth(eqnfinal), 0.8 * cy);
				if (!flag4)
					DrawTextString(eqnfinal);
			}
			if (k6 == 2)
			{
				cancelTimer(TIMER_BLINK500);
				aa = calculate(',');
				bb = calculate(',');
				cc = calculate('\0');
				eqn2(aa, bb, cc);
				MovePen(3.2 - TextStringWidth(eqnfinal), 0.8 * cy);
				if (!flag4)
					DrawTextString(eqnfinal);
			}
			if (k6 == 3)
			{
				cancelTimer(TIMER_BLINK500);
				aa = calculate(',');
				bb = calculate(',');
				cc = calculate(',');
				dd = calculate('\0');
				eqn3(aa, bb, cc, dd);
				MovePen(3.2 - TextStringWidth(eqnfinal), 0.8 * cy);
				if (!flag4)
					DrawTextString(eqnfinal);
			}
		}
		else if (!k1 && !k2 && !k3 && !k4 && !k5 && !k6 && k7 && !k8)
		{
			cancelTimer(TIMER_BLINK500);
			cn = 0;
			maxx = 0;
			maxy = 0;
			xo = calculate(',');
			xf = calculate(',');
			lenth = *xf - *xo;
			for (i = 1; i <= 2000; i++)
			{
				cn = 0;
				x = calculate(',');
				x = calculate(',');
				*x = *xo + lenth * (double)(i - 0.5) / 2000.0;
				y = calculate('\0');
				if (*y > maxy)
					maxy = *y;
			}
			maxx = max(fabs(*xo), fabs(*xf));
			ClearFunction();
			flag2 = 1;
		}
		else if (!k1 && !k2 && !k3 && !k4 && !k5 && !k6 && !k7 && k8)
		{
			cancelTimer(TIMER_BLINK500);
			cn = 0;
			xo = calculate(',');
			xf = calculate(',');
			lenth = *xf - *xo;
			for (i = *xo; i <= *xf; i++)
			{
				cn = 0;
				x = calculate(',');
				x = calculate(',');
				*x = i;
				y = calculate('\0');
				*sum += *y;
			}
			sprintf(final, "%.*f", ac, *sum);
			MovePen(3.2 - TextStringWidth(final), 0.8 * cy);
			if (!flag4)
				DrawTextString(final);
		}
		break;
	case '\r':
		break;
	case 27:
		break;
	case 'u':
		c = '.'; // to prevent del's effect
		goto jump;
	case '\b':
		break;
	case 'z':
		restore();
		if (n == textlen)
			break;
		n++;
		MovePen(ox, oy);
		SetEraseMode(1);
		DrawLine(0, 0.13);
		DrawTextS(index, textlen - iindex);
		ox = ox + (TextStringWidth(text + klen) - TextStringWidth(text + (klen--) - 1));
		FullLeft();
		Flash();
		MovePen(ox, oy);
		startTimer(TIMER_BLINK500, mseconds500);
		break;
	case 'v':
		restore();
		if (n == 0)
			break;
		if (n-- <= 0)
			break;
		MovePen(ox, oy);
		SetEraseMode(1);
		DrawLine(0, 0.13);
		DrawTextS(index, textlen - iindex);
		ox = ox + (TextStringWidth(text + klen++) - TextStringWidth(text + klen));
		FullRight();
		Flash();
		MovePen(ox, oy);
		startTimer(TIMER_BLINK500, mseconds500);
		break;
	case '#':
		restore();
		if (klen == 0)
			break;
		MovePen(ox, oy);
		SetEraseMode(1);
		DrawLine(0, 0.13);
		DrawTextSS(index, textlen - iindex);
		ox += (TextStringWidth(text + klen) - TextStringWidth(text + (klen--) - 1));
		SetEraseMode(0);
		textlen--;
		if (klen < textlen)
		{
			for (i = klen + 1; i <= textlen; i++)
			{
				temp = text[i];
				text[i - 1] = temp;
			}
			text[textlen] = '\0';
		}
		if (klen == textlen)
		{
			text[textlen] = '\0';
		}
		if (!index)
		{
			if (iindex && !index)
				iindex--;
			DrawTextS(index, textlen - iindex);
			MovePen(ox, oy);
		}
		else
		{
			if (index >= 1)
				index--;
			if (iindex && !index)
				iindex--;
			DrawTextS(index, textlen - iindex);
			ox = oox + TextStringWidth(text + index) - TextStringWidth(text + klen);
		}
		Flash();
		startTimer(TIMER_BLINK500, mseconds500);
		break;
	jump:;
	default:
		restore();
		str[0] = c;
		flagp = 0;
		SetEraseMode(1);
		DrawTextSS(index, textlen - iindex);
		if (klen < textlen)
		{
			for (i = textlen; i > klen; i--)
			{
				temp = text[i - 1];
				text[i] = temp;
			}
			text[++textlen] = '\0';
			text[klen] = c;
		}
		if (klen == textlen)
		{
			text[textlen++] = c;
			text[textlen] = '\0';
			flagp = 1;
			goto next;
		}
		SetEraseMode(0);
	next:;
		if (klen < textlen && iindex)
			iindex++;
		DrawTextS(index, textlen - iindex);
		if (flagp)
			goto next1;
		MovePen(ox - TextStringWidth(text + klen + 1) + TextStringWidth(text + klen), oy);
	next1:;
		ox = GetCurrentX();
		oy = GetCurrentY();
		if (flagp)
			klen = textlen;
		else
			klen++;
		if (TextStringWidth(text) >= 2.8 - alinput && !iindex)
		{
			SetEraseMode(1);
			DrawTextSS(index, textlen - iindex);
			index = 0;
			while (TextStringWidth(text + index++) >= 2.9 - alinput)
				;
			DrawTextS(index, textlen - iindex);
			ox = oox + TextStringWidth(text + index) - TextStringWidth(text + klen);
		}
		Flash();
		startTimer(TIMER_BLINK500, mseconds500);
		break;
	}
}

void CharEventProcess(char c)
{
	registerTimerEvent(TimerEventProcess);
	int i, flagg = 0;
	char temp;
	double *result;
	result = New(double *);
	MovePen(ox, oy);
	SetEraseMode(1);
	DrawLine(0, 0.13);
	SetEraseMode(0);
	switch (c)
	{
	case '\r':
		break;
	case '\b':
		break;
	default:
		restore();
		str[0] = c;
		flagg = 0;
		SetEraseMode(1);
		DrawTextSS(index, textlen - iindex);
		if (klen < textlen)
		{
			for (i = textlen; i > klen; i--)
			{
				temp = text[i - 1];
				text[i] = temp;
			}
			text[++textlen] = '\0';
			text[klen] = c;
		}
		if (klen == textlen)
		{
			text[textlen++] = c;
			text[textlen] = '\0';
			flagg = 1;
			goto next;
		}
		SetEraseMode(0);
	next:;
		if (klen < textlen && iindex)
			iindex++;
		DrawTextS(index, textlen - iindex);
		if (flagg)
			goto next1;
		MovePen(ox - TextStringWidth(text + klen + 1) + TextStringWidth(text + klen), oy);
	next1:;
		ox = GetCurrentX();
		oy = GetCurrentY();
		if (flagg)
			klen = textlen;
		else
			klen++;
		if (TextStringWidth(text) >= 2.8 - alinput && !iindex)
		{
			SetEraseMode(1);
			DrawTextSS(index, textlen - iindex);
			index = 0;
			while (TextStringWidth(text + index++) >= 2.9 - alinput)
				;
			DrawTextS(index, textlen - iindex);
			ox = oox + TextStringWidth(text + index) - TextStringWidth(text + klen);
		}
		Flash();
		startTimer(TIMER_BLINK500, mseconds500);
		break;
	}
}

void TimerEventProcess(int timerID)
{
	//      bool erasemode;
	DrawTextSS(index, textlen - iindex);
	switch (timerID)
	{
	case TIMER_BLINK500:
		//	        erasemode = GetEraseMode();
		MovePen(ox, oy);
		SetEraseMode(!isDisplay);
		DrawLine(0, 0.13);
		SetEraseMode(0);
		DrawTextS(index, textlen - iindex);
		isDisplay = !isDisplay;
		break;
	default:
		break;
	}
}
