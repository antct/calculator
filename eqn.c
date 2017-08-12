#include "eqn.h"
extern int ac;
extern char eqnfinal[100];
double f(double a, double b, double c, double d, double x)
{
    return (a * x * x * x + b * x * x + c * x + d);
}

double f1(double a, double b, double c, double x)
{
    return (3 * a * x * x + 2 * b * x + c);
}

double resolve(double a, double b, double c, double d)
{
    double x0, x1, e;
    x0 = 1;
    if ((a + b + c + d) == 0)
        return 1;
    if (d == 0)
        return 0;
    e = f(a, b, c, d, x0);
    do
    {
        x1 = x0 - e / f1(a, b, c, x0);
        x0 = x1;
        e = f(a, b, c, d, x0);
    } while (fabs(e) >= 1e-8);
    return x1;
}

void eqn30(double *a, double *b, double *c, double *d)
{
    double m, n;
    double y;
    double t;
    y = resolve(*a, *b, *c, *d);
    if (y != 0)
    {
        n = *d / (-y);
        m = (n - *c) / y;
        t = m * m - 4.0 * *a * n;
        t = fabs(t);
        sprintf("%s%.*f %s%.*f %s%.*f", "x1=", ac, y, "x2=", ac, (-m - sqrt(t)) / (2 * *a), "x3=", ac, (-m + sqrt(t)) / (2 * *a));
    }
    else
    {
        t = *b * *b - 4 * *a * *c;
        t = fabs(t);
        sprintf("%s%.*f %s%.*f %s%.*f", "x1=", ac, y, "x2=", ac, (-*b - sqrt(t)) / (2 * *a), "x3=", ac, (-*b + sqrt(t)) / (2 * *a));
    }
}

void eqn3(double *a, double *b, double *c, double *d)
{
    double a1, a2, a3;
    double m, n;
    double k, l;
    double p, q;
    double x1, x2, x3;
    a1 = *b / *a;
    a2 = *c / *a;
    a3 = *d / *a;
    p = a2 - 1.0 / 3 * a1 * a1;
    q = a3 - a1 * a2 / 3.0 + 2.0 / 27.0 * a1 * a1 * a1;
    k = sqrt(q * q / 4.0 + p * p * p / 27.0);
    l = 27.0 * q * q + 4.0 * p * p * p;
    if (l >= 0)
    {
        if ((q / -2 + k) < 0)
        {
            m = pow((q / 2 - k), 1.0 / 3);
            m = -m;
        }
        else
        {
            m = pow((q / -2 + k), 1.0 / 3);
        }
        if ((q / -2 - k) < 0)
        {
            n = pow((q / 2 + k), 1.0 / 3);
            n = -n;
        }
        else
        {
            n = pow((q / -2 - k), 1.0 / 3);
        }
        if (l < 1e-8)
        {
            if (p < 1e-8 && q < 1e-8)
                sprintf(eqnfinal, "%s%.*f", "x1=x2=x3=", ac, m + n - a1 / 3.0);
            else
            {
                sprintf(eqnfinal, "%s%.*f %s%.*f", "x1=", ac, m + n - a1 / 3.0, "x2=", ac, (m + n) / -2.0 - a1 / 3.0);
            }
        }
        else
        {
            if (((m + n) / -2 - a1 / 3.0) == 0)
            {
                sprintf(eqnfinal, "%s%.*f %s%.*f%c %s%.*f%c", "x1=", ac, m + n - a1 / 3.0, "x2=-", ac, (m - n) / 2 * sqrt(3), 'i', "x3=", ac, (m - n) / 2 * sqrt(3), 'i');
            }
            else
            {
                sprintf(eqnfinal, "%s%.*f %s%.*f%c%.*f%c %s%.*f%c%.*f%c", "x1=", ac, m + n - a1 / 3.0, "x2=", ac, (m + n) / -2 - a1 / 3.0, '-', ac, (m - n) / 2 * sqrt(3), 'i', "x3=", ac, (m + n) / -2 - a1 / 3.0, '+', ac, (m - n) / 2 * sqrt(3), 'i');
            }
        }
    }
    else
    {
        eqn30(a, b, c, d);
    }
}

void eqn1(double *a, double *b)
{
    if (*a == 0 && *b == 0)
        sprintf(eqnfinal, "%s", "��Ϊ����ʵ��");
    else if (*a == 0 && *b != 0)
        sprintf(eqnfinal, "%s", "�޽�");
    else
        sprintf(eqnfinal, "%c%c%.*f", 'x', '=', ac, -1 * *b / *a);
}

void eqn2(double *a, double *b, double *c)
{
    double l;
    l = *b * *b - 4.0 * *a * *c;
    if (l > 0)
    {
        sprintf(eqnfinal, "%s%.*f %s%.*f", "x1=", ac, (-*b - sqrt(l)) / (2.0 * *a), "x2=", ac, (-*b + sqrt(l)) / (2.0 * *a));
    }
    else if (l == 0)
    {
        sprintf(eqnfinal, "%s%.*f", "x1=x2=", ac, (-*b) / (2.0 * *a));
    }
    else
    {
        if (b != 0)
        {
            sprintf(eqnfinal, "%s%.*f%c%.*f%c %s%.*f%c%.*f%c", "x1=", ac, (-*b) / (2.0 * *a), '-', ac, sqrt(-l) / (2.0 * *a), 'i', "x2=", ac, (-*b) / (2.0 * *a), '+', ac, sqrt(-l) / (2.0 * *a), 'i');
        }
        else
        {
            sprintf(eqnfinal, "%s%c%.*f%c %s%.*f%c", "x1=", ac, (-*b) / (2.0 * *a), '-', ac, sqrt(-l) / (2.0 * *a), 'i', "x2=", ac, (-*b) / (2.0 * *a), ac, sqrt(-l) / (2.0 * *a), 'i');
        }
    }
}
