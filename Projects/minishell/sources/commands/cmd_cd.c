/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:27:28 by tsilva            #+#    #+#             */
/*   Updated: 2024/11/19 09:52:50 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/commands.h"

static int	set_new_path(char *new_path, char **current_path);
static int	set_pwd(t_list *env_list, char *current_path);
static int	handle_home_path(t_list *env_list, char **current_path);
static char	*assign_current_path(char *old_pwd, char *tmp_pwd);

int	cmd_cd(t_cmd *cmd, t_list *env_list)
{
	char	*current_path;

	if (cmd->cmd_array[1] && cmd->n_args > 1)
	{
		print_shell_error("too many arguments", "cd");
		return (EXIT_FAILURE);
	}
	if (cmd->cmd_array[1] && !*cmd->cmd_array[1])
		return (EXIT_SUCCESS);
	current_path = NULL;
	if (!cmd->cmd_array[1])
	{
		if (!handle_home_path(env_list, &current_path))
			return (EXIT_FAILURE);
	}
	else if (!set_new_path(cmd->cmd_array[1], &current_path))
		return (EXIT_FAILURE);
	if (current_path && !set_pwd(env_list, current_path))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static char	*assign_current_path(char *old_pwd, char *tmp_pwd)
{
	if (!old_pwd)
		return (ft_strdup(tmp_pwd));
	return (ft_strdup(old_pwd));
}

static int	set_new_path(char *new_path, char **current_path)
{
	char	*msg_error;
	char	*old_pwd;
	char	*tmp_pwd;

	msg_error = NULL;
	old_pwd = getcwd(NULL, 0);
	if (chdir(new_path) != 0)
	{
		msg_error = join_and_free("cd: ", new_path, 0, 0);
		print_shell_error(strerror(errno), msg_error);
		cleanup_cd(old_pwd, NULL, msg_error);
		return (0);
	}
	tmp_pwd = getcwd(NULL, 0);
	if (!tmp_pwd && !old_pwd)
	{
		print_shell_error("error retrieving current directory: getcwd: cannot "
			"access parent directories", "cd");
		cleanup_cd(old_pwd, NULL, NULL);
		return (0);
	}
	*current_path = assign_current_path(old_pwd, tmp_pwd);
	cleanup_cd(old_pwd, tmp_pwd, NULL);
	return (1);
}

static int	set_pwd(t_list *env_list, char *current_path)
{
	t_list	*new_env;

	if (!has_env_var(env_list, "OLDPWD"))
	{
		new_env = ft_lstnew(ft_strdup("OLDPWD="));
		if (!new_env)
		{
			free(current_path);
			exit(EXIT_FAILURE);
		}
		ft_lstadd_back(&env_list, new_env);
	}
	change_env_var(env_list, "OLDPWD", current_path);
	free(current_path);
	current_path = getcwd(NULL, 0);
	if (!current_path)
	{
		print_shell_error(strerror(errno), "cd");
		return (0);
	}
	change_env_var(env_list, "PWD", current_path);
	free(current_path);
	return (1);
}

static int	handle_home_path(t_list *env_list, char **current_path)
{
	char	*home;

	home = get_env_var(env_list, "HOME");
	if (!home)
	{
		print_shell_error("cd: HOME not set", "");
		return (0);
	}
	if (!set_new_path(home, current_path))
	{
		free(home);
		return (0);
	}
	free(home);
	return (1);
}
