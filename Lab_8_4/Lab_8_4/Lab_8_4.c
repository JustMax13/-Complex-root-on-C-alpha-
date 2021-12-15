#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

typedef struct Complexnum
{
	double real, imag;
}Complexnum;

Complexnum result();
double fxR();
double fxI();
double ComplexNumberModule();

void main()
{
	int Degree, real, imag;
	char sign,c;
	Complexnum z;

	printf("Натуральна степінь кореня: ");
	scanf("%d", &Degree);

	printf("\n\n");
	printf("*Введіть перше значення =>  пробіл => введіть + або - => пробіл => Введіть перше значення*\n\n\n");
	printf("z = ");
	scanf("%d %c %d%c", &real, &sign, &imag, &c);

	z.real = real;
	if (sign == '+')
	{
		z.imag = imag;
	}
	else
	{
		z.imag = -imag;
	}

	if (z.imag == 0 && z.real)
	{
		printf("\nВідповідь: 0");
		return;
	}
	Complexnum Result[Degree];
	for (int k = 0; k < Degree; k++)
	{
		Result[k] = result(z, k, Degree);
	}
	
	printf("Ось ваші розв'язки: ");
    for (int i = 0; i < Degree; i++)
    {
		z = Result[i];
		double z1 = z.real;
		double z2 = z.imag;
		char ch = '-';
		if (z2 >= 0)
		{
			ch = '+';
		}
		else
		{
			z2 = -z2;
		}
		printf("\nz%d =%lg %c %lgi ", (i+1),z1,ch,z2);
    }
	printf("\n");
}

Complexnum result(Complexnum z, int k, int Degree)
{
	double injection;

	double modz = ComplexNumberModule(z);
	if (z.real >= 0)
	{
		if (z.real != 0)
		{
			if (z.imag >= 0)
			{
				injection = atan(z.imag / z.real);
				z.real = fxR(modz, injection, Degree, k);
				z.imag = fxI(modz, injection, Degree, k);
			}
			else
			{
				injection = 2*M_PI - atan(labs(z.imag / z.real));
				z.real = fxR(modz, injection, Degree, k);
				z.imag = fxI(modz, injection, Degree, k);
			}
		}
		else
		{
			if (z.imag > 0)
			{
				injection = M_PI / 2;
				z.real = fxR(modz, injection, Degree, k);
				z.imag = fxI(modz, injection, Degree, k);
			}
			else
			{
				injection = 3*M_PI / 2;
				z.real = fxR(modz, injection, Degree, k);
				z.imag = fxI(modz, injection, Degree, k);
			}
		}
	}
	else
	{
		if (z.imag >= 0)
		{
			injection = M_PI - atan(labs(z.imag / z.real));
			z.real = fxR(modz, injection, Degree, k);
			z.imag = fxI(modz, injection, Degree, k);
		}
		else
		{
			injection = M_PI + atan(labs(z.imag / z.real));
			z.real = fxR(modz, injection, Degree, k);
			z.imag = fxI(modz, injection, Degree, k);
		}
	}
	return z;
}

double ComplexNumberModule(Complexnum z)
{
	double modz;
	modz = sqrt(pow(z.real,2) + pow(z.imag, 2));
	return modz;
}

double fxR(double modz, double injection, int Degree, int k)
{
	double fxR = pow(modz, 1.0 / Degree) * cos((injection + 2 * M_PI * k) / Degree);
	return fxR;
}

double fxI(double modz, double injection, int Degree, int k)
{
	return pow(modz, 1.0 / Degree) * sin((injection + 2 * M_PI * k) / Degree);
}