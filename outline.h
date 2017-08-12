#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "graphics.h"
#include "genlib.h"
#include "conio.h"
#include <windows.h>
#include <olectl.h>
#include <stdio.h>
#include <mmsystem.h>
#include <wingdi.h>
#include <ole2.h>
#include <ocidl.h>
#include <string.h>
#include <winuser.h>

void DrawOutline(void)
{
	double cx, cy;
	string s;
	char a[20] = {'0', '\0', '1', '\0', '2', '\0', '3', '\0', '4', '\0', '5', '\0', '6', '\0', '7', '\0', '8', '\0', '9', '\0'};
	cx = GetWindowWidth();
	cy = GetWindowHeight();
	MovePen(0.3, 0.75 * cy);
	DrawLine(3.0, 0.0);
	DrawLine(0.0, 0.2 * cy);
	DrawLine(-3.0, 0.0);
	DrawLine(0.0, -0.2 * cy);
	int i, j;
	SetPenColor("Yellow");
	MovePen(0.3 + 4 * 0.62, (0.14 + 0.21) * cy + 0.03);
	DrawTextString("��");
	MovePen(0.3 + 4 * 0.62 + 0.15, (0.14 + 0.21) * cy + 0.03);
	DrawTextString("��");
	MovePen(0.3 + 4 * 0.62 + 0.3, (0.14 + 0.21) * cy + 0.03);
	DrawTextString("��");
	MovePen(0.3 + 4 * 0.62 + 0.37, (0.14 + 0.21) * cy + 0.03);
	DrawTextString("��");
	MovePen(0.3 + 4 * 0.62, (0.14 + 0.21) * cy + 0.12);
	DrawTextString("��");
	MovePen(0.3 + 4 * 0.62 + 0.15, (0.14 + 0.21) * cy + 0.12);
	DrawTextString("��");
	MovePen(0.3 + 4 * 0.62 + 0.3, (0.14 + 0.21) * cy + 0.12);
	DrawTextString("��");
	MovePen(0.3 + 4 * 0.62 + 0.37, (0.14 + 0.21) * cy + 0.12);
	DrawTextString("��");
	MovePen(0.3 + 3 * 0.62, (0.14 + 0.21) * cy + 0.03);
	DrawTextString("��");
	MovePen(0.3 + 3 * 0.62 + 0.15, (0.14 + 0.21) * cy + 0.03);
	DrawTextString("��");
	MovePen(0.3 + 3 * 0.62 + 0.3, (0.14 + 0.21) * cy + 0.03);
	DrawTextString("��");
	MovePen(0.3 + 3 * 0.62 + 0.37, (0.14 + 0.21) * cy + 0.03);
	DrawTextString("��");
	MovePen(0.3 + 3 * 0.62, (0.14 + 0.21) * cy + 0.12);
	DrawTextString("��");
	MovePen(0.3 + 3 * 0.62 + 0.15, (0.14 + 0.21) * cy + 0.12);
	DrawTextString("��");
	MovePen(0.3 + 3 * 0.62 + 0.3, (0.14 + 0.21) * cy + 0.12);
	DrawTextString("��");
	MovePen(0.3 + 3 * 0.62 + 0.37, (0.14 + 0.21) * cy + 0.12);
	DrawTextString("��");
	/*SetPenColor("Light Gray");
	for(i=1;i<=4;i++){
		for(j=1;j<=6;j++){
		MovePen(0.3+(j-1)*0.52,0.42*cy+0.03+(i-1)*0.36);
		DrawTextString("��");
		MovePen(0.3+(j-1)*0.52+0.12,0.42*cy+0.03+(i-1)*0.36);
		DrawTextString("��");
		MovePen(0.3+(j-1)*0.52+0.245,0.42*cy+0.03+(i-1)*0.36);
		DrawTextString("��");
		MovePen(0.3+(j-1)*0.52,0.42*cy+0.08+(i-1)*0.36);
		DrawTextString("��");
		MovePen(0.3+(j-1)*0.52+0.12,0.42*cy+0.08+(i-1)*0.36);
		DrawTextString("��");
		MovePen(0.3+(j-1)*0.52+0.245,0.42*cy+0.08+(i-1)*0.36);
		DrawTextString("��");
		}
	}
	SetPenSize(2);
    for(i=1;i<=30;i++){
    	MovePen(3.3-0.005*i+0.002,0.7*cy);
	    DrawArc(0.15-0.005*i,0.0,360.0);	
	    MovePen(3.3-0.575-0.005*i+0.005,0.7*cy);
	    DrawArc(0.15-0.005*i,0.0,360.0);
	    MovePen(0.3+0.3-0.005*i+0.005,0.7*cy);
	    DrawArc(0.15-0.005*i,0.0,360.0);
	    MovePen(0.3+0.875-0.005*i+0.002,0.7*cy);
	    DrawArc(0.15-0.005*i,0.0,360.0);
	}
	SetPenSize(1);
	for(i=1;i<=30;i++){
		MovePen(1.7-0.2598/30.0*i,0.7*cy);
		DrawLine(0.0,(1.7-0.2598/30.0*i-1.7+0.2598)/sqrt(3));
		DrawLine(-(1.7-0.2598/30.0*i-1.7+0.2598),-(1.7-0.2598/30.0*i-1.7+0.2598)/sqrt(3));
		DrawLine((1.7-0.2598/30.0*i-1.7+0.2598),-(1.7-0.2598/30.0*i-1.7+0.2598)/sqrt(3));
		DrawLine(0.0,(1.7-0.2598/30.0*i-1.7+0.2598)/sqrt(3));
		MovePen(1.9+0.2598/30.0*i,0.7*cy);
		DrawLine(0.0,(1.9+0.2598-1.9-0.2598/30.0*i)/sqrt(3));
		DrawLine((1.9+0.2598-1.9-0.2598/30.0*i),-(1.9+0.2598-1.9-0.2598/30.0*i)/sqrt(3));
		DrawLine(-(1.9+0.2598-1.9-0.2598/30.0*i),-(1.9+0.2598-1.9-0.2598/30.0*i)/sqrt(3));
		DrawLine(0.0,(1.9+0.2598-1.9-0.2598/30.0*i)/sqrt(3));
    }*/
	SetPenColor("Black");
	MovePen(3.3, 0.7 * cy);
	DrawArc(0.15, 0.0, 360.0);
	MovePen(3.3 - 0.222, 0.7 * cy - 0.03);
	s = GetFont();
	SetFont("����");
	DrawTextString("ON");
	MovePen(3.3 - 0.575, 0.7 * cy);
	DrawArc(0.15, 0.0, 360.0);
	MovePen(3.3 - 0.285 - 0.575, 0.7 * cy - 0.03);
	DrawTextString("HELP");
	MovePen(0.3 + 0.3, 0.7 * cy);
	DrawArc(0.15, 0.0, 360.0);
	MovePen(0.3 + 0.3 - 0.285, 0.7 * cy - 0.03);
	DrawTextString("MODE");
	MovePen(0.3 + 0.875, 0.7 * cy);
	DrawArc(0.15, 0.0, 360.0);
	MovePen(0.3 + 0.875 - 0.255, 0.7 * cy - 0.03);
	DrawTextString("SCI");
	MovePen(1.7, 0.7 * cy - 0.15);
	DrawLine(0.0, 0.3);
	DrawLine(-0.2598, -0.15);
	DrawLine(0.2598, -0.15);
	MovePen(1.9, 0.7 * cy - 0.15);
	DrawLine(0.0, 0.3);
	DrawLine(0.2598, -0.15);
	DrawLine(-0.2598, -0.15);
	for (i = 1; i <= 4; i++)
	{
		for (j = 1; j <= 6; j++)
		{
			MovePen(0.3 + (j - 1) * 0.52, (0.6 - 0.06 * (i - 1)) * cy);
			DrawLine(0.4, 0.0);
			DrawLine(0.0, 0.22);
			DrawLine(-0.4, 0.0);
			DrawLine(0.0, -0.22);
		}
	}
	for (i = 1; i <= 4; i++)
	{
		for (j = 1; j <= 5; j++)
		{
			MovePen(0.3 + (j - 1) * 0.62, (0.35 - 0.07 * (i - 1)) * cy);
			DrawLine(0.52, 0.0);
			DrawLine(0.0, 0.25);
			DrawLine(-0.52, 0.0);
			DrawLine(0.0, -0.25);
		}
	}
	for (i = 2; i <= 4; i++)
	{
		for (j = 1; j <= 3; j++)
		{
			MovePen(0.3 + (j - 1) * 0.62 + 0.25, (0.14 + (i - 1) * 0.07) * cy + 0.08);
			DrawTextString(a + 2 * j + (i - 2) * 6);
		}
	}
	MovePen(0.3, 0.08 * cy);
	MovePen(0.3 + 3 * 0.62 + 0.25, (0.14 + 0.07) * cy + 0.08);
	DrawTextString("+");
	MovePen(0.3 + 4 * 0.62 + 0.25, (0.14 + 0.07) * cy + 0.08);
	DrawTextString("-");
	MovePen(0.3 + 3 * 0.62 + 0.25, (0.14 + 0.14) * cy + 0.08);
	DrawTextString("*");
	MovePen(0.3 + 0 * 0.62 + 0.25, (0.14) * cy + 0.08);
	DrawTextString("0");
	MovePen(0.3 + 1 * 0.62 + 0.25, (0.14) * cy + 0.11);
	DrawTextString(".");
	MovePen(0.3 + 2 * 0.62 + 0.25, (0.14) * cy + 0.08);
	DrawTextString(",");
	MovePen(0.3 + 4 * 0.62 + 0.25, (0.14 + 0.14) * cy + 0.08);
	DrawTextString("\\");
	MovePen(0.3 + 3 * 0.62 + 0.18, (0.14 + 0.21) * cy + 0.08);
	DrawTextString("DEL");
	MovePen(0.3 + 4 * 0.62 + 0.20, (0.14 + 0.21) * cy + 0.08);
	DrawTextString("AC");
	MovePen(0.3 + 3 * 0.62 + 0.17, (0.14) * cy + 0.08);
	DrawTextString("ANS");
	MovePen(0.3 + 4 * 0.62 + 0.25, (0.14) * cy + 0.08);
	DrawTextString("=");
	MovePen(0.3 + 0.18, 0.6 * cy + 0.06);
	DrawTextString("e");
	MovePen(0.3 + 0.52 + 0.18, 0.6 * cy + 0.06);
	DrawTextString("x");
	MovePen(0.3 + 0.52 * 2 + 0.17, 0.6 * cy + 0.06);
	DrawTextString("x!");
	MovePen(0.3 + 0.52 * 3 + 0.04, 0.6 * cy + 0.155);
	DrawLine(0.09, 0);
	MovePen(0.3 + 0.52 * 3 + 0.04, 0.6 * cy + 0.155);
	DrawLine(0.045, -0.045);
	DrawLine(-0.045, -0.045);
	DrawLine(0.09, 0);
	MovePen(0.3 + 0.52 * 3 + 0.13, 0.6 * cy + 0.06);
	DrawTextString("f(x)");
	MovePen(0.3 + 0.52 * 4 + 0.07, 0.6 * cy + 0.06);
	DrawTextString("d/dx");
	MovePen(0.3 + 0.52 * 5 + 0.04, 0.6 * cy + 0.07);
	DrawArc(0.02, 180.0, 120.0);
	MovePen(0.3 + 0.52 * 5 + 0.07, 0.6 * cy + 0.07);
	DrawLine(0, 0.10);
	MovePen(0.3 + 0.52 * 5 + 0.03 + 0.08, 0.6 * cy + 0.06 + 0.09);
	DrawArc(0.02, 0.0, 180.0);
	MovePen(0.3 + 0.52 * 5 + 0.03 + 0.08, 0.6 * cy + 0.06);
	DrawTextString("f(x)");
	MovePen(0.3 + 0.1, 0.54 * cy + 0.06);
	DrawTextString("sin");
	MovePen(0.3 + 0.52 + 0.1, 0.54 * cy + 0.06);
	DrawTextString("cos");
	MovePen(0.3 + 0.52 * 2 + 0.1, 0.54 * cy + 0.06);
	DrawTextString("tan");
	MovePen(0.3 + 0.52 * 3 + 0.07, 0.54 * cy + 0.06);
	DrawTextString("asin");
	MovePen(0.3 + 0.52 * 4 + 0.07, 0.54 * cy + 0.06);
	DrawTextString("acos");
	MovePen(0.3 + 0.52 * 5 + 0.07, 0.54 * cy + 0.06);
	DrawTextString("atan");
	MovePen(0.3 + 0.1, 0.48 * cy + 0.06);
	DrawTextString("log");
	MovePen(0.3 + 0.52 + 0.135, 0.48 * cy + 0.06);
	DrawTextString("ln");
	MovePen(0.3 + 0.52 * 2 + 0.1, 0.48 * cy + 0.06);
	DrawTextString("[x]");
	MovePen(0.3 + 0.52 * 3 + 0.1, 0.48 * cy + 0.06);
	DrawTextString("|x|");
	MovePen(0.3 + 0.52 * 4 + 0.1, 0.48 * cy + 0.06);
	DrawTextString("max");
	MovePen(0.3 + 0.52 * 5 + 0.1, 0.48 * cy + 0.06);
	DrawTextString("min");
	MovePen(0.3 + 0.1, 0.42 * cy + 0.06);
	DrawTextString("x^y");
	MovePen(0.3 + 0.52 + 0.1, 0.42 * cy + 0.06);
	DrawTextString("x%y");
	MovePen(0.3 + 0.52 * 2 + 0.16, 0.42 * cy + 0.06);
	DrawTextString("(");
	MovePen(0.3 + 0.52 * 3 + 0.18, 0.42 * cy + 0.06);
	DrawTextString(")");
	MovePen(0.3 + 0.52 * 4 + 0.135, 0.42 * cy + 0.06);
	DrawTextString("M+");
	MovePen(0.3 + 0.52 * 5 + 0.135, 0.42 * cy + 0.06);
	DrawTextString("MR");
	SetFont(s);
}
