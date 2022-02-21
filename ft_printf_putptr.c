#include "ft_printf.h"

static void	ft_pf_putptr(unsigned long addr, t_flags flags, size_t *len)
{
	if (!addr && flags.dot != 0)
	{
		ft_pf_putstr("0", len);
	}
	if (addr)
	{
		ft_pf_puthex(addr, "0123456789abcdef", len);
	}
}

static void	ft_pf_putptr_flags_with_0(unsigned long addr, t_flags flags,
	size_t *len)
{
	size_t	convlen;

	if (!addr && flags.dot != 0)
		convlen = 1;
	if (!addr && flags.dot == 0)
		convlen = 0;
	if (addr)
	{
		convlen = ft_convlen(addr, 16);
	}
	if (flags.dot < 0 || (flags.dot >= 0 && (size_t)flags.dot < convlen))
	{
		flags.dot = convlen;
	}
	ft_pf_putstr("0x", len);
	ft_pf_putwidth(flags.width, convlen + 2, 1, len);
	ft_pf_putptr(addr, flags, len);
}

static void	ft_pf_putptr_flags_without_0(unsigned long addr, t_flags flags,
	size_t *len)
{
	size_t	convlen;

	if (!addr && flags.dot != 0)
		convlen = 1;
	if (!addr && flags.dot == 0)
		convlen = 0;
	if (addr)
	{
		convlen = ft_convlen(addr, 16);
	}
	if (flags.dot < 0 || (flags.dot >= 0 && (size_t)flags.dot < convlen))
	{
		flags.dot = convlen;
	}
	if (flags.minus == 0)
	{
		ft_pf_putwidth(flags.width, flags.dot + 2, 0, len);
	}
	ft_pf_putstr("0x", len);
	ft_pf_putwidth(flags.dot, convlen, 1, len);
	ft_pf_putptr(addr, flags, len);
	if (flags.minus == 1)
	{
		ft_pf_putwidth(flags.width, flags.dot + 2, 0, len);
	}
}

void	ft_pf_putptr_flags(unsigned long addr, t_flags flags, size_t *len)
{
	if (flags.dot >= 0 || flags.minus == 1)
	{
		flags.zero = 0;
	}
	if (flags.zero == 0)
	{
		ft_pf_putptr_flags_without_0(addr, flags, len);
	}
	if (flags.zero == 1)
	{
		ft_pf_putptr_flags_with_0(addr, flags, len);
	}
}
