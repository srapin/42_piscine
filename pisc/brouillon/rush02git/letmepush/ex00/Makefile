SRC = ./main.c\
	./construct_dict.c\
	./convert.c\
	./dict_list.c\
	./ft_atoi_dict.c\
	./ft_split.c\
	./itoa.c\
	./tools.c

NAME = rush-02
CFLAGS += -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)
$(NAME) : $(OBJ)
	gcc -o $(NAME) $(OBJ)

all: $(NAME)

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re