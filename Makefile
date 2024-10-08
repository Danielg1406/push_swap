NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft

INCLUDES = -I $(LIBFT)

SRCS = $(addsuffix .c, )

OBJS := $(SRCS:%.c=%.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
