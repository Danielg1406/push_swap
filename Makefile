NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = $(addsuffix .c, )

OBJS := $(SRCS:%.c=%.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
