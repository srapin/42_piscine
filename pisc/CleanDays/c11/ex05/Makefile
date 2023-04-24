# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srapin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 00:19:47 by srapin            #+#    #+#              #
#    Updated: 2022/10/06 01:21:04 by srapin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= do-op
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
SRC	= ft_atoi.c\
	do_op.c\
	operators.c\
	tools.c\
	ft_strstr.c
RM	= rm -f
OBJS	= $(SRC:.c=.o)

%.o: %.c
	@ $(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	@ $(CC) -o $(NAME) $(OBJS)

clean:	
	@ $(RM) $(OBJS)

fclean:	clean 
	@ $(RM) $(NAME)

re:	fclean all

.PHONY:	all clean re fclean
