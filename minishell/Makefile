NAME = minishell
LIBFT_DIR = lib/libft
LIBFT = $(LIBFT_DIR)/libft.a
CC=cc
CCFLAGS= -Wall -Wextra -Werror -g
EXTRA_FLAGS = -lreadline
FSANITIZE = -fsanitize=address -fsanitize=leak -fsanitize=undefined -fno-omit-frame-pointer
SRCS = src/main.c \
	src/handle_signals/handle_signals.c \
	src/handle_signals/handle_signals_utils.c \
	src/syntax_check/syntax_check.c \
	src/syntax_check/syntax_check_utils.c \
	src/tokenizer/tokenizer.c \
	src/tokenizer/tokenizer_handlers.c \
	src/tokenizer/tokenizer_handlers2.c \
	src/tokenizer/tokenizer_handle_list.c \
	src/tokenizer/tokenizer_utils.c \
	src/parser/parser.c \
	src/parser/parser_handlers.c \
	src/parser/parser_handlers2.c \
	src/parser/parser_checkers.c \
	src/parser/parser_expand.c \
	src/parser/parser_expand_utils.c \
	src/parser/parser_utils.c \
	src/binary_tree/binary_tree.c \
	src/binary_tree/binary_tree_utils.c \
	src/binary_tree/redir_node_functions.c \
	src/heredoc/heredoc.c \
	src/heredoc/heredoc_utils.c \
	src/executer/executer.c \
	src/executer/executer_utils.c \
	src/executer/exec_builtin_execve.c \
	src/executer/exec_pipe.c \
	src/executer/execve.c \
	src/executer/execve_utils.c \
	src/executer/exec_redir.c \
	src/builtins/echo/echo.c \
	src/builtins/cd/cd.c \
	src/builtins/pwd/pwd.c \
	src/builtins/export/export.c \
	src/builtins/export/export_utils.c \
	src/builtins/export/export_utils2.c \
	src/builtins/unset/unset.c \
	src/builtins/env/env.c \
	src/builtins/exit/exit.c \
	src/utils/utils.c \
	src/utils/handle_input.c \
	src/utils/handle_error.c \
	src/utils/handle_mem.c \
	src/utils/init_data.c \
	src/utils/free_functions.c \
	src/utils/prints.c
OBJS = $(SRCS:.c=.o)

#GENERAL
LIB_STATIC_NAME = libft.a
LIB_PATH=lib/
LIB_EXTERNALS = libreadline
LIBS_FLAGS= -l$(patsubst lib%.a, %, $(LIB_STATIC_NAME)) -l$(patsubst lib%, %, $(LIB_EXTERNALS)) -L$(LIB_PATH)
LIB_STATIC= $(addprefix $(LIB_PATH) , $(INCLUDE_PATH))
INCLUDE_PATH=./includes/ ./lib/*/include/
INCLUDE_FLAG=$(addprefix -I , $(INCLUDE_PATH))
RM = rm -f

#VALGRIND
VALGRIND_FLAGS = --quiet --leak-check=full --show-leak-kinds=all --track-fds=yes --trace-children=yes --gen-suppressions=all
VALGRIND_SUPP = --suppressions=readline.supp

all: $(NAME)

$(NAME): msg libs $(OBJS) $(LIB_STATIC)
	$(CC) $(CCFLAGS) $(OBJS) $(INCLUDE_FLAG) $(LIBS_FLAGS) -o $(NAME)
	echo "\033[1;32m✔ Compilation complete! 🎉\033[0m"

libs:
	make -s all -C lib/libft

msg:
	@echo "\033[1;32m🌟 Compiling... The code is coming to life! 🚀\033[0m"

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

valgrind: all
	valgrind $(VALGRIND_FLAGS) $(VALGRIND_SUPP) ./$(NAME)

sanitize: $(NAME)
	$(CC) $(CCFLAGS) $(FSANITIZE) $(OBJS) $(INCLUDE_FLAG) $(LIBS_FLAGS) -o $(NAME)

clean:
	make -s -C $(LIBFT_DIR) clean
	make -s -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	make -s -C $(LIBFT_DIR) fclean
	make -s -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SILENT:
