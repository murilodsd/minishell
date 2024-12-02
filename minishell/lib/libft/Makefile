CC=cc
CCFLAGS=-Wall -Wextra -Werror -g
AR=ar
ARFLAGS=rcs
NAME=../libft.a
SRC_PATH=src/
SRCS_LIBFT=ft_itoa.c ft_char_to_byte.c ft_byte_to_char.c ft_putstr_fd.c \
ft_atoi.c ft_strmapi.c ft_memchr.c ft_split.c ft_strcmp.c ft_strncmp.c \
ft_bzero.c  ft_memcmp.c ft_strchr.c ft_strnstr.c ft_str_in_set.c \
ft_calloc.c ft_realloc.c ft_memcpy.c ft_strdup.c ft_strrchr.c \
ft_isalnum.c ft_memmove.c ft_striteri.c ft_strtrim.c ft_str_validate.c \
ft_isalpha.c ft_memset.c ft_strjoin.c ft_substr.c ft_str_replace.c \
ft_isascii.c ft_putchar_fd.c ft_strlcat.c ft_strcat.c ft_flood_fill.c \
ft_mtxdup.c ft_mtxlen.c\
ft_isdigit.c ft_putendl_fd.c ft_strlcpy.c ft_strcpy.c ft_tolower.c \
ft_isprint.c ft_putnbr_fd.c ft_strlen.c ft_toupper.c ft_countdec.c \
ft_lstadd_front.c ft_lstadd_back.c \
ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstadd_string_ordered.c \
ft_lstsize.c ft_free_ptr_buffer.c ft_save_pointer.c ft_free_exit_error.c \
ft_check_mem_alloc.c ft_free_matrix.c
SRCS_PRINTF=ft_printf.c ft_print_p_fd.c \
ft_printnbr_fd.c ft_print_s_c_fd.c ft_printnbr_base_fd.c
SRCS_GET_NEXT_LINE=get_next_line.c
SRCS_NAMES=$(SRCS_LIBFT) $(SRCS_PRINTF) $(SRCS_GET_NEXT_LINE)
SCR=$(addprefix $(SRC_PATH), $(SRCS_NAMES))
OBJ_PATH=build/
OBJS_NAMES=$(SRCS_NAMES:.c=.o)
OBJS=$(addprefix $(OBJ_PATH), $(OBJS_NAMES))
INCLUDE=-I ./include
RM=rm -f

all: msg $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $?

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(CCFLAGS) -c $< -o $@ $(INCLUDE)

msg:
	@echo "\033[1;34m📚 Generating static library... Consolidating knowledge into blocks! 🏗️\033[0m"

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re generating_static_library_msg

.SILENT: