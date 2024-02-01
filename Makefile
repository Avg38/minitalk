NAME_CLIENT = client
NAME_SERVER = server
NAME_CLIENT_BONUS = client_bonus
NAME_SERVER_BONUS = server_bonus

SRCS_CLIENT = srcs/client.c libft/ft_utils.c libft/ft_printf1.c libft/ft_printf2.c
SRCS_SERVER = srcs/server.c libft/ft_utils.c libft/ft_printf1.c libft/ft_printf2.c
SRCS_CLIENT_BONUS = srcs/client_bonus.c libft/ft_utils.c libft/ft_printf1.c libft/ft_printf2.c
SRCS_SERVER_BONUS = srcs/server_bonus.c libft/ft_utils.c libft/ft_printf1.c libft/ft_printf2.c

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)
OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT)
	@gcc $(CFLAGS) -g3 -o $@ $^

$(NAME_SERVER): $(OBJS_SERVER)
	@gcc $(CFLAGS) -o $@ $^

$(NAME_CLIENT_BONUS): $(OBJS_CLIENT_BONUS)
	@gcc $(CFLAGS) -g3 -o $@ $^

$(NAME_SERVER_BONUS): $(OBJS_SERVER_BONUS)
	@gcc $(CFLAGS) -o $@ $^

bonus: $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

.c.o:
	@gcc ${CFLAGS} -c $< -o $@

clean:
	@$(RM) $(OBJS_CLIENT) $(OBJS_SERVER) $(OBJS_CLIENT_BONUS) $(OBJS_SERVER_BONUS)

fclean: clean
	@$(RM) $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

re: fclean all

.PHONY: clean fclean re all