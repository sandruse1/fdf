# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sandruse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/17 10:32:51 by sandruse          #+#    #+#              #
#    Updated: 2017/02/24 09:17:54 by sandruse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = fdf_create_struct.c\
	  ft_valid.c\
	  fdf_main.c\
	  ft_line.c\
	  ft_window.c\
	  ft_window_size.c\

GG = $(SRC: .c=.o)

HEAD = fdf.h

FLAG = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit

LIB = -L libft -lft

LIB_HEAD = libft/libft.h

all: $(NAME)

$(NAME): $(GG) $(LIB_HEAD) $(HEAD)
	@echo "\033[33mCompiling library..."
	@make -C libft
	@echo "\033[33mOK!)"
	@echo "\033[33mCompiling project...\033[0m"
	@gcc $(FLAG) $(SRC) $(LIB) $(MLX)
	@gcc -o $(NAME) $(GG) $(LIB) $(MLX)
	@rm a.out
	@echo "\033[32;01mLet's Get Ready To Rumble"

clean:
	@rm -f *.o
	@make clean -C libft
	@echo "\033[33mCLEAN OK!)"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft
	@echo "\033[33mFCLEAN OK!)"

re: fclean all
