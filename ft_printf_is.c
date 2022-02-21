#include "ft_printf.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

int	ft_ispftypes(int c)
{
	if (c == '%' || c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == 'n' || c == 'f')
	{
		return (1);
	}
	return (0);
}

int	ft_ispfflags(int c)
{
	if (c == '#' || c == '-' || c == '+' || c == ' '
		|| c == '0' || c == '*' || c == '.')
	{
		return (1);
	}
	return (0);
}

int	ft_ispflentypes(int c)
{
	if (c == 'l' || c == 'h')
	{
		return (1);
	}
	return (0);
}

int	ft_iseven(long n)
{
	if (n % 2 == 0)
	{
		return (1);
	}
	return (0);
}
