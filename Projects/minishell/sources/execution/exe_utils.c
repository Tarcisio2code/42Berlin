/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:22:51 by fdunkel           #+#    #+#             */
/*   Updated: 2024/11/15 16:17:17 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libraries.h"
#include "../../include/execution.h"
#include "../../include/environment.h"
#include "../../include/parser.h"
#include "../libft/libft.h"

int	n_of_paths(char **path)
{
	int	length;

	length = 0;
	while (path[length])
		length++;
	return (length);
}

char	**path_w_slash(t_msh *msh_core)
{
	char	*paths_as_string;
	char	**paths_array;
	char	**path_array;
	int		path_len;
	int		i;

	paths_as_string = get_env_var(msh_core->envp, "PATH");
	if (paths_as_string == NULL)
		return (NULL);
	paths_array = ft_split(paths_as_string, ':');
	path_len = n_of_paths(paths_array);
	i = 0;
	path_array = (char **) malloc(sizeof(char *) * (path_len + 1));
	malloc_error_check(path_array);
	while (i < path_len)
	{
		path_array[i] = ft_strjoin(paths_array[i], "/");
		i++;
	}
	path_array[i] = NULL;
	free(paths_as_string);
	free_two_dim_array(paths_array);
	return (path_array);
}

void	find_path(t_cmd *cmd, char **env_path)
{
	char	*cmd_name;

	cmd_name = cmd->cmd_array[0];
	if (has_rel_path(cmd->cmd_array) || has_abs_path(cmd->cmd_array))
	{
		cmd->path = ft_strdup(cmd->cmd_array[0]);
		malloc_error_check(cmd->path);
	}
	else
	{
		cmd->path = get_path_from_env(env_path, cmd_name);
		if (cmd->path == NULL)
			cmd->path = ft_strdup(cmd_name);
		malloc_error_check(cmd->path);
	}
}

bool	cmd_is_builtin(t_cmd *cmd)
{
	char	*command;

	if (!cmd || !cmd->cmd_array)
	{
		printf("\ncmd_is_builtin: token list is empty\n");
		return (false);
	}
	command = cmd->cmd_array[0];
	if (ft_strncmp(command, "echo", 5) == 0
		|| ft_strncmp(command, "cd", 3) == 0
		|| ft_strncmp(command, "pwd", 4) == 0
		|| ft_strncmp(command, "export", 7) == 0
		|| ft_strncmp(command, "unset", 6) == 0
		|| ft_strncmp(command, "env", 4) == 0
		|| ft_strncmp(command, "exit", 5) == 0)
		return (true);
	return (false);
}

void	default_stdin_stdout(char *action, int *saved_stdin, int *saved_stdout)
{
	if (ft_strncmp(action, "save", 5) == 0)
	{
		*saved_stdin = dup(STDIN_FILENO);
		*saved_stdout = dup(STDOUT_FILENO);
	}
	else if (ft_strncmp(action, "reset", 6) == 0)
	{
		dup2(*saved_stdin, STDIN_FILENO);
		dup2(*saved_stdout, STDOUT_FILENO);
		close(*saved_stdin);
		close(*saved_stdout);
	}
	else
		printf("default_stdin_stdout ERROR\n");
}
