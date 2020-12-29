#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include "locale.h"


double mycos(double x, int k, double e) {
	double x2 = x * x,
		c = 1,
		n = 2,
		f = 2,
		z = -1,
		i = 0;

	while (((x2 / f) >= e) && (i < k)) {
		c = c + z * x2 / f;
		n = n + 2;
		x2 = x2 * x * x;
		f = f * (n - 1) * n;
		z = z * (-1);
		i = i + 1;
	}
	return c;
}

long double f(long double s) //модуль числа
{
	if (s < 0) s = -s;
	return s;
}

long double cotan(long double x, int k, long double e)
{
	long double sin = x, cos = 1, cotan = 0, a = 1;
	int n = 2, i = 0;
	while ((f(cos / sin - cotan) > e) && (i < k))
	{
		cotan = cos / sin;
		a *= -x * x / ((n - 1) * n);
		cos += a;
		sin += a * x / (n + 1);
		n += 2;
		i = i + 1;
	}
	cotan = cos / sin;
	return cotan;
}

void enter(double* x, int* n, double* e)
{
	printf("Введите x \n");
	scanf_s("%lf", x);
	printf("Введите число элементов ряда \n");
	scanf_s("%d", n);
	printf("Введите точность вычислений \n");
	scanf_s("%lf", e);
}

void menu()
{
	double x = 0, e = 0;
	int n = 0;
	int max_op = 0;
	int op;
	long double res = 0, pr1 = 0;
	char men[5][50] = { {"Ввести значения"}, {"cos(x)"}, {"ctg(x)"}, {"sec(x) (не работает)"}, {"Выход"} };
	max_op = 5;
	while (1)
	{
		system("cls");
		for (int i = 0; i < max_op; i++)
		{
			printf("%d. %s \n", i + 1, men[i]);
		}
		scanf_s("%d", &op);
		switch (op)
		{
		case 1:
		{
			enter(&x, &n, &e);
			break;
		}
		case 2:
		{
			res = mycos(x, n, e);
			pr1 = cos(x);
			printf("Эталонное значение cos(%.0lf) %.13lf \n", x, pr1);
			printf("Вычислительная оценка %.13lf \n", res);
			printf("Разница между оценкой и эталонным значением %.13lf \n", fabs(res - pr1));
			system("pause");
			break;
		}
		case 3:
		{
			res = cotan(x, n, e);
			pr1 = cos(x) / sin(x);
			printf("Эталонное значение cos(%.0lf) %.13lf \n", x, pr1);
			printf("Вычислительная оценка %.13lf \n", res);
			printf("Разница между оценкой и эталонным значением %.13f \n", fabs(res - pr1));
			system("pause");
			break;
		}
		case 4:
		{
			break;
		}
		default:
		{
			break;
		}
		}
		if (op == 5)
		{
			break;
		}
	}
}

void main()
{
	setlocale(LC_ALL, "Rus");
	menu();
}
