#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <math.h>
# define HEX_SYM_B "0123456789ABCDEF"
# define HEX_SYM_S "0123456789abcdef"

typedef struct s_flags
{
	int		minus;
	int		zero;
	int		width;
	int		star;
	int		dot;
	int		type;
	int		lenl;
	int		lenll;
	int		lenh;
	int		lenhh;
	int		sharp;
	int		sign;
}			t_flags;

int		ft_isdigit(int c);
int		ft_ispftypes(int c);
int		ft_ispfflags(int c);
int		ft_ispflentypes(int c);
int		ft_iseven(long n);
size_t	ft_strlen(const char *str);
size_t	ft_unsignlen(unsigned long nbr);
size_t	ft_intlen(long nbr);
size_t	ft_convlen(unsigned long nbr, size_t base);
size_t	ft_dbllen(double nbr, size_t signs);
void	ft_pf_otherflag(int c, t_flags *flags);
void	ft_pf_starflag(t_flags *flags, va_list args);
int		ft_pf_dotflag(const char *string, t_flags *flags, va_list args);
void	ft_pf_widthflag(int c, t_flags *flags);
void	ft_pf_lenflag(int c, t_flags *flags);
void	ft_pf_putchar(int c, size_t *len);
void	ft_pf_putchar_flags(int c, t_flags flags, size_t *len);
void	ft_pf_putstr(char *str, size_t *len);
void	ft_pf_putstr_flags(char *str, t_flags flags, size_t *len);
void	ft_pf_putnbr(long n, size_t *len);
void	ft_pf_putnbr_flags(long n, t_flags flags, size_t *len);
void	ft_pf_putunbr_flags(unsigned long n, t_flags flags, size_t *len);
void	ft_pf_puthex(unsigned long n, char *alpha, size_t *len);
void	ft_pf_puthex_flags(unsigned long n, t_flags flags,
			char *alpha, size_t *len);
void	ft_pf_putptr_flags(unsigned long addr, t_flags flags, size_t *len);
void	ft_pf_savelen_flags(unsigned long *n, t_flags flags, size_t *len);
double	ft_dblrnd_bank(double nbr, size_t signs);
void	ft_pf_putdbl(double n, t_flags flags, size_t *len);
void	ft_pf_putdbl_flags(double n, t_flags flags, size_t *len);
void	ft_pf_putdbl_flags_with_inf(t_flags flags, size_t *len);
void	ft_pf_putdbl_flags_with_minus_inf(t_flags flags, size_t *len);
void	ft_pf_putdbl_flags_with_nan(t_flags flags, size_t *len);
void	ft_pf_putdbl_flags_with_0(double n, t_flags flags, size_t *len);
void	ft_pf_putdbl_flags_without_0(double n, t_flags flags, size_t *len);
void	ft_pf_putwidth(int width, int length, int zero, size_t *len);
int		ft_printf(const char *string, ...);

#endif