#include "../../../includes/minishell.h"

//REVIEW -> TALVEZ SEJA MELHOR USAR O EXPAND
char	*get_home(t_shell *shell)
{
	t_list	*home_node;

	home_node = ft_lstfind_name(shell->envp_lst,"HOME");
	if (!home_node)
	{
		msg_error(VAR_NOT_SET, "cd", "HOME");
		free_all(shell);
		exit(EXIT_FAILURE);
	}
	return (((t_var *)(home_node->content))->value);
}

void	set_pwd(t_shell *shell)
{
	t_var	*pwd;

	pwd = (t_var *)ft_calloc(sizeof(t_var), 1);
	check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
			pwd, "Calloc failed");
	pwd->value = safe_getcwd(NULL, 0, NULL);
	pwd->name = ft_strdup("PWD");
	check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
			pwd->name, "Calloc failed");
	add_or_edit_var(shell, pwd);
}

void	set_oldpwd(t_shell *shell, char *value)
{
	t_var	*old_pwd;

	old_pwd = (t_var *)ft_calloc(sizeof(t_var), 1);
	check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
			old_pwd, "Calloc failed");
	old_pwd->name = ft_strdup("OLDPWD");
	check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
			old_pwd->name, "Calloc failed");
	old_pwd->value = value;
	add_or_edit_var(shell, old_pwd);
}

void	change_directory(t_shell *shell, char *path)
{
	char	*actual_path;

	actual_path = safe_getcwd(NULL, 0, NULL);
	if (!path)
		path = get_home(shell);
	if (chdir(path) == SUCCESS)
	{
		set_pwd(shell);
		set_oldpwd(shell, actual_path);
	}
	else
	{
		ft_lstremove_mem_node(&(shell->mem_allocation.ptr_mem_list), actual_path);
		msg_error(0, "cd: ", path);
	}
}

void	cd_builtin(t_shell *shell, char **cd_args)
{	
	if (cd_args[2])
		msg_error(TOO_MANY_ARGS, "cd");
	if (cd_args[1])
	{
		if(!ft_strcmp(cd_args[1], ""))
			return ;	
	}
	change_directory(shell, cd_args[1]);
}

/* int main(int argc, char const *argv[])
{
	
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

