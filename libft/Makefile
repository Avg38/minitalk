SRCS	= ft_utils.c ft_printf1.c ft_printf2.c
OBJS	= $(SRCS:.c=.o)
NAME	= libft.a
CFLAGS	= -Wall -Wextra -Werror
RM	= rm -rf

all:	$(NAME)

$(NAME):	$(OBJS)
		@ar rc $(NAME) $(OBJS)

%.o:	%.c libft.h 
	gcc $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
