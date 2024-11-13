#include "../../../includes/minishell.h"

char	*safe_getcwd(char *buf, size_t size, t_shell *shell)
{
	char	*cwd;

	cwd = getcwd(buf, size);
/* 	if (!cwd)
	{
		shell->exit_status = EXIT_FAILURE;
		shell_error(shell, "PWD Error", 0, false);
		return (NULL);
	} */
	return (cwd);
}

void	cd_builtin(char *path)
{
	if (chdir(path) != 0)
		ft_printf(2,"Erro ao mudar o diretório");
	else
		ft_printf(2,"Mudamos de diretório\n");
}

int main(int argc, char const *argv[])
{
	
	char cwd[100];

	// Obtém e imprime o diretório atual antes de mudar
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Diretório atual: %s\n", cwd);
    } else {
        perror("getcwd() erro");
    }
	cd_builtin("../");

	// Obtém e imprime o diretório atual depois de mudar
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Diretório atual após mudança: %s\n", cwd);
    } else {
        perror("getcwd() erro");
    }
	return 0;
}

