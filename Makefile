NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c utils.c ops_raw.c ops.c pars.c algo.c bench.c \
       ft_printf/ft_printf.c \
       ft_printf/ft_printf_char.c \
       ft_printf/ft_printf_hex.c \
       ft_printf/ft_printf_number.c \
       ft_printf/ft_printf_pointer.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h ft_printf/ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
