NAME = minishell
LIBFT_DIR = includes/libft
LIBFT = $(LIBFT_DIR)/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
EXTRA_FLAGS = -lreadline
SRCS = src/main.c \
	src/syntax_check/syntax_check.c \
	src/tokenizer/tokenizer.c \
	src/parser/parser.c \
	src/binary_tree/binary_tree.c \
	src/executer/executer.c \
	src/builtins/builtins.c \
	src/utils/init_data.c src/utils/handle_input.c src/utils/handle_signals.c
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
