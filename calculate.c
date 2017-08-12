#include "calculate.h"
extern double MR;
extern int cn;
extern double *x;
extern double ans;
extern char text[100];

int isnumber(char c)
{
	return (c >= '0' && c <= '9');
}

int isletter(char c)
{
	return (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z');
}

int issymbol(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '(' || c == '=');
}

char *scan(char *k)
{
	char *str;
	char c;
	int n = 0;
	str = New(char *);
	str[n++] = *k;
	while (isletter((c = text[cn++])))
	{
		str[n++] = c;
	}
	if (StringEqual(str, "Ans") || StringEqual(str, "M") || StringEqual(str, "e"))
		cn--;
	str[n] = '\0';
	return str;
}

int trans(char *a)
{
	int b;
	b = *a - '0';
	return b;
}

void process(stackADT stack, char *out)
{
	double *out1, *out2;
	double *newin;
	newin = New(double *);
	out1 = PopStack(stack);
	out2 = PopStack(stack);
	switch (*out)
	{
	case '+':
		*newin = *out1 + *out2;
		break;
	case '-':
		*newin = *out2 - *out1;
		break;
	case '*':
		*newin = *out1 * *out2;
		break;
	case '/':
		*newin = *out2 / *out1;
		if (*out1 == 0)
			error();
		break;
	case '%':
		*newin = (int)*out2 % (int)*out1;
		break;
	case '^':
		*newin = pow(*out2, *out1);
		break;
	default:
		break;
	}
	PushStack1(stack, newin);
}

double fact(double n)
{
	if (n == 1)
		return 1;
	else
		return (n * fact(n - 1));
}
double *calculate(char c)
{
	stackADT stack1, stack2;
	stack1 = NewStack();
	stack2 = NewStack();
	char *in, *ins, *oin, *ooin, *oooin, *inss;
	int n = 1, flag = 1;
	double *ori, *num1, *num2, *num3;
	string s;
	in = New(char *);
	oin = New(char *);
	ooin = New(char *);
	ori = New(double *);
	num1 = New(double *);
	num2 = New(double *);
	*ori = 0;
	PushStack1(stack2, ori);
	*in = text[cn++];
	if (*in == 'x')
	{
		*in = '1';
		*num1 = *x;
		goto mm;
	}
	while (*in != c)
	{
		if (*in == '-' && issymbol(*oin))
		{
			inss = New(char *);
			num3 = New(double *);
			*num3 = -1;
			PushStack1(stack2, num3);
			*inss = '*';
			PushStack2(stack1, inss);
			*in = text[cn++];
		}
		if (*in == '+' && issymbol(*oin))
		{
			inss = New(char *);
			num3 = New(double *);
			*num3 = 1;
			PushStack1(stack2, num3);
			*inss = '*';
			PushStack2(stack1, inss);
			*in = text[cn++];
		}
		*ooin = *oin;
		*oin = *in;
		if (isnumber(*in))
		{
			*num1 = trans(in);
		mm:;
			ins = New(char *);
			*ins = text[cn++];
			while (isnumber(*ins))
			{
				*num1 = *num1 * 10 + trans(ins);
				*ins = text[cn++];
			}
			if (*ins == '.')
			{
				*ins = text[cn++];
				do
				{
					*num1 = *num1 + trans(ins) * pow(0.1, n++);
					*ins = text[cn++];
				} while (isnumber(*ins));
			}
			if (*ins == '!')
			{
				*num1 = fact(*num1);
				*ins = text[cn++];
			}
			PushStack1(stack2, num1);
			*in = *ins;
			goto next;
		}
		else if (isletter(*in) && *in != 'x')
		{
			s = scan(in);
			if (StringEqual(s, "Ans"))
			{
				*num1 = ans;
			}
			else if (StringEqual(s, "M"))
			{
				*num1 = MR;
			}
			else if (StringEqual(s, "e"))
			{
				*num1 = E;
			}
			else if (StringEqual(s, "pow"))
			{
				num1 = calculate(',');
				num2 = calculate('=');
				*num1 = pow(*num1, *num2);
			}
			else if (StringEqual(s, "log"))
			{
				num1 = calculate(',');
				num2 = calculate('=');
				if (*num1 <= 0 || *num1 == 1 || *num2 <= 0)
					error();
				else
					*num1 = log(*num2) / log(*num1);
			}
			else if (StringEqual(s, "lg"))
			{
				num2 = calculate('=');
				*num1 = log10(*num2);
			}
			else if (StringEqual(s, "max"))
			{
				num1 = calculate(',');
				num2 = calculate('=');
				*num1 = fmax(*num1, *num2);
			}
			else if (StringEqual(s, "min"))
			{
				num1 = calculate(',');
				num2 = calculate('=');
				*num1 = fmin(*num1, *num2);
			}
			else if (StringEqual(s, "sin"))
			{
				num1 = calculate('=');
				*num1 = sin(*num1);
			}
			else if (StringEqual(s, "cos"))
			{
				num1 = calculate('=');
				*num1 = cos(*num1);
			}
			else if (StringEqual(s, "tan"))
			{
				num1 = calculate('=');
				*num1 = tan(*num1);
			}
			else if (StringEqual(s, "asin"))
			{
				num1 = calculate('=');
				if (*num1 > 1 || *num1 < -1)
					error();
				else
					*num1 = asin(*num1);
			}
			else if (StringEqual(s, "acos"))
			{
				num1 = calculate('=');
				if (*num1 > 1 || *num1 < -1)
					error();
				else
					*num1 = acos(*num1);
			}
			else if (StringEqual(s, "atan"))
			{
				num1 = calculate('=');
				*num1 = atan(*num1);
			}
			else if (StringEqual(s, "sqrt"))
			{
				num1 = calculate('=');
				if (*num1 < 0)
					error();
				else
					*num1 = sqrt(*num1);
			}
			else if (StringEqual(s, "abs"))
			{
				num1 = calculate('=');
				*num1 = fabs(*num1);
			}
			else if (StringEqual(s, "ln"))
			{
				num1 = calculate('=');
				if (*num1 <= 0)
					error();
				else
					*num1 = log(*num1);
			}
			else if (StringEqual(s, "f"))
			{
				num1 = calculate('=');
				*num1 = floor(*num1);
			}
			else if (StringEqual(s, "exp"))
			{
				num1 = calculate('=');
				*num1 = exp(*num1);
			}
			else
			{
				error();
			}
			PushStack1(stack2, num1);
		}
		else
		{
			switch (*in)
			{
			case '|':
				num1 = calculate('|');
				*num1 = fabs(*num1);
				PushStack1(stack2, num1);
				break;
			case '[':
				num1 = calculate(']');
				*num1 = floor(*num1);
				PushStack1(stack2, num1);
				break;
			case '(':
				PushStack2(stack1, in);
				break;
			case ')':
				if (IsemptyStack(stack1))
					goto next1;
				ins = PopStack(stack1);
				while (*ins != '(')
				{
					process(stack2, ins);
					if (IsemptyStack(stack1))
						goto next1;
					ins = PopStack(stack1);
				}
				break;
			case '+':
				ins = TopStack(stack1);
				if (ins == NULL || *ins == '(')
				{
					PushStack2(stack1, in);
				}
				else
				{
					do
					{
						ins = PopStack(stack1);
						process(stack2, ins);
						ins = TopStack(stack1);
					} while (!IsemptyStack(stack1) && *ins != '(');
					PushStack2(stack1, in);
				}
				break;
			case '-':
				ins = TopStack(stack1);
				if (IsemptyStack(stack1) || *ins == '(')
					PushStack2(stack1, in);
				else
				{
					do
					{
						ins = PopStack(stack1);
						process(stack2, ins);
						ins = TopStack(stack1);
					} while (!IsemptyStack(stack1) && *ins != '(');
					PushStack2(stack1, in);
				}
				break;
			case '*':
				ins = TopStack(stack1);
				if (IsemptyStack(stack1) || *ins != '/' && *ins != '%')
					PushStack2(stack1, in);
				else
				{
					do
					{
						ins = PopStack(stack1);
						process(stack2, ins);
						ins = TopStack(stack1);
					} while (!(IsemptyStack(stack1) || *ins != '/' && *ins != '%'));
					PushStack2(stack1, in);
				}
				break;
			case '/':
				ins = TopStack(stack1);
				if (IsemptyStack(stack1) || *ins != '*' && *ins != '%')
					PushStack2(stack1, in);
				else
				{
					do
					{
						ins = PopStack(stack1);
						process(stack2, ins);
						ins = TopStack(stack1);
					} while (!(IsemptyStack(stack1) || *ins != '*' && *ins != '%'));
					PushStack2(stack1, in);
				}
				break;
			case '%':
				ins = TopStack(stack1);
				if (IsemptyStack(stack1) || *ins != '*' && *ins != '/')
					PushStack2(stack1, in);
				else
				{
					do
					{
						ins = PopStack(stack1);
						process(stack2, ins);
						ins = TopStack(stack1);
					} while (!(IsemptyStack(stack1) || *ins != '*' && *ins != '/'));
					PushStack2(stack1, in);
				}
				break;
			case '^':
				PushStack2(stack1, in);
				break;
			default:
				break;
			}
		}
		if (*in == 'x')
		{
			*in = '1';
			*num1 = *x;
			if (isnumber(*ooin))
			{
				inss = New(char *);
				*inss = '*';
				PushStack2(stack1, inss);
			}
			goto mm;
		}
		*in = text[cn++];
	next:;
	}
	while (!IsemptyStack(stack1))
	{
		ins = PopStack(stack1);
		process(stack2, ins);
	}
next1:;
	return (TopStack(stack2));
}
