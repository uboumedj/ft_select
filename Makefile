# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/22 16:31:48 by uboumedj          #+#    #+#              #
#    Updated: 2019/10/05 16:32:59 by uboumedj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft

SRCS = 

INC = ft_seelct.h

OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@ $(CC) $(CFLAGS) -o $(NAME) $(SRCS) -Iinclude $(LIBFT)/libft.a
	@echo "\033[1;34mft_select\033[1;32m...compiled\t✓\033[0m"

clean:
	@rm -rf $(OBJS)
	@make clean -C $(LIBFT)
	@echo "\033[1;34mft_select project\033[1;33m obj files removed\t\033[1;31m✓\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT)
	@echo "\033[1;34mft_select project\033[1;33m files deleted\t\t\033[1;31m✓\033[0m"

re: fclean all
