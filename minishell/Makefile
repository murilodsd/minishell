NAME = minishell
LIBFT_DIR = includes/libft
LIBFT = $(LIBFT_DIR)/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
EXTRA_FLAGS = -lreadline
SRCS = src/main.c \
	src/handle_signals/handle_signals.c \
	src/syntax_check/syntax_check.c \
	src/tokenizer/tokenizer.c \
	src/parser/parser.c \
	src/binary_tree/binary_tree.c \
	src/executer/executer.c \
	src/builtins/builtins.c \
	src/builtins/echo/echo.c \
	src/builtins/cd/cd.c \
	src/builtins/pwd/pwd.c \
	src/builtins/export/export.c \
	src/builtins/unset/unset.c \
	src/builtins/env/env.c \
	src/builtins/exit/exit.c \
	src/utils/handle_input.c \
	src/utils/handle_error.c \
	src/utils/init_data.c
OBJS = $(SRCS:.c=.o)
RM = rm -rf

all: $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(EXTRA_FLAGS) -o $(NAME) $(OBJS) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SILENT:
