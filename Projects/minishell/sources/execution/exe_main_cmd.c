/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_main_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:41:42 by tsilva              #+#    #+#           */
/*   Updated: 2024/11/15 14:25:05 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libraries.h"
#include "../../include/execution.h"
#include "../../include/environment.h"
#include "../../include/redirections.h"
#include "../../include/pipes.h"
#include "../../include/heredocs.h"

static void	handle_env_and_pipes(t_cmd *cmd, t_cmd_table *cmd_table, 
								t_msh *msh_core, char ***env)
{
	if (ends_with_minishell(cmd->cmd_array[0]) == true)
		increment_shlvl(msh_core->envp);
	*env = convert_env_to_arr(msh_core->envp);
	close_all_pipes(cmd_table->pipes, cmd_table->n_cmds - 1);
}

static void	validate_path(t_cmd *cmd, t_msh *msh_core, char **env)
{
	struct stat	path_stat;

	if (stat(cmd->path, &path_stat) == 0)
	{
		if (S_ISDIR(path_stat.st_mode))
		{
			print_shell_error("Is a directory", cmd->cmd_array[0]);
			msh_core->exit_status = 126;
			cmd_exit(cmd->cmd_array, msh_core);
		}
		if (access(cmd->path, X_OK) == -1)
		{
			print_shell_error("Permission denied", cmd->cmd_array[0]);
			msh_core->exit_status = 126;
			cmd_exit(cmd->cmd_array, msh_core);
		}
	}
	else
	{
		free_two_dim_array(env);
		print_shell_error("No such file or directory", cmd->cmd_array[0]);
		msh_core->exit_status = 127;
		cmd_exit(cmd->cmd_array, msh_core);
	}
}

static void	execute_command(t_cmd *cmd, char **env, t_msh *msh_core)
{
	errno = 0;
	if (execve(cmd->path, cmd->cmd_array, env) == -1)
	{
		free_two_dim_array(env);
		print_shell_error("command not found", cmd->cmd_array[0]);
		msh_core->exit_status = 127;
		cmd_exit(cmd->cmd_array, msh_core);
	}
}

void	execute_cmd(t_cmd *cmd, t_cmd_table *cmd_table, t_msh *msh_core)
{
	char	**env;

	handle_env_and_pipes(cmd, cmd_table, msh_core, &env);
	if (cmd->cmd_array[0][0] == '.' || cmd->cmd_array[0][0] == '/')
		validate_path(cmd, msh_core, env);
	execute_command(cmd, env, msh_core);
}

void	process_external_cmd(t_cmd *cmd, t_cmd_table *cmd_table,
							char **path_slash, t_msh *msh_core)
{
	long	pid;
	t_list	*new_pid_node;

	pid = fork();
	if (pid < 0)
	{
		free_two_dim_array(path_slash);
		ft_putstr_fd("minishell: fork: Resource temporarily unavailable\n", 2);
		msh_core->exit_status = 127;
		cmd_exit(cmd->cmd_array, msh_core);
	}
	else if (pid == 0)
	{
		setup_signal_handling(true);
		find_path(cmd, path_slash);
		execute_cmd(cmd, cmd_table, msh_core);
	}
	if (pid > 0)
	{
		setup_signal_handling(false);
		new_pid_node = ft_lstnew((void *)pid);
		if (new_pid_node)
			ft_lstadd_back(&cmd_table->children_pids, new_pid_node);
	}
}
