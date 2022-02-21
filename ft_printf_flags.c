#include "ft_printf.h"

void	ft_pf_otherflag(int c, t_flags *flags)
{
	if (c == '#')
		flags->sharp = 1;
	if (c == '-')
	{
		flags->zero = 0;
		flags->minus = 1;
	}
	if (c == ' ' && flags->sign != '+')
		flags->sign = ' ';
	if (c == '+')
	{
		flags->sign = '+';
	}
}

void	ft_pf_starflag(t_flags *flags, va_list args)
{
	flags->star = 1;
	flags->width = va_arg(args, int);
	if (flags->width < 0)
	{
		flags->minus = 1;
		flags->width *= -1;
		flags->zero = 0;
	}
}

int	ft_pf_dotflag(const char *string, t_flags *flags, va_list args)
{
	int	i;

	i = 1;
	if (string[i] == '*')
	{
		flags->dot = va_arg(args, int);
		i++;
	}
	else
	{
		flags->dot = 0;
		while (ft_isdigit(string[i]))
		{
			flags->dot = flags->dot * 10 + string[i] - '0';
			i++;
		}
	}
	return (i);
}

void	ft_pf_widthflag(int c, t_flags *flags)
{
	if (flags->star == 1)
	{
		flags->width = 0;
	}
	flags->width = flags->width * 10 + c - '0';
}

void	ft_pf_lenflag(int c, t_flags *flags)
{
	if (c == 'l')
	{
		if (flags->lenl == 0)
		{
			flags->lenl = 1;
		}
		else
		{
			flags->lenl = 0;
			flags->lenll = 1;
		}
	}
	if (c == 'h')
	{
		if (flags->lenh == 0)
		{
			flags->lenh = 1;
		}
		else
		{
			flags->lenh = 0;
			flags->lenhh = 1;
		}
	}
}
