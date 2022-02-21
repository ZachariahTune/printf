#include "ft_printf.h"

int main() 
{
	char		letter = 'K';
	int			number = -1;
	char		lngnum = 92;
	unsigned	unumber = 0;
	char		*string = "mama-myla-ramu\0";
	double		dblnum = 123;
	double		dblnum1 = 1.5;
	double		dblnum2 = 2.5;
	double		dblnum3 = 3.5;
	double		dblnum4 = 4.5;
	double		dblnum5 = -1.5;
	double		dblnum6 = -2.5;
	double		dblnum7 = -3.5;
	double		dblnum8 = -4.5;
	int			len = 10;

	//string = NULL; // For NULL string
	
	ft_printf("Obyazatelnaya chast\n===================\n");
	ft_printf("char = %-3c; number = %10.42d; unsigned = %07u; hex = %0#18.14x; HEX = %#0-12.10X; string = %12.10s; ptr = %10p; ptr_ptr = %16p; double = %#+08.f; percent = %%; lngnum = %hhd; %n",
	letter, number, unumber, unumber, unumber, string, string, &string, dblnum, lngnum, &len);
	ft_printf("len = %i;\n", len);

	printf("char = %-3c; number = %10.42d; unsigned = %07u; hex = %0#18.14x; HEX = %#0-12.10X; string = %12.10s; ptr = %10p; ptr_ptr = %16p; double = %#+08.f; percent = %%; lngnum = %hhd; %n",
	letter, number, unumber, unumber, unumber, string, string, &string, dblnum, lngnum, &len);
	printf("len = %i;\n", len);

	ft_printf("\nBonusnaya chast\n===============\n");
	printf("dbl = %#+ f; rnd = %#+ .0f; <- original\n", dblnum1, dblnum1);
	ft_printf("dbl = %#+ f; rnd = %#+ .0f; <- myprintf\n\n", dblnum1, dblnum1);

	printf("dbl = %f; rnd = %.0f; <- original\n", dblnum2, dblnum2);
	ft_printf("dbl = %f; rnd = %.0f; <- myprintf\n\n", dblnum2, dblnum2);

	printf("dbl = %f; rnd = %.0f; <- original\n", dblnum3, dblnum3);
	ft_printf("dbl = %f; rnd = %.0f; <- myprintf\n\n", dblnum3, dblnum3);

	printf("dbl = %f; rnd = %.0f; <- original\n", dblnum4, dblnum4);
	ft_printf("dbl = %f; rnd = %.0f; <- myprintf\n\n", dblnum4, dblnum4);

	printf("dbl = %# f; rnd = %# .0f; <- original\n", dblnum5, dblnum5);
	ft_printf("dbl = %# f; rnd = %# .0f; <- myprintf\n\n", dblnum5, dblnum5);

	printf("dbl = %f; rnd = %.0f; <- original\n", dblnum6, dblnum6);
	ft_printf("dbl = %f; rnd = %.0f; <- myprintf\n\n", dblnum6, dblnum6);

	printf("dbl = %f; rnd = %.0f; <- original\n", dblnum7, dblnum7);
	ft_printf("dbl = %f; rnd = %.0f; <- myprintf\n\n", dblnum7, dblnum7);

	printf("dbl = %f; rnd = %.0f; <- original\n", dblnum8, dblnum8);
	ft_printf("dbl = %f; rnd = %.0f; <- myprintf\n\n", dblnum8, dblnum8);

    return 0;
}
