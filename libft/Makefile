# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmach <gmach@student.42lyon.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/06 06:57:02 by bfitte            #+#    #+#              #
#    Updated: 2025/12/18 17:39:20 by gmach            ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

BUILD_DIR=.build

CC=cc
CFLAGS=-Wall -Werror -Wextra
DEPFLAGS=-MMD -MP

SRC_FILES=ft_isalpha.c\
	ft_memcpy.c\
	ft_strrchr.c\
	ft_isdigit.c\
	ft_memmove.c\
	ft_strncmp.c\
	ft_isalnum.c\
	ft_strlcpy.c\
	ft_memchr.c\
	ft_isascii.c\
	ft_strlcat.c\
	ft_strlen.c\
	ft_memcmp.c\
	ft_isprint.c\
	ft_toupper.c\
	ft_strnstr.c\
	ft_tolower.c\
	ft_memset.c\
	ft_strchr.c\
	ft_bzero.c\
	ft_atoi.c\
	ft_calloc.c\
	ft_strdup.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_split.c\
	ft_itoa.c\
	ft_strmapi.c\
	ft_striteri.c\
	ft_putchar_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_putstr_fd.c\
	ft_lstnew_bonus.c\
	ft_lstadd_front_bonus.c\
	ft_lstsize_bonus.c\
	ft_lstlast_bonus.c\
	ft_lstadd_back_bonus.c\
	ft_lstdelone_bonus.c\
	ft_lstclear_bonus.c\
	ft_lstiter_bonus.c\
	ft_lstmap_bonus.c\
	ft_printf.c\
	ft_printf_chartype.c\
	ft_printf_nbrtype.c\
	ft_printf_nbrbase.c\

OBJ := $(patsubst %.c, $(BUILD_DIR)/%.o, $(SRC_FILES))
DEP=$(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(DEPFLAGS) -o $@ -c $<

$(BUILD_DIR):
	mkdir -p $@

clean:
	rm -f $(OBJ) $(DEP)

fclean: clean
	rm -f $(NAME)
	rm -rf $(BUILD_DIR)

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re
