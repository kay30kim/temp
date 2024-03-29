# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 12:17:03 by kyung-ki          #+#    #+#              #
#    Updated: 2023/11/26 14:34:23 by kyung-ki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror # -g -fsanitize=address
NAME	=	so_long
VPATH	=	$(SRC_DIR)
#// /Users/kyung-ki/.brew/lib
#MLX		=	-framework Cocoa -framework OpenGL -framework IOKit library/MLX42/build/libmlx42.a -Iinclude -lglfw -L"/Users/kyung-ki/.brew/lib"

SRC_DIR	=	src
SRCS	=	$(addprefix $(SRC_DIR)/, graphics.c main.c map_check.c map.c move.c utils.c) #mlx_main.c )
OBJS	=	${SRCS:.c=.o}

#MK		=	mkdir -p
#BIN_DIR =	bin
#BIN		=	$(addprefix $(BIN_DIR)/, $(SRCS:.c=.o))
INCLUDE	=	include
USERS	=	$(shell whoami)

LIBGL	=	-lglfw -L"/Users/$(USERS)/homebrew/lib" -L"/Users/$(USERS)/.brew/lib"
LIBFT	=	./library/libft
LIBMLX	=	./library/MLX42
LIBPF	=	./library/ft_printf
LIBGNL	=	./library/get_next_line
LIBS	=	${LIBGL} ${LIBFT}/libft.a ${LIBMLX}/libmlx42.a ${LIBPF}/libftprintf.a ${LIBGNL}/get_next_line.a
HEADERS	=	-Iinclude -I$(LIBFT)/include -I$(LIBMLX)/include -I$(LIBPF) -I$(LIBGNL)


#$(BIN_DIR)/%.o: $(SRC_DIR)/%.c | $(BIN_DIR)
#	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

all : libft libmlx libpf libgnl $(NAME)

libft :
	$(MAKE) -C $(LIBFT)

libmlx :
	$(MAKE) -C $(LIBMLX)

libpf :
	$(MAKE) -C $(LIBPF)

libgnl :
	$(MAKE) -C $(LIBGNL)

%.o: %.c
	@${CC} ${CFLAGS} -o $@ -c $< ${HEADERS}

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
#	$(CC) $(CFLAGS) $(BIN) -o $(NAME) -L$(LIBFT) -lft -L$(LIBMLX) -lmlx -L$(LIBPF) -lftprintf -L$(LIBGNL) -lgnl
#	$(CC) $(CFLAGS) $(BIN) $(MLX) -o $(NAME)
#	$(CC) $(CFLAGS) -Iinclude -I./ $(MLX) $(NAME) $(BIN) src/main.c

clean : 
	rm -rf $(OBJS)
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(LIBPF) clean
	$(MAKE) -C $(LIBGNL) clean
#	$(MAKE) -C $(LIBMLX) clean

fclean : clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(LIBPF) fclean
	$(MAKE) -C $(LIBGNL) fclean
#	$(MAKE) -C $(LIBMLX) fclean

re : fclean all

.PHONY : all clean fclean re libft libmlx libpf libgnl
