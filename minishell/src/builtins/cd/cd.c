#include "../../../includes/minishell.h"

void	cd_builtin(char **cd_args)
{
	if (cd_args[2])
		//error -> bash:  cd: too many  arguments
		ft_printf(2,"cd: too many arguments");
	if (cd_args[1])
	{
		if(!ft_strcmp(cd_args[1], ""))
			return ;
	}

	if (chdir(cd_args[1]) != 0)
		ft_printf(2,"Erro ao mudar o diretório");
}

int main(int argc, char const *argv[])
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

	//-----  cd "" mde-souz  ----//
	printf("cd: too many arguments\n");
	cd_builtin((char *[]){"cd", "", "mde-souz", NULL});
	return 0;
}

