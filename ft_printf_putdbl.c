#include "ft_printf.h"

static double	ft_dbldivision10(double n, size_t times)
{
	size_t	i;

	i = 0;
	while (i < times)
	{
		n /= 10;
		i++;
	}
	return (n);
}

double	ft_dblrnd_bank(double nbr, size_t signs)
{
	size_t	i;
	long	nbr_lng;

	i = 0;
	while (i < signs && (nbr - (double)(long)(nbr * 10.0)) < 1)
	{
		nbr *= 10.0;
		i++;
	}
	nbr_lng = (long)(nbr + 0.5);
	if (ft_iseven(nbr_lng) == 0 && (double)nbr_lng == (nbr + 0.5))
		nbr = (double)(nbr_lng - 1);
	else
		nbr = (double)nbr_lng;
	while (i > 0)
	{
		nbr /= 10.0;
		i--;
	}
	return (nbr);
}

static void	ft_pf_putdbl_maxlong(size_t dot, size_t *len)
{
	ft_pf_putstr("9223372036854775808", len);
	if (dot > 0)
	{
		ft_pf_putchar('.', len);
		ft_pf_putwidth(dot, 0, 1, len);
	}
}

void	ft_pf_putdbl(double n, t_flags flags, size_t *len)
{
	int	i;

	if (n >= 9223372036854775296)
		ft_pf_putdbl_maxlong(flags.dot, len);
	else
	{
		n = ft_dblrnd_bank(n, flags.dot);
		ft_pf_putnbr((long)n, len);
		if (flags.dot > 0)
		{
			ft_pf_putchar('.', len);
			n = ft_dblrnd_bank(n - (long)n, flags.dot);
			n += ft_dbldivision10(1.0, flags.dot + 1);
			i = 0;
			while (i < flags.dot)
			{
				n *= 10;
				if ((long)n == 0)
					ft_pf_putchar('0', len);
				i++;
			}
			if ((long)n != 0)
				ft_pf_putnbr((long)n, len);
		}
	}
}

void	ft_pf_putdbl_flags(double n, t_flags flags, size_t *len)
{
	if (flags.minus == 1)
		flags.zero = 0;
	if (flags.dot < 0)
		flags.dot = 6;
	if (n == INFINITY)
		ft_pf_putdbl_flags_with_inf(flags, len);
	else if (n == -INFINITY)
		ft_pf_putdbl_flags_with_minus_inf(flags, len);
	else if (n != n)
		ft_pf_putdbl_flags_with_nan(flags, len);
	else
	{
		if (flags.zero == 0)
			ft_pf_putdbl_flags_without_0(n, flags, len);
		if (flags.zero == 1)
			ft_pf_putdbl_flags_with_0(n, flags, len);
	}
}
