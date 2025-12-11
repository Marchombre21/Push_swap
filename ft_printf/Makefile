# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfitte/gmach <bfitte@student.42lyon.fr/    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/17 10:37:31 by gmach             #+#    #+#              #
#    Updated: 2025/12/11 07:04:39 by bfitte/gmac      ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

#flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
CFLAGS += -MMD -MP -I. -I$(LIBFT_DIR)

#directories
SRC_DIR = srcs
LIBFT_DIR = ../libft

#headers
SUBLIB = $(LIBFT_DIR)/libft.a

#files
SRC = $(addprefix $(SRC_DIR)/, ft_printf.c handle_chartype.c handle_nbrtype.c nbrbase_fcts.c)
OBJ = $(SRC:.c=.o)
DEPS = $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ) $(SUBLIB)
	cp $(SUBLIB) $(NAME)
	ar rcs $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(SUBLIB):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ) $(DEPS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) a.out
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

t: $(NAME)
	$(CC) -g -g3 main.c $(NAME)
	./a.out

.PHONY: all clean fclean re t

-include $(DEPS)
