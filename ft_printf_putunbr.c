#include "ft_printf.h"

static void	ft_pf_putunbr(unsigned long n, size_t *len)
{
	if (n > 9)
	{
		ft_pf_putnbr(n / 10, len);
		ft_pf_putnbr(n % 10, len);
	}
	else
	{
		ft_pf_putchar(n + '0', len);
	}
}

static void	ft_pf_putunbr_flags_with_0(unsigned long n, t_flags flags,
	size_t *len)
{
	size_t	unsignlen;

	unsignlen = ft_unsignlen(n);
	if (flags.dot < 0 || (flags.dot >= 0 && (size_t)flags.dot < unsignlen))
	{
		flags.dot = unsignlen;
	}
	ft_pf_putwidth(flags.width, flags.dot, 1, len);
	ft_pf_putunbr(n, len);
}

static void	ft_pf_putunbr_flags_without_0(unsigned long n, t_flags flags,
	size_t *len)
{
	size_t	unsignlen;

	unsignlen = ft_unsignlen(n);
	if (flags.dot < 0 || (flags.dot >= 0 && (size_t)flags.dot < unsignlen))
	{
		flags.dot = unsignlen;
	}
	if (flags.minus == 0)
	{
		ft_pf_putwidth(flags.width, flags.dot, 0, len);
	}
	ft_pf_putwidth(flags.dot, unsignlen, 1, len);
	ft_pf_putunbr(n, len);
	if (flags.minus == 1)
	{
		ft_pf_putwidth(flags.width, flags.dot, 0, len);
	}
}

void	ft_pf_putunbr_flags(unsigned long n, t_flags flags, size_t *len)
{
	if (!flags.lenl && !flags.lenll && !flags.lenh && !flags.lenhh)
		n = (unsigned long)(unsigned int)n;
	if (flags.lenh == 1)
		n = (unsigned long)(unsigned short)n;
	if (flags.lenhh == 1)
		n = (unsigned long)(unsigned char)n;
	if (flags.dot >= 0 || flags.minus == 1)
		flags.zero = 0;
	if (n == 0 && flags.dot == 0)
		ft_pf_putwidth(flags.width, 0, 0, len);
	else
	{
		if (flags.zero == 0)
			ft_pf_putunbr_flags_without_0(n, flags, len);
		if (flags.zero == 1)
			ft_pf_putunbr_flags_with_0(n, flags, len);
	}
}
