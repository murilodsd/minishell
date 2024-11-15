NAME = minishell
LIBFT_DIR = lib/libft
LIBFT = $(LIBFT_DIR)/libft.a
CC=cc
CCFLAGS= -Wall -Wextra -Werror -g
EXTRA_FLAGS = -lreadline
SRCS = src/main.c \
	src/handle_signals/handle_signals.c \
	src/syntax_check/syntax_check_utils.c \
	src/syntax_check/syntax_check.c \
	src/syntax_check/syntax_check_utils.c \
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
	src/utils/handle_mem.c \
	src/utils/init_data.c
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

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SILENT:
