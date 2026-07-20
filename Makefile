NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

SRCS        = main.c \
              push_swap.c \
              normalize.c \
              sort_small.c \
              sort_radix.c \
              stack_utils.c \
              stack_utils2.c \
              parse_utils.c \
              ops_push.c \
              ops_swap.c \
              ops_rotate.c \
              ops_rev_rotate.c \
              ft_split.c \
              parse.c \
              init.c

OBJS        = $(SRCS:.c=.o)

HEADER      = push_swap.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re