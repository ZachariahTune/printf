#include "ft_printf.h"

void	ft_pf_savelen_flags(unsigned long *n, t_flags flags, size_t *len)
{
	if (!flags.lenl && !flags.lenll && !flags.lenh && !flags.lenhh)
		*(unsigned int *)n = *len;
	else if (flags.lenh == 1)
		*(unsigned short *)n = *len;
	else if (flags.lenhh == 1)
		*(unsigned char *)n = *len;
	else
		*n = *len;
}
