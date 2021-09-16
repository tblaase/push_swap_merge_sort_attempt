NAME = push_swap

CFILES =	actions/pa.c\
			actions/pb.c\
			actions/ra.c\
			actions/rb.c\
			actions/rr.c\
			actions/rra.c\
			actions/rrb.c\
			actions/rrr.c\
			actions/sa.c\
			actions/sb.c\
			actions/ss.c\
			ft_big_sort_a.c\
			ft_big_sort_b.c\
			ft_find.c\
			ft_free_all.c\
			ft_if_sorted_a.c\
			ft_if_sorted_b.c\
			ft_input_error.c\
			ft_lst_functions.c\
			ft_one_stack_left_a.c\
			ft_one_stack_left_b.c\
			ft_push_smallest.c\
			ft_set_swap.c\
			ft_big_sort.c\
			ft_sort_five.c\
			ft_sort_four.c\
			ft_sort_three.c\
			ft_sort.c\
			push_swap.c\

OBJECTS = $(CFILES:.c=.o)

LIB_PATH = libft/

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: subsystem $(NAME)

subsystem:
	make -C $(LIB_PATH) all

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIB_PATH)libft.a -o $(NAME)

clean:
	make -C $(LIB_PATH) clean
	rm -f $(OBJECTS)

fclean: clean
	make -C $(LIB_PATH) fclean
	rm -f $(NAME)

re: fclean all

call: all clean
	make -C $(LIB_PATH) fclean
