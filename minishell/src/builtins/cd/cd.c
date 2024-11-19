#include "../../../includes/minishell.h"

//REVIEW -> TALVEZ SEJA MELHOR USAR O EXPAND
char	*get_home(t_shell *shell)
{
	t_list	*home_node;

	home_node = ft_lstfind_name(shell->envp_lst,"HOME");
	if (!home_node)
		return (NULL);
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
	{
		path = get_home(shell);
		if (!path)
		{
			msg_error(VAR_NOT_SET, "cd", "HOME");
			shell->exit_status = EXIT_FAILURE;
			return ;
		}
	}
	if (chdir(path) == SUCCESS)
	{
		set_pwd(shell);
		set_oldpwd(shell, actual_path);
		shell->exit_status = EXIT_SUCCESS;
	}
	else
	{
		ft_lstremove_mem_node(&(shell->mem_allocation.ptr_mem_list), actual_path);
		msg_error(0, "cd: ", path);
		shell->exit_status = EXIT_FAILURE;
	}
}

void	cd_builtin(t_shell *shell, char **cd_args)
{	
	if (cd_args[2])
	{
		msg_error(TOO_MANY_ARGS, "cd");
		shell->exit_status = EXIT_FAILURE;
		return ;
	}
	if (cd_args[1])
	{
		if(!ft_strcmp(cd_args[1], ""))
		{
			shell->exit_status = EXIT_SUCCESS;
			return ;	
		}
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

/* int	main(int argc, char **argv, char **envp)
{
	t_shell		*shell;
	(void)envp;
	//REVIEW -> APAGAR LINHA DEBAIXO
	char *envp1[] = {"aaa=primeira", "var2=1", "var3=", "var", NULL};
	char *args[] = {"export", "", "1var=", "var2 =", "var2=2", "var3", "var=", "var4", NULL};
	init_data(&shell, argc, argv, envp1);
	export_builtin(shell, args);
	char *args0[] = {"export", NULL};
	export_builtin(shell, args0);
	char *args1[] = {"unset", "aaa", "v1var", "var3", "1VAR", "", NULL};
	unset_builtin(shell, args1);
	char *args2[] = {"export", NULL};
	export_builtin(shell, args2);
	env_builtin(shell->envp_lst);
 	while (1)
	{
		shell->cmd = readline("minishell$ ");
		check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
			shell->cmd, "Read line failed");
		if (shell->cmd[0] != '\0')
		{
			add_history(shell->cmd);
			handle_input(shell->cmd);
			free(shell->cmd);
		}
	}
	free_exit_error(shell, 0, "teste");
	return (0);
} */

