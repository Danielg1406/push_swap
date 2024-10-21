NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

OPERATIONS_DIR = operations
UTILS_DIR = utils
PARSING_DIR = parsing
CHECKER_DIR = checker
SORT_DIR = sorting

HEADER = push_swap.h

SRCS = main.c \
      	$(OPERATIONS_DIR)/push.c \
      	$(OPERATIONS_DIR)/swap.c \
      	$(OPERATIONS_DIR)/rotate.c \
   	$(OPERATIONS_DIR)/reverse_rotate.c \
      	$(UTILS_DIR)/utils.c \
	$(UTILS_DIR)/utils2.c \
       	$(PARSING_DIR)/parsing.c \
	$(PARSING_DIR)/initialize.c \
	$(CHECKER_DIR)/checker.c \
	$(SORT_DIR)/ft_qsort.c \
	$(SORT_DIR)/radix_utils.c \
	$(SORT_DIR)/ft_radixsort.c \
	$(SORT_DIR)/sort_less_five.c


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
