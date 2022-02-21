SRCS	=	ft_printf.c ft_printf_flags.c ft_printf_is.c ft_printf_len.c \
			ft_printf_putchar.c ft_printf_putstr.c ft_printf_putnbr.c \
			ft_printf_putunbr.c ft_printf_puthex.c ft_printf_putptr.c \
			ft_printf_putdbl.c ft_printf_putdbl_with.c \
			ft_printf_putwidth.c ft_printf_savelen.c
		
OBJS	=	$(SRCS:.c=.o)

BONUS	=	ft_printf.c ft_printf_flags.c ft_printf_is.c ft_printf_len.c \
			ft_printf_putchar.c ft_printf_putstr.c ft_printf_putnbr.c \
			ft_printf_putunbr.c ft_printf_puthex.c ft_printf_putptr.c \
			ft_printf_putdbl.c ft_printf_putdbl_with.c \
			ft_printf_putwidth.c ft_printf_savelen.c

B_OBJS	=	$(BONUS:.c=.o)

CC		=	gcc
RM 		= 	rm -f
CFLAGS	=	-Wall -Wextra -Werror -I.
NAME	=	libftprintf.a

all: 		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

bonus:		$(OBJS) $(B_OBJS)
			ar rcs $(NAME) $(OBJS) $(B_OBJS)

clean:
			${RM} $(OBJS) $(B_OBJS)

fclean:		clean
			${RM} ${NAME}
			${RM} ./*.out

re:			fclean $(NAME)

.PHONY:		all clean fclean re bonus
