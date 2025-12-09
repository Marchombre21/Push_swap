CC := cc

NAME := push_swap

RM := rm -f

DEPFLAGS := -MMD -MP

HEADER := ft_push_swap.h

LIBFT_DIR := libft/

LIBFT := $(LIBFT_DIR)libft_ps.a

FLAGS := -Wall -Werror -Wextra -I$(LIBFT_DIR)

SRC_FILES := main.c

OBJ := $(patsubst %.c, %.o, $(SRC_FILES))

DEPS := $(patsubst %.o, %.d, $(OBJ))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(FLAGS) $(DEPFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJ) $(DEPS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)