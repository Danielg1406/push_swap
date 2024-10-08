NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

OPERATIONS_DIR = operations
UTILS_DIR = utils

HEADER = push_swap.h

# List all source files from the main directory, operations, and utils
SRCS = main.c \
       $(OPERATIONS_DIR)/push.c \
       $(OPERATIONS_DIR)/swap.c \
       $(OPERATIONS_DIR)/rotate.c \
       $(OPERATIONS_DIR)/reverse_rotate.c \
       $(UTILS_DIR)/utils.c

# Generate object files from source files
OBJS = $(SRCS:%.c=%.o)

RM = rm -f

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I $(LIBFT_DIR) -I $(UTILS_DIR) -I . -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
