NAME_CLIENT = client
NAME_SERVER = server

SRCS_CLIENT = client.c
SRCS_SERVER = server.c

OBJS_CLIENT = {SRCS_CLIENT:.c=.o}
OBJS_SERVER = {SRCS_SERVER:.c=.o}

CFLAGS = -Wall -Wextra -Werror

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT)
	@gcc $(CFLAGS) -g3 -o $@ $^

$(NAME_SERVER): $(OBJS_SERVER)
	@gcc $(CFLAGS) -o $@ $^

.c.o:	include/minitakl.h
	@gcc ${CFLAGS} -c $< -o $@

clean:
	@$(RM) $(OBJS_CLIENT) $(OBJS_SERVER)

fclean: clean
	@$(RM) $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

.PHONY: clean fclean re all