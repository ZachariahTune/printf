#include "ft_printf.h"

void	ft_pf_putdbl_flags_with_inf(t_flags flags, size_t *len)
{
	int		if_sign;

	if_sign = 0;
	if (flags.sign > 0)
		if_sign = 1;
	if (flags.minus == 0)
	{
		ft_pf_putwidth(flags.width, (3 + if_sign), 0, len);
	}
	if (flags.sign > 0)
		ft_pf_putchar(flags.sign, len);
	ft_pf_putstr("inf", len);
	if (flags.minus == 1)
	{
		ft_pf_putwidth(flags.width, (3 + if_sign), 0, len);
	}
}

void	ft_pf_putdbl_flags_with_minus_inf(t_flags flags, size_t *len)
{
	if (flags.minus == 0)
	{
		ft_pf_putwidth(flags.width, 4, 0, len);
	}
	ft_pf_putstr("-inf", len);
	if (flags.minus == 1)
	{
		ft_pf_putwidth(flags.width, 4, 0, len);
	}
}

void	ft_pf_putdbl_flags_with_nan(t_flags flags, size_t *len)
{
	if (flags.minus == 0)
	{
		ft_pf_putwidth(flags.width, 3, 0, len);
	}
	ft_pf_putstr("nan", len);
	if (flags.minus == 1)
	{
		ft_pf_putwidth(flags.width, 3, 0, len);
	}
}

void	ft_pf_putdbl_flags_with_0(double n, t_flags flags, size_t *len)
{
	size_t	dbllen;
	int		if_sign;
	int		if_sharp;

	if_sign = 0;
	if_sharp = 0;
	if (n < 0)
	{
		n = -n;
		flags.sign = '-';
	}
	if (flags.sign > 0)
		if_sign = 1;
	if (flags.sharp == 1 && flags.dot == 0)
		if_sharp = 1;
	dbllen = ft_dbllen(n, flags.dot);
	if (flags.sign > 0)
		ft_pf_putchar(flags.sign, len);
	ft_pf_putwidth(flags.width, (dbllen + if_sign + if_sharp), 1, len);
	ft_pf_putdbl(n, flags, len);
	if (flags.sharp == 1 && flags.dot == 0)
		ft_pf_putchar('.', len);
}

void	ft_pf_putdbl_flags_without_0(double n, t_flags flags, size_t *len)
{
	size_t	dbllen;
	int		if_sign;
	int		if_sharp;

	if_sign = 0;
	if_sharp = 0;
	if (n < 0)
	{
		n = -n;
		flags.sign = '-';
	}
	if (flags.sign > 0)
		if_sign = 1;
	if (flags.sharp == 1 && flags.dot == 0)
		if_sharp = 1;
	dbllen = ft_dbllen(n, flags.dot);
	if (flags.minus == 0)
		ft_pf_putwidth(flags.width, (dbllen + if_sign + if_sharp), 0, len);
	if (flags.sign > 0)
		ft_pf_putchar(flags.sign, len);
	ft_pf_putdbl(n, flags, len);
	if (flags.sharp == 1 && flags.dot == 0)
		ft_pf_putchar('.', len);
	if (flags.minus == 1)
		ft_pf_putwidth(flags.width, (dbllen + if_sign + if_sharp), 0, len);
}
