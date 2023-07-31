NAME:=push_swap

LIBFT:=libft/libft.a

SRC_DIR=src
BUILD_DIR:=build

CFLAGS:=-Wall -Wextra -Werror -Ilibft/include -Isrc
DEPFLAGS=-MT $@ -MMD -MP -MF $(BUILD_DIR)/$*.d

SRC:=src/algorithm/helper.c src/algorithm/local_optimized_sort.c src/algorithm/optimize.c src/algorithm/optimize_replace.c src/algorithm/quick_select.c src/algorithm/sort_stacks.c src/args/parse_args.c src/deque/deque.c src/deque/deque_operation.c src/error/error.c src/main.c src/stacks/add_instruction.c src/stacks/push.c src/stacks/rotate.c src/stacks/rotate_reverse.c src/stacks/stacks.c src/stacks/swap.c src/util/memory.c src/util/string.c
OBJ:=$(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))
DEP:=$(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.d,$(SRC))

.PHONY: all
all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(DEPFLAGS) -c -o $@ $<

$(LIBFT):
	make -C libft

.PHONY: clean
clean:
	make -C libft clean
	$(RM) $(OBJ) $(DEP)

.PHONY: fclean
fclean: clean
	make -C libft fclean
	$(RM) $(NAME)

.PHONY: re
re: fclean all

-include $(DEP)
