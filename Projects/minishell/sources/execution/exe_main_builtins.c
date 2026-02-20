/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_main_builtins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdunkel <fdunkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:41:42 by fdunkel             #+#    #+#           */
/*   Updated: 2024/11/18 14:58:21 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libraries.h"
#include "../../include/execution.h"
#include "../../include/environment.h"
#include "../../include/redirections.h"
#include "../../include/pipes.h"
#include "../../include/heredocs.h"

static void	run_builtin(t_cmd *entry, t_list **envp, t_msh *msh_core)
{
	if (!ft_strncmp(entry->cmd_array[0], "echo", 5))
		msh_core->exit_status = cmd_echo(entry);
	else if (!ft_strncmp(entry->cmd_array[0], "cd", 3))
		msh_core->exit_status = cmd_cd(entry, *envp);
	else if (!ft_strncmp(entry->cmd_array[0], "pwd", 4))
		msh_core->exit_status = cmd_pwd(*envp);
	else if (!ft_strncmp(entry->cmd_array[0], "export", 7))
		msh_core->exit_status = cmd_export(envp, entry);
	else if (!ft_strncmp(entry->cmd_array[0], "unset", 6))
		msh_core->exit_status = cmd_unset(envp, entry->cmd_array);
	else if (!ft_strncmp(entry->cmd_array[0], "env", 4))
		msh_core->exit_status = cmd_env(envp, entry);
	else if (!ft_strncmp(entry->cmd_array[0], "exit", 5))
		msh_core->exit_status = cmd_exit(entry->cmd_array, msh_core);
}

void	execute_builtin(t_cmd *entry, t_list **envp, t_msh *msh_core)
{
	pid_t	pid;
	t_list	*pid_child;

	if (msh_core->cmd_table->n_cmds == 1)
		run_builtin(entry, envp, msh_core);
	else
	{
		pid = fork();
		if (pid < 0)
			exit(EXIT_FAILURE);
		if (pid == 0)
		{
			run_builtin(entry, envp, msh_core);
			exit(msh_core->exit_status);
		}
		pid_child = ft_lstnew((void *)(long)pid);
		malloc_error_check(pid_child);
		ft_lstadd_back(&msh_core->cmd_table->children_pids, pid_child);
	}
}
