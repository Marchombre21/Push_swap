# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfitte/gmach <bfitte@student.42lyon.fr/    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/17 10:37:31 by gmach             #+#    #+#              #
#    Updated: 2025/12/15 09:52:55 by bfitte/gmac      ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

#flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -MMD -MP -I$(LIBFT_DIR) -I.

#directories
SRC_DIR = srcs
LIBFT_DIR = ../libft

#used libft files
LIBFT_SRC = $(addprefix $(LIBFT_DIR)/, ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strlen.c)
LIBFT_OBJ = $(LIBFT_SRC:.c=.o)
LIBFT_DEPS = $(LIBFT_OBJ:.o=.d)

#files
SRC = $(addprefix $(SRC_DIR)/, ft_printf.c handle_chartype.c handle_nbrtype.c nbrbase_fcts.c)
OBJ = $(SRC:.c=.o)
DEPS = $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_OBJ)
	ar rcs $@ $(OBJ) $(LIBFT_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re t

clean:
	rm -f $(OBJ) $(DEPS)

fclean: clean
	rm -f $(NAME) a.out

re: fclean all

t: $(NAME)
	$(CC) -g -g3 main.c $(NAME)
	./a.out

.PHONY: all clean fclean re t FORCE

-include $(DEPS) $(LIBFT_DEPS)
