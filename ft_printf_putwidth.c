#include "ft_printf.h"

void	ft_pf_putwidth(int width, int length, int zero, size_t *len)
{
	while (width - length > 0)
	{
		if (zero)
		{
			ft_pf_putchar('0', len);
		}
		else
		{
			ft_pf_putchar(' ', len);
		}
		length++;
	}
}
