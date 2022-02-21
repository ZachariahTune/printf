#include "ft_printf.h"

void	ft_pf_puthex(unsigned long n, char *alpha, size_t *len)
{
	int		base;
	char	buffer[50];
	char	*ptr;

	base = ft_strlen(alpha);
	ptr = &buffer[49];
	*ptr = '\0';
	if (n == 0)
	{
		ptr--;
		*ptr = '0';
	}
	while (n != 0)
	{
		ptr--;
		*ptr = alpha[n % base];
		n /= base;
	}
	ft_pf_putstr(ptr, len);
}

static void	ft_pf_puthex_flags_with_0(unsigned long n, t_flags flags,
	char *alpha, size_t *len)
{
	size_t	convlen;
	int		if_sharp;

	if_sharp = 0;
	if (n > 0 && flags.sharp == 1)
		if_sharp = 2;
	convlen = ft_convlen(n, ft_strlen(alpha));
	if (flags.dot < 0 || (flags.dot >= 0 && (size_t)flags.dot < convlen))
		flags.dot = convlen;
	if (n > 0 && flags.sharp == 1 && alpha[15] == 'f')
		ft_pf_putstr("0x", len);
	if (n > 0 && flags.sharp == 1 && alpha[15] == 'F')
		ft_pf_putstr("0X", len);
	ft_pf_putwidth(flags.width, (flags.dot + if_sharp), 1, len);
	ft_pf_puthex(n, alpha, len);
}

static void	ft_pf_puthex_flags_without_0(unsigned long n, t_flags flags,
	char *alpha, size_t *len)
{
	size_t	convlen;
	int		if_sharp;

	if_sharp = 0;
	if (n > 0 && flags.sharp == 1)
		if_sharp = 2;
	convlen = ft_convlen(n, ft_strlen(alpha));
	if (flags.dot < 0 || (flags.dot >= 0 && (size_t)flags.dot < convlen))
		flags.dot = convlen;
	if (flags.minus == 0)
		ft_pf_putwidth(flags.width, (flags.dot + if_sharp), 0, len);
	if (n > 0 && flags.sharp == 1 && alpha[15] == 'f')
		ft_pf_putstr("0x", len);
	if (n > 0 && flags.sharp == 1 && alpha[15] == 'F')
		ft_pf_putstr("0X", len);
	ft_pf_putwidth(flags.dot, convlen, 1, len);
	ft_pf_puthex(n, alpha, len);
	if (flags.minus == 1)
		ft_pf_putwidth(flags.width, (flags.dot + if_sharp), 0, len);
}

void	ft_pf_puthex_flags(unsigned long n, t_flags flags,
	char *alpha, size_t *len)
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
			ft_pf_puthex_flags_without_0(n, flags, alpha, len);
		if (flags.zero == 1)
			ft_pf_puthex_flags_with_0(n, flags, alpha, len);
	}
}
