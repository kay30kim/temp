# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 12:02:22 by kyung-ki          #+#    #+#              #
#    Updated: 2023/11/18 17:09:27 by kyung-ki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	clang

CFLAGS	=	-Wall -Werror -Wextra

NAME	=	get_next_line.a

SRCS	=	get_next_line.c get_next_line_utils.c

OBJS	=	${SRCS:.c=.o}



all : $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclaen all

.PHONY : all clean fclean re 
