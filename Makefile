SRCS_SERVER = srcs/server.c
SRCS_CLIENT = srcs/client.c
SRCS_SERVER_BONUS = srcs/server_bonus.c
SRCS_CLIENT_BONUS = srcs/client_bonus.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)
OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)

NAME_SERVER = server
NAME_CLIENT = client
NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus

all: libft $(NAME_SERVER) $(NAME_CLIENT)
bonus: libft $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

libft:
	$(MAKE) -C libft

$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) -Iinclude -Ilibft $(OBJS_SERVER) -o $(NAME_SERVER) -Llibft -lft

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) -Iinclude -Ilibft $(OBJS_CLIENT) -o $(NAME_CLIENT) -Llibft -lft

$(NAME_SERVER_BONUS): $(OBJS_SERVER_BONUS)
	$(CC) $(CFLAGS) -Iinclude -Ilibft $(OBJS_SERVER_BONUS) -o $(NAME_SERVER_BONUS) -Llibft -lft

$(NAME_CLIENT_BONUS): $(OBJS_CLIENT_BONUS)
	$(CC) $(CFLAGS) -Iinclude -Ilibft $(OBJS_CLIENT_BONUS) -o $(NAME_CLIENT_BONUS) -Llibft -lft

%.o: %.c include/minitalk.h
	$(CC) $(CFLAGS) -Iinclude -Ilibft -c $< -o $@

clean:
	$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)
	$(RM) $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)
	$(RM) libft/*.o

fclean: clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)
	$(RM) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)
	$(RM) libft/libft.a

re: fclean all

.PHONY: clean fclean re all