#include "ft_printf.h"

void	ft_pf_putnbr(long n, size_t *len)
{
	if (n < 0)
	{
		if (n == -n)
		{
			ft_pf_putnbr(922337203685477580, len);
			ft_pf_putchar('8', len);
		}
		else
			ft_pf_putnbr(-n, len);
	}
	else if (n > 9)
	{
		ft_pf_putnbr(n / 10, len);
		ft_pf_putnbr(n % 10, len);
	}
	else
	{
		ft_pf_putchar(n + '0', len);
	}
}

static void	ft_pf_putnbr_flags_with_0(long n, t_flags flags, size_t *len)
{
	size_t	intlen;
	int		if_sign;

	if_sign = 0;
	if (n < 0)
		flags.sign = '-';
	if (flags.sign > 0)
		if_sign = 1;
	intlen = ft_intlen(n);
	if (flags.dot < 0 || (flags.dot >= 0 && (size_t)flags.dot < intlen))
		flags.dot = intlen;
	if (flags.sign > 0)
		ft_pf_putchar(flags.sign, len);
	ft_pf_putwidth(flags.width, (flags.dot + if_sign), 1, len);
	ft_pf_putnbr(n, len);
}

static void	ft_pf_putnbr_flags_without_0(long n, t_flags flags, size_t *len)
{
	size_t	intlen;
	int		if_sign;

	if_sign = 0;
	if (n < 0)
		flags.sign = '-';
	if (flags.sign > 0)
		if_sign = 1;
	intlen = ft_intlen(n);
	if (flags.dot < 0 || (flags.dot >= 0 && (size_t)flags.dot < intlen))
		flags.dot = intlen;
	if (flags.minus == 0)
		ft_pf_putwidth(flags.width, (flags.dot + if_sign), 0, len);
	if (flags.sign > 0)
		ft_pf_putchar(flags.sign, len);
	ft_pf_putwidth(flags.dot, intlen, 1, len);
	ft_pf_putnbr(n, len);
	if (flags.minus == 1)
		ft_pf_putwidth(flags.width, (flags.dot + if_sign), 0, len);
}

void	ft_pf_putnbr_flags(long n, t_flags flags, size_t *len)
{
	if (!flags.lenl && !flags.lenll && !flags.lenh && !flags.lenhh)
		n = (long)(int)n;
	if (flags.lenh == 1)
		n = (long)(short)n;
	if (flags.lenhh == 1)
		n = (long)(char)n;
	if (flags.dot >= 0 || flags.minus == 1)
		flags.zero = 0;
	if (n == 0 && flags.dot == 0)
	{
		if (flags.sign > 0)
		{
			ft_pf_putchar(flags.sign, len);
			ft_pf_putwidth(flags.width, 1, 0, len);
		}
		else
			ft_pf_putwidth(flags.width, 0, 0, len);
	}
	else
	{
		if (flags.zero == 0)
			ft_pf_putnbr_flags_without_0(n, flags, len);
		if (flags.zero == 1)
			ft_pf_putnbr_flags_with_0(n, flags, len);
	}
}
