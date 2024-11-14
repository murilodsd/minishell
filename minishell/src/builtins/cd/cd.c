#include "../../../includes/minishell.h"

void	cd_builtin(char **cd_args)
{
	if (cd_args[2])
		msg_error(TOO_MANY_ARGS, "cd");
	if (cd_args[1])
	{
		if(!ft_strcmp(cd_args[1], ""))
			return ;
	}

	if (chdir(cd_args[1]) != 0)
		msg_error(0, "cd: ", cd_args[1]);
		//ft_printf(2, "minishell: cd: %s: %s\n", cd_args[1], strerror(errno));
}

void print_error_message(int errnum) {
    printf("Erro %d: %s\n", errnum, strerror(errnum));
}

/* int main(int argc, char const *argv[])
{

	char cwd[100];

	char *cwd;

	//----- TESTES CD ------//
	cwd = getcwd(NULL, 0);
	printf("Diretório atual: %s\n", cwd);
	//----- INDO PARA PASTA DO USER ------//
	cd_builtin((char *[]){"cd", "/home/mde-souz", NULL});
	cwd = getcwd(NULL, 0);
	printf("/home/mde-souz\n");
	printf("%s\n", cwd);
	//-----  cd .  ----//
	cd_builtin((char *[]){"cd", ".", NULL});
	cwd = getcwd(NULL, 0);
	printf("%s\n", cwd);
	printf("/home/mde-souz\n");
	//-----  cd ..  ----//
	cd_builtin((char *[]){"cd", "..", NULL});
	cwd = getcwd(NULL, 0);
	printf("%s\n", cwd);
	printf("/home\n");
	//-----  cd ""  ----//
	cd_builtin((char *[]){"cd", "", NULL});
	cwd = getcwd(NULL, 0);
	printf("%s\n", cwd);
	printf("/home\n");
	//-----  cd ''  ----//
	cd_builtin((char *[]){"cd", (char[]){'\0'}, NULL});
	cwd = getcwd(NULL, 0);
	printf("%s\n", cwd);
	printf("/home\n");
	//-----  cd mde-souz  ----//
	cd_builtin((char *[]){"cd", "mde-souz", NULL});
	cwd = getcwd(NULL, 0);
	printf("%s\n", cwd);
	printf("/home/mde-souz\n");
	//-----  cd ../../../..   ----//
	cd_builtin((char *[]){"cd", "../../../..", NULL});
	cwd = getcwd(NULL, 0);
	printf("%s\n", cwd);
	printf("/\n");

	//----- CASOS DE ERRO ----//

	//-----  cd path_inexistente   ----//
	cd_builtin((char *[]){"cd", "path_inexistente", NULL});
	printf("minishell: cd: path_inexistente: No such file or directory\n");
	//-----  cd "" mde-souz  ----//
	cd_builtin((char *[]){"cd", "", "mde-souz", NULL});
	printf("minishell: cd: too many arguments\n");
	return 0;
} */

