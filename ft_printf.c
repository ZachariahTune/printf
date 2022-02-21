#include "ft_printf.h"

static t_flags	ft_pf_flags(void)
{
	t_flags	flags;

	flags.minus = 0;
	flags.zero = 0;
	flags.width = 0;
	flags.star = 0;
	flags.dot = -1;
	flags.type = 0;
	flags.lenl = 0;
	flags.lenll = 0;
	flags.lenh = 0;
	flags.lenhh = 0;
	flags.sharp = 0;
	flags.sign = 0;
	return (flags);
}

static int	ft_pf_parser(const char *str, t_flags *flags, va_list args, int i)
{
	while (str[i] && (ft_isdigit(str[i]) || ft_ispftypes(str[i])
			|| ft_ispfflags(str[i]) || ft_ispflentypes(str[i])))
	{
		if (str[i] == '#' || str[i] == '-' || str[i] == '+' || str[i] == ' ')
			ft_pf_otherflag(str[i], flags);
		if (str[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (str[i] == '*')
			ft_pf_starflag(flags, args);
		if (str[i] == '.')
			i += ft_pf_dotflag(&str[i], flags, args);
		if (ft_isdigit(str[i]))
			ft_pf_widthflag(str[i], flags);
		if (ft_ispflentypes(str[i]))
			ft_pf_lenflag(str[i], flags);
		if (ft_ispftypes(str[i]))
		{
			flags->type = str[i];
			break ;
		}
		i++;
	}
	return (i);
}

static void	ft_pf_puts(int c, t_flags *flags, va_list args, size_t *len)
{
	if (c == '%')
		ft_pf_putchar_flags(c, *flags, len);
	else if (c == 'c')
		ft_pf_putchar_flags(va_arg(args, int), *flags, len);
	else if (c == 's')
		ft_pf_putstr_flags(va_arg(args, char *), *flags, len);
	else if (c == 'p')
		ft_pf_putptr_flags(va_arg(args, unsigned long), *flags, len);
	else if (c == 'd' || c == 'i')
		ft_pf_putnbr_flags(va_arg(args, long int), *flags, len);
	else if (c == 'u')
		ft_pf_putunbr_flags(va_arg(args, unsigned long), *flags, len);
	else if (c == 'x')
		ft_pf_puthex_flags(va_arg(args, unsigned long), *flags, HEX_SYM_S, len);
	else if (c == 'X')
		ft_pf_puthex_flags(va_arg(args, unsigned long), *flags, HEX_SYM_B, len);
	else if (c == 'n')
		ft_pf_savelen_flags(va_arg(args, unsigned long *), *flags, len);
	else if (c == 'f')
		ft_pf_putdbl_flags(va_arg(args, double), *flags, len);
}

static int	ft_printf_start(const char *string, va_list args,
	size_t i, size_t len)
{
	t_flags	flags;

	while (string[i])
	{
		flags = ft_pf_flags();
		while (string[i] && string[i] != '%')
		{
			ft_pf_putchar(string[i], &len);
			i++;
		}
		if (string[i] == '%' && string[i + 1])
		{
			i = i + ft_pf_parser(&string[i + 1], &flags, args, 0) + 2;
			ft_pf_puts(flags.type, &flags, args, &len);
		}
		else if (string[i + 1] == '\0')
		{
			i++;
		}
	}
	return (len);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		len;

	va_start(args, string);
	len = ft_printf_start(string, args, 0, 0);
	va_end(args);
	return (len);
}
