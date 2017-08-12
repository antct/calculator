#include "assistance.h"
#include "calculate.h"
#include "graphics.h"
extern int flag;
extern int flag2;
extern int flag3;
extern int flag4;
extern double maxy;
extern double maxx;
extern double lenth;
extern int cn;
extern double *x;
extern double *xo;
extern double *y;
extern double cx, cy;
extern double ox, oy;
extern double oldx;
extern double oldy;
extern double cx, cy;
extern double ox, oy;
extern int index;
extern int iindex;
extern double alinput;
extern char text[100];
extern char final[100];
extern char eqnfinal[100];
extern bool k1;
extern bool k2;
extern bool k3;
extern bool k4;
extern bool k5;
extern int k6;
extern bool k7;
extern bool k8;
extern double oox, ooy;
extern int klen, textlen;
extern double ans;
extern int n;
extern int ac;
extern const int mseconds500;
extern const int mseconds1000;

bool inAarc(double mx, double my, double rx, double ry, double r)
{
	return ((pow(mx - rx, 2.0) + pow(my - ry, 2.0)) <= r * r);
}

bool inState(double mx, double my, double rx, double ry, double a, double b)
{
	return ((mx - rx) >= 0 && (mx - rx) <= a && (my - ry) >= 0 && (my - ry) <= b && flag);
}
void ClearFunction(void)
{
	int i;
	MovePen(0.4, 0.82 * 6.0 - 0.1);
	DrawLine(2.8 + 0.05, 0);
	DrawLine(-0.05, 0.05);
	MovePen(3.2 + 0.05, 0.82 * 6.0 - 0.1);
	DrawLine(-0.05, -0.05);
	MovePen(1.8, 0.77 * 6.0 - 0.1);
	DrawLine(0, 0.1 * 6.0 + 0.05);
	DrawLine(-0.05, -0.05);
	MovePen(1.8, 0.87 * 6.0 + 0.05 - 0.1);
	DrawLine(0.05, -0.05);
	MovePen(1.8 + 0.05, 0.82 * 6.0 + 0.01 - 0.1);
	DrawTextString("0.0");
	MovePen(1.8 + 0.05, 0.87 * 6.0 - 0.04 - 0.1);
	sprintf(final, "%.1f", maxy);
	DrawTextString(final);
	MovePen(1.8 + 0.05, 0.77 * 6.0 - 0.1);
	sprintf(final, "%c%.1f", '-', maxy);
	DrawTextString(final);
	MovePen(3.0, 0.82 * 6.0 + 0.05 - 0.1);
	sprintf(final, "%.1f", maxx);
	DrawTextString(final);
	MovePen(0.4, 0.82 * 6.0 + 0.05 - 0.1);
	sprintf(final, "%c%.1f", '-', maxx);
	DrawTextString(final);
	for (i = 1; i <= 2000; i++)
	{
		cn = 0;
		x = calculate(',');
		x = calculate(',');
		*x = *xo + lenth * (double)(i - 0.5) / 2000.0;
		y = calculate('\0');
		*x = 1.8 + *x / maxx * 1.4;
		*y = 0.82 * 6.0 + *y / maxy * 0.05 * 6.0 - 0.1;
		if (i >= 2)
		{
			MovePen(oldx, oldy);
			DrawLine(*x - oldx, *y - oldy);
		}
		oldx = *x;
		oldy = *y;
	}
	flag2 = !flag2;
}

void Clear(void)
{
	int i;
	oox = 0.4;
	cancelTimer(TIMER_BLINK500);
	MovePen(ox, oy);
	SetEraseMode(1);
	DrawLine(0, 0.13);
	MovePen(0.32, 0.894 * 6.0);
	DrawLine(0.06, 0.03 / sqrt(3));
	DrawLine(0, -2 * 0.03 / sqrt(3));
	DrawLine(-0.06, 0.03 / sqrt(3));
	MovePen(0.32, 0.883 * 6.0);
	DrawLine(0, 2 * 0.037 / sqrt(3));
	DrawLine(0.06, -0.037 / sqrt(3));
	DrawLine(-0.06, -0.037 / sqrt(3));
	MovePen(oox, oy);
	DrawTextSSS(index, textlen - iindex);
	MovePen(oox, oy);
	DrawTextString("����nλС��:");
	DrawTextSSS(index, textlen - iindex);
	MovePen(oox, oy);
	DrawTextString("��");
	MovePen(oox + 0.10, oy);
	DrawTextString("(a,b)f(x)dx:");
	DrawTextSSS(index, textlen - iindex);
	MovePen(oox, oy);
	DrawTextString("df/dx|x=a:");
	DrawTextSSS(index, textlen - iindex);
	MovePen(oox, oy);
	DrawTextString("1:����ģʽ  2:����ģʽ  3:��ͼģʽ:");
	DrawTextSSS(index, textlen - iindex);
	MovePen(oox, oy);
	DrawTextString("���̴���(1-3):");
	DrawTextSSS(index, textlen - iindex);
	MovePen(oox, oy);
	DrawTextString("��");
	MovePen(oox + 0.14, oy);
	DrawTextString("(x=a,b)f(x):");
	DrawTextSSS(index, textlen - iindex);
	MovePen(oox, oy);
	DrawTextString("ax+b=0 a,b:");
	DrawTextSSS(index, textlen - iindex);
	MovePen(oox, oy);
	DrawTextString("ax^2+bx+c=0 a,b,c:");
	DrawTextSSS(index, textlen - iindex);
	MovePen(oox, oy);
	DrawTextString("ax^3+bx^2+cx+d=0 a,b,c,d:");
	DrawTextSSS(index, textlen - iindex);
	MovePen(oox, oy);
	DrawTextString("[a,b],f(x):");
	DrawTextSSS(index, textlen - iindex);
	MovePen(3.2 - TextStringWidth(final), 0.8 * cy);
	DrawTextString(final);
	MovePen(3.2 - TextStringWidth(eqnfinal), 0.8 * cy);
	DrawTextString(eqnfinal);
	if (flag2)
		ClearFunction();
	if (flag4)
	{
		MovePen(oox, oy);
		DrawTextString("Error   AC:Cancel");
		flag4 = 0;
	}
	cn = 0;
	n = 0;
	ac = 2;
	ox = 0.4;
	ans = 0;
	klen = 0;
	textlen = 0;
	oox = 0.4;
	index = iindex = 0;
	alinput = 0;
	memset(text, '\0', sizeof(text));
	memset(final, '\0', sizeof(final));
	memset(eqnfinal, '\0', sizeof(final));
	k1 = k2 = k3 = k4 = k5 = k7 = k8 = FALSE;
	k6 = 0;
	SetEraseMode(0);
	MovePen(0.3, 0.75 * cy);
	DrawLine(3.0, 0.0);
	DrawLine(0.0, 0.2 * cy);
	DrawLine(-3.0, 0.0);
	DrawLine(0.0, -0.2 * cy);
}

