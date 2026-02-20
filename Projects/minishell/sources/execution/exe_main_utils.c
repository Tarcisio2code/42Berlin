/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_main_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:41:42 by tsilva            #+#    #+#             */
/*   Updated: 2024/11/15 11:56:20 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libraries.h"
#include "../../include/execution.h"
#include "../../include/environment.h"
#include "../../include/redirections.h"
#include "../../include/pipes.h"
#include "../../include/heredocs.h"

void	setup_signal_handling(bool is_child)
{
	if (is_child)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_IGN);
	}
	else
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
}

void	update_exit_status(t_msh *msh_core, t_cmd *last_cmd, int exit_info,
			bool signaled)
{
	if (last_cmd->redir_error)
		msh_core->exit_status = 1;
	else if (WIFEXITED(exit_info))
		msh_core->exit_status = WEXITSTATUS(exit_info);
	else if (signaled)
		msh_core->exit_status = WTERMSIG(exit_info) + 128;
}

t_cmd	*get_last_command(t_cmd *first_cmd)
{
	t_cmd	*last_cmd;

	last_cmd = first_cmd;
	while (last_cmd && last_cmd->next)
		last_cmd = last_cmd->next;
	return (last_cmd);
}
