/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-souz <mde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 08:29:56 by mde-souz          #+#    #+#             */
/*   Updated: 2024/12/09 09:27:22 by mde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*get_home(t_shell *shell, char *actual_path)
{
	t_list	*home_node;

	home_node = ft_lstfind_name(shell->envp_lst, "HOME");
	if (!home_node || !((t_var *)(home_node->content))->value)
	{
		msg_error(VAR_NOT_SET, "cd", "HOME");
		ft_lstremove_mem_node(&(shell->mem_allocation.ptr_mem_list), \
			actual_path);
		shell->exit_status = EXIT_FAILURE;
		return (NULL);
	}
	return (((t_var *)(home_node->content))->value);
}

char	*get_oldpwd(t_shell *shell, char *actual_path)
{
	t_list	*oldpwd_node;

	oldpwd_node = ft_lstfind_name(shell->envp_lst, "OLDPWD");
	if (!oldpwd_node || !((t_var *)(oldpwd_node->content))->value)
	{
		msg_error(VAR_NOT_SET, "cd", "OLDPWD");
		ft_lstremove_mem_node(&(shell->mem_allocation.ptr_mem_list), \
			actual_path);
		shell->exit_status = EXIT_FAILURE;
		return (NULL);
	}
	return (((t_var *)(oldpwd_node->content))->value);
}

void	set_pwd_and_oldpwd(t_shell *shell, char *value)
{
	t_var	*pwd;
	t_var	*old_pwd;

	pwd = (t_var *)ft_calloc(sizeof(t_var), 1);
	check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
			pwd, "Calloc failed");
	pwd->value = safe_getcwd(NULL, 0, shell);
	pwd->name = ft_strdup("PWD");
	check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
			pwd->name, "Calloc failed");
	add_or_edit_var(shell, pwd);
	old_pwd = (t_var *)ft_calloc(sizeof(t_var), 1);
	check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
			old_pwd, "Calloc failed");
	old_pwd->name = ft_strdup("OLDPWD");
	check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
			old_pwd->name, "Calloc failed");
	old_pwd->value = value;
	add_or_edit_var(shell, old_pwd);
	shell->exit_status = EXIT_SUCCESS;
}

void	change_directory(t_shell *shell, char *path)
{
	char	*actual_path;

	actual_path = safe_getcwd(NULL, 0, shell);
	if (!path || !ft_strcmp(path, "~"))
	{
		path = get_home(shell, actual_path);
		if (!path)
			return ;
	}
	else if (!ft_strcmp(path, "-"))
	{
		path = get_oldpwd(shell, actual_path);
		if (!path)
			return ;
	}
	if (chdir(path) == SUCCESS)
		set_pwd_and_oldpwd(shell, actual_path);
	else
	{
		ft_lstremove_mem_node(&(shell->mem_allocation.ptr_mem_list), \
			actual_path);
		msg_error(GENERAL_ERROR, "cd: ", path);
		shell->exit_status = EXIT_FAILURE;
	}
}

void	cd_builtin(t_shell *shell, char **cd_args)
{
	if (cd_args[1] && cd_args[2])
	{
		msg_error(TOO_MANY_ARGS, "cd");
		shell->exit_status = EXIT_FAILURE;
		return ;
	}
	if (cd_args[1])
	{
		if (!ft_strcmp(cd_args[1], ""))
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
	char **args;
	(void)envp;
	//REVIEW -> APAGAR LINHA DEBAIXO
	//char *envp1[] = {"aaa=primeira", "var2=1", "var3=", "var", NULL};
	//char *args[] = {"cd", "src", NULL};
	init_data(&shell, argc, argv, envp);
	char *args3[] = {"cd", "", NULL};
	ft_printf(1, RED"%s %c%c\n"RESET, "cd", '"','"');
	cd_builtin(shell, args3);
	pwd_builtin(shell);
	ft_printf(1, "%d\n", shell->exit_status);
	char *args4[] = {"cd", NULL};
	ft_printf(1, RED"%s\n"RESET, "cd");
	cd_builtin(shell, args4);
	pwd_builtin(shell);
	ft_printf(1, "%d\n", shell->exit_status);
	char *args5[] = {"cd", "nonexistent", NULL};
	ft_printf(1, RED"%s %s\n"RESET, "cd", "nonexistent");
	cd_builtin(shell, args5);
	pwd_builtin(shell);
	ft_printf(1, "%d\n", shell->exit_status);
	char *args6[] = {"cd", "..", NULL};
	ft_printf(1, RED"%s %s\n"RESET, "cd", "..");
	cd_builtin(shell, args6);
	pwd_builtin(shell);
	ft_printf(1, "%d\n", shell->exit_status);
	char *args7[] = {"unset", "HOME", NULL};
	unset_builtin(shell, args7);
	char *args8[] = {"cd", NULL};
	ft_printf(1, RED"%s\n"RESET, "cd");
	cd_builtin(shell, args8);
	pwd_builtin(shell);
	ft_printf(1, "%d\n", shell->exit_status);
	char *args9[] = {"cd", "um", "dois", NULL};
	ft_printf(1, RED"%s %s %s\n"RESET, "cd", "um", "dois");
	cd_builtin(shell, args9);
	pwd_builtin(shell);
	ft_printf(1, "%d\n", shell->exit_status);
	// char *args10[] = {"exit", NULL};
	// exit_builtin(shell, args10);
	while (1)
	{
		shell->cmd = readline("minishell$ ");
		check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
			shell->cmd, "Read line failed");
		if (shell->cmd[0] != '\0')
		{
			args = parse_input(shell->cmd);
			check_mem_alloc(shell, &(shell->mem_allocation.ptr_mem_list), \
			args, "Read line failed");
			if (!ft_strcmp(args[0], "cd"))
				cd_builtin(shell, args);
			else if (!ft_strcmp(args[0], "exit"))
				exit_builtin(shell, args);
			ft_printf(1, "exit_status: %d\n", shell->exit_status);
			pwd_builtin(shell);
			add_history(shell->cmd);
			//handle_input(shell->cmd);
			//free(shell->cmd);
			ft_lstremove_mem_node(&(shell->mem_allocation.ptr_mem_list), \
				shell->cmd);
		}
	}
	free_exit_error(shell, 0, "teste");
 	return (0);
} */