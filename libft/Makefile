CFLAGS=-Wall -Wextra -Werror
SRC_DIR=.
SRC=ft_atoi.c ft_atol.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strcmp.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
SRC += ft_printf/ft_printf.c ft_printf/ft_putnbr_base.c ft_printf/parse_placeholder.c ft_printf/print.c ft_printf/to_enum.c
SRC += get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJ=$(SRC:.c=.o)
NAME=libft.a

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

.PHONY: clean
clean:
	$(RM) $(OBJ)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all
