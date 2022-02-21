#include "ft_printf.h"

void	ft_pf_putstr(char *str, size_t *len)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_pf_putchar(str[i], len);
		i++;
	}
}

static void	ft_pf_putlstr(char *str, int l, size_t *len)
{
	int	i;

	i = 0;
	while (str[i] && i < l)
	{
		ft_pf_putchar(str[i], len);
		i++;
	}
}

void	ft_pf_putstr_flags(char *str, t_flags flags, size_t *len)
{
	size_t	strlen;

	if (str == NULL)
		str = "(null)";
	strlen = ft_strlen(str);
	if (flags.dot < 0 || (flags.dot >= 0 && (size_t)flags.dot > strlen))
	{
		flags.dot = strlen;
	}
	if (flags.minus == 0)
	{
		ft_pf_putwidth(flags.width, flags.dot, 0, len);
	}
	ft_pf_putlstr(str, flags.dot, len);
	if (flags.minus == 1)
	{
		ft_pf_putwidth(flags.width, flags.dot, 0, len);
	}
}
