SRCS	= ft_utils.c ft_printf1.c ft_printf2.c

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

CFLAGS	= -Wall -Wextra -Werror

RM	= rm -rf


%.o:	%.c libft.h 
	@gcc ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		@ar rc ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} *.o

fclean:		clean
		${RM} ${NAME}

re:		fclean all
