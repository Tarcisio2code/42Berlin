/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:41:42 by tsilva            #+#    #+#             */
/*   Updated: 2024/11/15 16:02:57 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libraries.h"
#include "../../include/execution.h"
#include "../../include/environment.h"
#include "../../include/redirections.h"
#include "../../include/pipes.h"
#include "../../include/heredocs.h"

static	void	initialize_execution(t_msh *msh_core, t_cmd_table **cmd_table,
									t_cmd **first_cmd)
{
	if (!msh_core || !msh_core->cmd_table || !msh_core->cmd_table->entry)
		return ;
	*cmd_table = msh_core->cmd_table;
	*first_cmd = (*cmd_table)->entry;
	msh_core->path_slash = path_w_slash(msh_core);
	if ((*cmd_table)->n_cmds >= 2)
		(*cmd_table)->pipes = init_pipes((*cmd_table)->n_cmds);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	setup_heredocs((*cmd_table)->heredoc, msh_core);
	link_heredoc_to_cmd(*cmd_table);
}

static bool	handle_redirections(t_cmd *cmd, t_msh *msh_core)
{
	if (setup_redirs(cmd->redirs, cmd, msh_core) != 0)
	{
		cmd->redir_error = true;
		msh_core->exit_status = 1;
		return (false);
	}
	return (true);
}

static void	execute_command(t_cmd *cmd, t_cmd_table *cmd_table, t_msh *msh_core)
{
	if (cmd->redir_error || !((cmd)->cmd_array && (cmd)->cmd_array[0]))
		return ;
	setup_pipes(cmd_table->pipes, cmd, cmd_table->n_cmds - 1);
	if (cmd_is_builtin(cmd))
		execute_builtin(cmd, &msh_core->envp, msh_core);
	else
		process_external_cmd(cmd, cmd_table, msh_core->path_slash, msh_core);
}

static void	cleanup_execution(t_msh *msh_core, t_cmd_table *cmd_table,
								t_cmd *first_cmd)
{
	msh_core->cmd_table->entry = first_cmd;
	close_all_pipes(cmd_table->pipes, cmd_table->n_cmds - 1);
	free_two_dim_array(msh_core->path_slash);
	msh_core->path_slash = NULL;
	wait_for_children(msh_core, first_cmd);
}

void	execute_main(t_msh *msh_core)
{
	t_cmd_table	*cmd_table;
	t_cmd		*first_cmd;
	int			saved_stdin;
	int			saved_stdout;

	initialize_execution(msh_core, &cmd_table, &first_cmd);
	while (cmd_table->entry)
	{
		default_stdin_stdout("save", &saved_stdin, &saved_stdout);
		if (msh_core->heredoc_error)
		{
			msh_core->heredoc_error = false;
			return ;
		}
		if (handle_redirections(cmd_table->entry, msh_core))
			execute_command(cmd_table->entry, cmd_table, msh_core);
		default_stdin_stdout("reset", &saved_stdin, &saved_stdout);
		cmd_table->entry = cmd_table->entry->next;
	}
	cleanup_execution(msh_core, cmd_table, first_cmd);
}
