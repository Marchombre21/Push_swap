CC := cc

NAME := push_swap

RM := rm -f

DEPFLAGS := -MMD -MP

HEADER := ft_push_swap.h

LIBFT_DIR := libft/

PRINTF_DIR := ft_printf/

BUILD_DIR := .build

LIBFT := $(LIBFT_DIR)libft.a

PRINTF := $(PRINTF_DIR)libftprintf.a

FLAGS := -Wall -Werror -Wextra -g3 -I $(LIBFT_DIR) -I $(PRINTF_DIR)

SRC_FILES := main.c\
	complex_sort.c\
	medium_sort.c\
	push_op.c\
	reverse_op.c\
	rotate_op.c\
	simple_sort.c\
	rev_simple_sort.c\
	swap_op.c\
	push_swap_utils.c\
	push_swap_utils2.c\

OBJ := $(patsubst %.c, $(BUILD_DIR)/%.o, $(SRC_FILES))

DEPS := $(patsubst %.o, %.d, $(OBJ))

TEST_FILE := args.txt
TFLAGS := --medium

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(FLAGS) $(OBJ) $(PRINTF) $(LIBFT) -o $(NAME)

$(LIBFT): FORCE
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(PRINTF): FORCE
	@$(MAKE) -C $(PRINTF_DIR) --no-print-directory

FORCE:

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(FLAGS) $(DEPFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	$(RM) $(OBJ) $(DEPS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	rmdir -p $(BUILD_DIR)
	$(RM) $(NAME)

t:
	make
	./push_swap $(TFLAGS) $(shell cat $(TEST_FILE))

tn:
	make
	./push_swap $(TFLAGS) $(shell cat $(TEST_FILE)) | wc -l

re: fclean all

.PHONY: all clean fclean re FORCE

-include $(DEPS)
