/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:52:36 by mde-souz          #+#    #+#             */
/*   Updated: 2024/12/10 19:42:03 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// ----------------------- PRINTF'S MACROS  ------------------------ //

# define BASE16_L "0123456789abcdef"
# define BASE16_U "0123456789ABCDEF"

// ----------------------- GETNEXTLINE'S MACROS -------------------- //

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# define MAX_FD 4096

// ----------------------- GENERAL MACROS -------------------------- //
# ifndef TRUE
#  define TRUE 1
# endif
# ifndef FALSE
#  define FALSE 0
# endif

# ifndef SUCCESS
#  define SUCCESS 0
# endif

# ifndef FAILURE
#  define FAILURE 1
# endif

// ----------------------- COLOR CODES ----------------------------- //

# ifndef COLOR_DEFINES_H
#  define COLOR_DEFINES_H

//Code to reset the color
#  define RESET   "\x1b[0m"
// Colors (texto)
#  define BLACK   "\x1b[1;3;30m"
#  define RED     "\x1b[1;3;31m"
#  define GREEN   "\x1b[1;3;32m"
#  define YELLOW  "\x1b[1;3;33m"
#  define BLUE    "\x1b[1;3;34m"
#  define MAGENTA "\x1b[1;3;35m"
#  define CYAN    "\x1b[1;3;36m"
#  define WHITE   "\x1b[1;3;37m"

# endif

// ----------------------- LIBRARIES ------------------------------- //

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <limits.h>
# include <stddef.h>

// ----------------------- STRUCTS DEFINITIONS --------------------- //

//Struct for a node
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

//Struct for a point
typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

//Struct for the printf tags
typedef struct tag_parameter
{
	int		flags[256];
	int		width;
	int		digits;
	int		decplaces;
	char	tag;
}	t_params;

//Structs with list of pointers to save pointers dynamic allocated
typedef struct s_mem_allocation
{
	t_list	*ptr_mem_list;
	t_list	*matrix_mem_list;
}	t_mem_alloc;

// ----------------------- TYPE DEFINITIONS ------------------------ //

typedef unsigned long	t_ul;

// ----------------------- FUNCTION PROTOTYPES --------------------- //

int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
size_t	ft_strlen(const char *s);
void	ft_putendl_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_isupper(int c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_isdigit(int c);
bool	ft_isalldigits(char *str);
int		ft_isprint(int c);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_countdec(long n_long);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
char	*ft_strcpy(char *dest, char *src);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strcat(char *dst, const char *src);
char	*ft_strchr(const char *s, int c);
bool	ft_str_validate(char *str, bool(*f)(char));
bool	ft_str_in_set(char *str, char *set);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_isspace(char c);
bool	ft_is_atoi_param_max_10(const char *nptr);
long	ft_atoi(const char *nptr);
char	*ft_char_to_byte(unsigned char c);
int		ft_byte_to_char(char *byte);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strdup(const char *s);
void	ft_str_replace(char **dest, char *src);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstadd_string_ordered(t_list **lst, t_list *new);
int		ft_toupper(int c);
int		ft_tolower(int c);
size_t	ft_mtxlen(char **matrix);
char	**ft_mtxdup(char **matrix);
void	flood_fill(char **tab, t_point size, t_point begin);

// -------------------- FT_PRINTF FUNCTION PROTOTYPES -------------- //

int		ft_printf(int fd, const char *format, ...);
int		ft_putnbr_hexabase_fd(t_ul nbr, char *base, int fd);
int		ft_printnbr_fd(long nbr, t_params params, int fd);
int		ft_print_s_fd(char *s, t_params params, int fd);
int		ft_printnbr_base_fd(t_ul nbr, t_params params, char *base, int fd);
int		ft_printchar_fd(char c, t_params params, int fd);
int		ft_print_p_fd(t_ul p, t_params params, int fd);

// ------------------- GET_NEXT_LINE FUNCTION PROTOTYPES ----------- //

char	*get_next_line(int fd);

//-------------- CHECK_ERROR AND FREE MEMORY FUNCTION PROTOTYPES --- //

void	ft_free_exit_error(t_mem_alloc *mem_allocation, char *error_msg);
void	ft_save_pointer(t_mem_alloc *mem_allocation, \
	t_list **ptr_or_matrix_list, void *ptr);
void	ft_check_mem_alloc(t_mem_alloc *mem_allocation, \
	t_list **ptr_or_matrix_list, void *ptr, char *error_msg);
void	ft_free_matrix(void *matrix_void);
void	ft_free_ptr_buffer(char **buffer, int size);

#endif