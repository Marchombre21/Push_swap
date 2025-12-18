
NAME := push_swap

BONUS := checker

LIBFT_DIR := libft

BUILD_DIR := .build

RM := rm -f

CC := cc

FLAGS := -Wall -Werror -Wextra -I $(LIBFT_DIR) -g -g3

DEPFLAGS := -MMD -MP

LIBFT := $(LIBFT_DIR)/libft.a

SRC_FILES := ft_push_swap.c\
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
	push_swap_utils3.c\

OBJ := $(patsubst %.c, $(BUILD_DIR)/%.o, $(SRC_FILES))
DEPS := $(patsubst %.o, %.d, $(OBJ))

SRC_FILES_BONUS := ft_push_swap_bonus.c\
	push_swap_utils3.c\
	push_op.c\
	reverse_op.c\
	rotate_op.c\
	swap_op.c\

OBJ_BONUS := $(patsubst %.c, $(BUILD_DIR)/%.o, $(SRC_FILES_BONUS))
DEPS_BONUS := $(patsubst %.o, %.d, $(OBJ_BONUS))

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

bonus: $(OBJ_BONUS)

$(BONUS): $(OBJ_BONUS) $(LIBFT) $(NAME)
	$(CC) $(FLAGS) $(OBJ_BONUS) $(LIBFT) -o $(BONUS)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJ) $(DEPS) $(OBJ_BONUS) $(DEPS_BONUS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rmdir -p $(BUILD_DIR)
	$(RM) $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re FORCE bonus

-include $(DEPS) $(DEPS_BONUS)
