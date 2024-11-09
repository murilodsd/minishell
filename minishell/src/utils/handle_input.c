#include "../../includes/utils.h"

void	handle_input(char *cmd)
{
	if (ft_strncmp(cmd, "exit", 4) == 0)
		exit(0);
	syntax_check(cmd);
	tokenizer(cmd);
}
