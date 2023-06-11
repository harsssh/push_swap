NAME:=push_swap

LIBFT:=libft/libft.a

SRC_DIR=src
BUILD_DIR:=build

CFLAGS:=-Wall -Wextra -Werror -Ilibft
DEPFLAGS=-MT $@ -MMD -MP -MF $(BUILD_DIR)/$*.d

SRC:=$(wildcard src/*.c)
OBJ:=$(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))
DEP:=$(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.d,$(SRC))

.PHONY: all
all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -Llibft -lft -o $@ $(OBJ)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDE) -c -o $@ $<

$(DEP):

$(BUILD_DIR):
	@mkdir -p $@

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