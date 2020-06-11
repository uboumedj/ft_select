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

SRCS = srcs/main.c srcs/errors.c srcs/initialise_terminal.c \
		srcs/initialise_list.c srcs/free.c srcs/initialise_signals.c \
		srcs/initialise_display.c srcs/display.c srcs/keys.c srcs/keys_2.c \
		srcs/initialise_signals_2.c

INC = ft_select.h

OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@ $(CC) $(CFLAGS) -o $(NAME) $(SRCS) -Iinclude $(LIBFT)/libft.a -ltermcap
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
