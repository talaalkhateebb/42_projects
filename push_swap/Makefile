
NAME = push_swap
SRC = assign_index.c \
	  best_move.c \
	  chunk_size.c \
	  fill_array.c \
	  find_position.c \
	  in_chunk.c \
	  indexing.c \
	  max_index.c \
	  move_to_top.c \
	  operations.c \
	  operation.c \
	  operationn.c \
	  push_back_to_a.c \
	  push_swap.c \
	  push_to_b_chunk.c \
	  sort_3.c \
	  sort_2.c \
	  sort.c \
	  sort_4_5.c \
	  sort_arr.c \
	  stack_size.c \
	  utils.c \
	  util.c \
	  is_sorted.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
