CC := cc

NAME := push_swap

RM := rm -f

DEPFLAGS := -MMD -MP

HEADER := ft_push_swap.h

LIBFT_DIR := libft/

PRINTF_DIR := ft_printf/

LIBFT := $(LIBFT_DIR)libft.a

PRINTF := $(PRINTF_DIR)libftprintf.a

FLAGS := -Wall -Werror -Wextra -I $(LIBFT_DIR) -I $(PRINTF_DIR)

SRC_FILES := main.c\
	complex_sort.c\
	medium_sort.c\
	push_op.c\
	reverse_op.c\
	rotate_op.c\
	simple_sort.c\
	swap_op.c

OBJ := $(patsubst %.c, %.o, $(SRC_FILES))

DEPS := $(patsubst %.o, %.d, $(OBJ))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR) bonus

$(PRINTF):
	make -C $(PRINTF_DIR)

%.o: %.c
	$(CC) $(FLAGS) $(DEPFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)
	$(RM) $(OBJ) $(DEPS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)