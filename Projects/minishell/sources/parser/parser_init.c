/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdunkel <fdunkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:07:43 by fdunkel           #+#    #+#             */
/*   Updated: 2024/11/15 15:17:47 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

t_h_doc	*init_heredoc_node(void)
{
	t_h_doc	*new_heredoc;

	new_heredoc = malloc(sizeof(t_h_doc));
	if (!new_heredoc)
		return (NULL);
	new_heredoc->delimiter = NULL;
	new_heredoc->fds = malloc(sizeof(int) * 2);
	if (!new_heredoc->fds)
	{
		free(new_heredoc);
		return (NULL);
	}
	new_heredoc->fds[0] = -1;
	new_heredoc->fds[1] = -1;
	new_heredoc->next = NULL;
	return (new_heredoc);
}

t_cmd_table	*init_cmd_table(void)
{
	t_cmd_table	*cmd_table;

	cmd_table = malloc(sizeof(t_cmd_table));
	if (!cmd_table)
		return (NULL);
	cmd_table->entry = NULL;
	cmd_table->n_cmds = 0;
	cmd_table->pipes = NULL;
	cmd_table->children_pids = NULL;
	cmd_table->heredoc = NULL;
	return (cmd_table);
}

t_redir	*init_redir(void)
{
	t_redir	*new_redirect;

	new_redirect = (t_redir *)malloc(sizeof(t_redir));
	malloc_error_check(new_redirect);
	new_redirect->file = NULL;
	new_redirect->next = NULL;
	new_redirect->type = -1;
	return (new_redirect);
}

t_cmd	*init_cmd(t_token *cur_token)
{
	t_cmd	*cmd;
	int		cmd_len;

	cmd_len = cmd_length(cur_token);
	cmd = malloc(sizeof(t_cmd));
	malloc_error_check(cmd);
	cmd->cmd_array = (char **)malloc(sizeof(char *) * (cmd_len + 1));
	malloc_error_check(cmd->cmd_array);
	cmd->path = NULL;
	cmd->redirs = NULL;
	cmd->redir_in = NULL;
	cmd->redir_out = NULL;
	cmd->index = -1;
	cmd->n_args = 0;
	cmd->cmd_array[0] = NULL;
	cmd->heredoc_ptr = NULL;
	cmd->has_heredoc = false;
	cmd->redir_error = false;
	cmd->next = NULL;
	return (cmd);
}
