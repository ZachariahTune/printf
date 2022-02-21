#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_unsignlen(unsigned long nbr)
{
	size_t	i;

	i = 1;
	while (nbr > 9)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

size_t	ft_intlen(long nbr)
{
	size_t	i;

	i = 1;
	if (nbr < 0)
	{
		nbr = -nbr;
	}
	while (nbr > 9)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

size_t	ft_convlen(unsigned long nbr, size_t base)
{
	size_t	i;

	i = 1;
	while (nbr > (base - 1))
	{
		nbr /= base;
		i++;
	}
	return (i);
}

size_t	ft_dbllen(double nbr, size_t signs)
{
	if (nbr < 0)
	{
		nbr = -nbr;
	}
	nbr = ft_dblrnd_bank(nbr, signs);
	if (signs == 0)
		return (ft_intlen((long)nbr));
	else
		return (ft_intlen((long)nbr) + signs + 1);
}
