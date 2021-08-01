SRC = error.c start_sort.c actions.c sort_few_numbers.c sort_few_numbers_aux.c \
	checks.c sort_many_numbers.c actions2.c
NAME = push_swap.a
HEADER = push_swap.h
OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME):
	@(cd libft/ ; make ; cp libft.a ../$(NAME))
	@clang -g -Wall -Wextra -Werror -c $(SRC)
	@ar rcs $(NAME) $(OBJS)
	@clang -g main.c $(NAME) -o push_swap
clean:	
	@rm -f $(OBJS)
	@(cd libft ; make clean)
fclean: clean
	@rm -f $(NAME) push_swap
	@(cd libft/ ; make fclean)
re: fclean all