void restore(void)
{
	cn = 0;
	SetEraseMode(1);
	MovePen(3.2 - TextStringWidth(final), 0.8 * cy);
	DrawTextString(final);
	MovePen(3.2 - TextStringWidth(eqnfinal), 0.8 * cy);
	DrawTextString(eqnfinal);
	if (flag2)
		ClearFunction();
	SetEraseMode(0);
	startTimer(TIMER_BLINK500, mseconds500);
}

void Flash(void)
{
	if (index != 0)
	{
		SetEraseMode(0);
		MovePen(0.32, 0.894 * 6.0);
		DrawLine(0.06, 0.03 / sqrt(3));
		DrawLine(0, -2 * 0.03 / sqrt(3));
		DrawLine(-0.06, 0.03 / sqrt(3));
	}
	else
	{
		SetEraseMode(1);
		MovePen(0.32, 0.894 * 6.0);
		DrawLine(0.06, 0.03 / sqrt(3));
		DrawLine(0, -2 * 0.03 / sqrt(3));
		DrawLine(-0.06, 0.03 / sqrt(3));
	}
	if (iindex != 0)
	{
		SetEraseMode(0);
		MovePen(0.32, 0.883 * 6.0);
		DrawLine(0, 2 * 0.037 / sqrt(3));
		DrawLine(0.06, -0.037 / sqrt(3));
		DrawLine(-0.06, -0.037 / sqrt(3));
	}
	else
	{
		SetEraseMode(1);
		MovePen(0.32, 0.883 * 6.0);
		DrawLine(0, 2 * 0.037 / sqrt(3));
		DrawLine(0.06, -0.037 / sqrt(3));
		DrawLine(-0.06, -0.037 / sqrt(3));
	}
}

void isFull(void)
{
	if (TextStringWidth(text) >= 2.8 - alinput)
	{
		MovePen(oox, oy);
		SetEraseMode(1);
		DrawTextString(text + index);
		index = 0;
		while (TextStringWidth(text + index++) >= 2.9 - alinput)
			;
		MovePen(oox, oy);
		SetEraseMode(0);
		DrawTextString(text + index);
		ox = oox + TextStringWidth(text + index);
	}
}

void DrawTextS(int a, int b)
{
	SetEraseMode(0);
	MovePen(oox, oy);
	DrawTextString(text + a);
	SetEraseMode(1);
	MovePen(TextStringWidth(text + a) - TextStringWidth(text + b) + oox, oy);
	DrawTextString(text + b);
	SetEraseMode(0);
}

void DrawTextSS(int a, int b)
{
	MovePen(oox, oy);
	DrawTextString(text + a);
	SetEraseMode(1);
	MovePen(TextStringWidth(text + a) - TextStringWidth(text + b) + oox, oy);
	DrawTextString(text + b);
	SetEraseMode(0);
}

void DrawTextSSS(int a, int b)
{
	DrawTextString(text + a);
	SetEraseMode(1);
	MovePen(TextStringWidth(text + a) - TextStringWidth(text + b) + oox, oy);
	DrawTextString(text + b);
}

void FullLeft(void)
{
	if (TextStringWidth(text) >= 2.8 - alinput && (ox >= oox - 0.0001) && (ox <= oox + 0.0001) && index)
	{
		MovePen(oox, oy);
		SetEraseMode(1);
		DrawTextString(text + index);
		if (index >= 1)
		{
			index--;
			iindex++;
		}
		DrawTextS(index, textlen - iindex);
		ox = oox + TextStringWidth(text + index) - TextStringWidth(text + index + 1);
	}
}

void FullRight(void)
{
	if (TextStringWidth(text) >= 2.8 - alinput && (ox >= oox + TextStringWidth(text + index) - TextStringWidth(text + textlen - iindex) - 0.0001) && (ox <= oox + TextStringWidth(text + index) - TextStringWidth(text + textlen - iindex) + 0.0001) && iindex)
	{
		MovePen(oox, oy);
		SetEraseMode(1);
		DrawTextString(text + index);
		if (iindex >= 1)
		{
			index++;
			iindex--;
		}
		DrawTextS(index, textlen - iindex);
		ox = oox + TextStringWidth(text + index) - TextStringWidth(text + textlen - iindex - 1);
	}
}

void error(void)
{
	Clear();
	MovePen(ox, oy);
	DrawTextString("Error   AC:Cancel");
	flag4 = 1;
}
