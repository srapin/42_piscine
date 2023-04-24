# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srapin <srapin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 01:15:01 by srapin            #+#    #+#              #
#    Updated: 2022/10/05 16:41:01 by srapin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
AR	= ar -rc
SRC	= ./srcs/ft_putchar.c\
	./srcs/ft_swap.c\
	./srcs/ft_putstr.c\
	./srcs/ft_strlen.c\
	./srcs/ft_strcmp.c
RM	= rm -f
OBJS	= $(SRC:.c=.o)
HEADER	= ./includes

%.o: %.c
	$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:	
	$(RM) $(OBJS)

fclean:	clean 
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean re fclean