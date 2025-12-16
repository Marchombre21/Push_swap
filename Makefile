
NAME := push_swap

LIBFT_DIR := libft

BUILD_DIR := .build

RM := rm -f

CC := cc

FLAGS := -Wall -Werror -Wextra -I $(LIBFT_DIR) -g -g3

DEPFLAGS := -MMD -MP

LIBFT := $(LIBFT_DIR)/libft.a

SRC_FILES := main.c\
	complex_sort.c\
	medium_sort.c\
	push_op.c\
	reverse_op.c\
	rotate_op.c\
	simple_sort.c\
	rev_simple_sort.c\
	swap_op.c\
	adaptive_sort.c\
	push_swap_utils.c\
	push_swap_utils2.c\

OBJ := $(patsubst %.c, $(BUILD_DIR)/%.o, $(SRC_FILES))

DEPS := $(patsubst %.o, %.d, $(OBJ))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT): FORCE
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

FORCE:

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(FLAGS) $(DEPFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJ) $(DEPS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rmdir -p $(BUILD_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re FORCE

-include $(DEPS)
