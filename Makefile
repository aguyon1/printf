# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguyon <aguyon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 16:22:48 by aguyon            #+#    #+#              #
#    Updated: 2023/10/12 17:09:10 by aguyon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libprintf.a

SRC =	src/ft_printf.c \
		src/ft_dprintf.c \
		src/utils/print_base.c \
		src/utils/print_char.c \
		src/utils/print_decimal.c \
		src/utils/print_format.c \
		src/utils/print_hexa.c \
		src/utils/print_memory.c \
		src/utils/print_percent.c \
		src/utils/print_str.c \
		src/utils/print_unsigned_decimal.c

HEADER = inc/ft_printf.h

BUILD_DIR = build

OBJ = $(SRC:%.c=$(BUILD_DIR)/%.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

CFLAGSDEV = -Wall -Wextra -Werror -g3

LIBFT = libft/libft.a

$(NAME): $(OBJ) $(LIBFT) $(HEADER)
			ar rcs $(NAME) $(OBJ)

all: $(NAME)

$(LIBFT):
	make -C libft

$(BUILD_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGSDEV) -c $< -o $@

clean:
	make clean -C libft
	rm -rf $(BUILD_DIR)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
