# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfitte/gmach <bfitte@student.42lyon.fr/    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/06 06:57:02 by bfitte            #+#    #+#              #
#    Updated: 2025/12/09 10:11:29 by bfitte/gmac      ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
CC=cc
HEADERS=libft.h
CFLAGS=-Wall -Werror -Wextra
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

BONUS_FILES=ft_lstnew_bonus.c\
	ft_lstadd_front_bonus.c\
	ft_lstsize_bonus.c\
	ft_lstlast_bonus.c\
	ft_lstadd_back_bonus.c\
	ft_lstdelone_bonus.c\
	ft_lstclear_bonus.c\
	ft_lstiter_bonus.c\
	ft_lstmap_bonus.c\

OBJ=$(SRC_FILES:.c=.o)

OBJ_BONUS=$(BONUS_FILES:.c=.o)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -o $@ -c $<

all: $(NAME)

bonus: $(NAME) $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ_BONUS)

clean: 
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re