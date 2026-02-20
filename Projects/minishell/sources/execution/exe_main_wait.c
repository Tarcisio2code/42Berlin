/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_main_wait.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:41:42 by tsilva            #+#    #+#             */
/*   Updated: 2024/11/15 16:04:19 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libraries.h"
#include "../../include/execution.h"
#include "../../include/environment.h"
#include "../../include/redirections.h"
#include "../../include/pipes.h"
#include "../../include/heredocs.h"

static void	handle_signal_status(int exit_info)
{
	if (WTERMSIG(exit_info) == SIGINT)
		write(1, "\n", 1);
	else if (WTERMSIG(exit_info) == SIGQUIT)
		ft_putstr_fd("Quit (core dumped)\n", 2);
}

static bool	is_last_child_pid(pid_t current_pid, t_list *children_pids)
{
	pid_t	last_pid;

	if (!children_pids)
		return (false);
	last_pid = (pid_t)(intptr_t)ft_lstlast(children_pids)->content;
	return (current_pid == last_pid);
}

static void	wait_for_each_child(t_msh *msh_core, t_cmd *last_cmd,
								int *exit_info, bool *signaled)
{
	pid_t	pid;

	while (msh_core->cmd_table->children_pids)
	{
		pid = (pid_t)(intptr_t)msh_core->cmd_table->children_pids->content;
		waitpid(pid, exit_info, 0);
		if (WIFSIGNALED(*exit_info))
		{
			*signaled = true;
			handle_signal_status(*exit_info);
		}
		if (is_last_child_pid(pid, msh_core->cmd_table->children_pids))
			update_exit_status(msh_core, last_cmd, *exit_info, *signaled);
		ft_list_del_first(&msh_core->cmd_table->children_pids);
	}
}

void	wait_for_children(t_msh *msh_core, t_cmd *first_cmd)
{
	int		exit_info;
	bool	signaled;
	t_cmd	*last_cmd;

	last_cmd = get_last_command(first_cmd);
	exit_info = 0;
	signaled = false;
	wait_for_each_child(msh_core, last_cmd, &exit_info, &signaled);
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
}
