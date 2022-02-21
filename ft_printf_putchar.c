#include "ft_printf.h"

void	ft_pf_putchar(int c, size_t *len)
{
	write(1, &c, 1);
	*len += 1;
}

void	ft_pf_putchar_flags(int c, t_flags flags, size_t *len)
{
	if (flags.minus == 0)
	{
		ft_pf_putwidth(flags.width, 1, flags.zero, len);
	}
	ft_pf_putchar(c, len);
	if (flags.minus == 1)
	{
		ft_pf_putwidth(flags.width, 1, flags.zero, len);
	}
}
