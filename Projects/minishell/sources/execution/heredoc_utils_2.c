/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdunkel <fdunkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:20:56 by fdunkel           #+#    #+#             */
/*   Updated: 2024/11/15 14:42:48 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/heredocs.h"

void	setup_heredoc_signals(void)
{
	signal(SIGINT, hdoc_signal);
	signal(SIGQUIT, SIG_IGN);
}

int	create_heredoc_pipe(t_h_doc *cur_hdoc, char **env_array, t_msh *msh_core)
{
	if (pipe(cur_hdoc->fds) == PIPE_ERROR)
	{
		free(env_array);
		msh_core->exit_status = 1;
		cmd_exit(NULL, msh_core);
	}
	return (0);
}

void	wait_heredoc_child(pid_t fork_return, t_msh *msh_core)
{
	int	exit_info;

	signal(SIGINT, SIG_IGN);
	waitpid(fork_return, &exit_info, 0);
	signal(SIGINT, handle_sigint);
	if (WIFEXITED(exit_info))
	{
		msh_core->exit_status = WEXITSTATUS(exit_info);
		if (msh_core->exit_status == 130)
			msh_core->heredoc_error = true;
	}
}
