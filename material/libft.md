# LIBFT

## Funções de Entrada/Saída
1. **ft_putchar_fd**: Imprime um caractere no file descriptor especificado.
2. **ft_putstr_fd**: Imprime uma string no file descriptor.
3. **ft_putnbr_fd**: Imprime um número inteiro no file descriptor.
4. **ft_putendl_fd**: Imprime uma string seguida de uma nova linha no file descriptor.

## Manipulação de Strings
5. **ft_strlen**: Calcula o comprimento de uma string.
6. **ft_strjoin**: Concatena duas strings em uma nova.
7. **ft_strlcpy**: Copia uma string para um buffer com tamanho limitado, garantindo segurança.
8. **ft_strlcat**: Concatena strings com limite de tamanho.
9. **ft_strchr**: Encontra a primeira ocorrência de um caractere em uma string.
10. **ft_strrchr**: Encontra a última ocorrência de um caractere em uma string.
11. **ft_strcmp**: Compara duas strings.
12. **ft_strncmp**: Compara até n caracteres de duas strings.
13. **ft_strnstr**: Localiza uma substring dentro de uma string, respeitando o limite de tamanho.
14. **ft_strtrim**: Remove caracteres específicos do início e fim de uma string.
15. **ft_strdup**: Cria uma cópia de uma string.
16. **ft_substr**: Extrai uma substring a partir de uma posição específica.
17. **ft_striteri**: Aplica uma função a cada caractere da string, modificando-a diretamente.
18. **ft_strmapi**: Cria uma nova string aplicando uma função a cada caractere de uma string.

## Conversões
19. **ft_atoi**: Converte uma string para um número inteiro.
20. **ft_itoa**: Converte um número inteiro para uma string.
21. **ft_char_to_byte**: Converte um caractere para um formato de byte.
22. **ft_byte_to_char**: Converte um byte para um caractere.

## Manipulação de Memória
23. **ft_memset**: Preenche uma área de memória com um valor.
24. **ft_bzero**: Zera uma área de memória.
25. **ft_memcpy**: Copia dados de uma área de memória para outra.
26. **ft_memmove**: Move dados entre áreas de memória que podem se sobrepor.
27. **ft_memchr**: Localiza um valor em uma área de memória.
28. **ft_memcmp**: Compara duas áreas de memória.
29. **ft_calloc**: Aloca memória inicializada com zeros.
30. **ft_realloc**: Redimensiona um bloco de memória previamente alocado.

## Checagem de Propriedades
31. **ft_isdigit**: Verifica se um caractere é um dígito.
32. **ft_isalpha**: Verifica se um caractere é alfabético.
33. **ft_isalnum**: Verifica se um caractere é alfanumérico.
34. **ft_isascii**: Verifica se um caractere pertence à tabela ASCII.
35. **ft_isprint**: Verifica se um caractere é imprimível.
36. **ft_isupper**: Verifica se um caractere é maiúsculo.
37. **ft_isspace**: Verifica se um caractere é espaço em branco.
38. **ft_isalldigits**: Verifica se uma string contém apenas dígitos.

## Manipulação de Listas Encadeadas
39. **ft_lstnew**: Cria um novo nó de lista encadeada.
40. **ft_lstadd_front**: Adiciona um nó no início da lista.
41. **ft_lstadd_back**: Adiciona um nó no final da lista.
42. **ft_lstlast**: Retorna o último nó de uma lista.
43. **ft_lstsize**: Calcula o tamanho de uma lista.
44. **ft_lstdelone**: Remove um nó da lista e libera sua memória.
45. **ft_lstclear**: Remove todos os nós da lista e libera memória.
46. **ft_lstiter**: Aplica uma função a cada nó da lista.
47. **ft_lstmap**: Cria uma nova lista aplicando uma função a cada nó.

## Utilidades Diversas
48. **ft_countdec**: Conta o número de dígitos decimais de um número.
49. **ft_toupper**: Converte um caractere para maiúsculo.
50. **ft_tolower**: Converte um caractere para minúsculo.
51. **ft_mtxlen**: Calcula o tamanho de uma matriz de strings (char **).
52. **ft_mtxdup**: Duplica uma matriz de strings.
53. **flood_fill**: Preenche uma área conectada em uma matriz, útil para algoritmos de grafos.

## Funções Relacionadas ao printf
54. **ft_printf**: Imprime uma string formatada em um file descriptor.
55. **ft_putnbr_hexabase_fd**: Imprime um número em base hexadecimal.
56. **ft_printnbr_fd**: Imprime um número com formatação.
57. **ft_print_s_fd**: Imprime uma string com formatação.
58. **ft_printnbr_base_fd**: Imprime um número em qualquer base numérica.
59. **ft_printchar_fd**: Imprime um caractere com formatação.
60. **ft_print_p_fd**: Imprime um ponteiro formatado.

## Funções do get_next_line
61. **get_next_line**: Lê uma linha de um arquivo ou entrada padrão.

## Gerenciamento de Memória Personalizado
62. **ft_free_exit_error**: Libera memória e exibe uma mensagem de erro antes de sair.
63. **ft_save_pointer**: Salva ponteiros alocados dinamicamente em listas para controle.
64. **ft_check_mem_alloc**: Verifica a alocação de memória e salva ponteiros dinamicamente.
65. **ft_free_matrix**: Libera a memória de uma matriz (char **).
66. **ft_free_ptr_buffer**: Libera memória de um buffer de ponteiros com tamanho fixo.

