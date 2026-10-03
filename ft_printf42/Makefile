CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs

NAME = libftprintf.a

SRCS = ft_printf.c ft_strlen.c ft_putnbr_fd.c ft_putnbrhexup_fd.c ft_putunbr_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_ptr_fd.c ft_putnbrhexlo_fd.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re