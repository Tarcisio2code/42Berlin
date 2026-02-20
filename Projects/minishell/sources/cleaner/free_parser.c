/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:05:41 by tsilva            #+#    #+#             */
/*   Updated: 2024/11/18 11:37:33 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cleaner.h"

void	free_redirects(t_redir *redirs)
{
	t_redir	*temp;
	t_redir	*next;

	if (!redirs)
		return ;
	temp = redirs;
	while (temp)
	{
		next = temp->next;
		free_and_null(temp->file);
		free_and_null(temp);
		temp = next;
	}
}

void	free_heredocs(t_h_doc *heredoc)
{
	t_h_doc	*temp;

	if (!heredoc)
		return ;
	while (heredoc)
	{
		temp = heredoc;
		heredoc = heredoc->next;
		free_and_null(temp->delimiter);
		free_and_null(temp->fds);
		free_and_null(temp);
	}
}

void	free_cmd(t_cmd *cmd)
{
	int	i;

	if (!cmd)
		return ;
	if (cmd->cmd_array)
	{
		i = 0;
		while (cmd->cmd_array[i])
		{
			free_and_null(cmd->cmd_array[i]);
			i++;
		}
		free_and_null(cmd->cmd_array);
	}
	free_and_null(cmd->path);
	free_and_null(cmd->redir_in);
	free_and_null(cmd->redir_out);
	free_redirects(cmd->redirs);
	cmd->heredoc_ptr = NULL;
	free_and_null(cmd);
}

void	free_cmd_table(t_cmd_table *cmd_table)
{
	t_cmd	*temp;
	int		i;

	if (!cmd_table)
		return ;
	while (cmd_table->entry)
	{
		temp = cmd_table->entry;
		cmd_table->entry = cmd_table->entry->next;
		free_cmd(temp);
	}
	if (cmd_table->pipes)
	{
		i = 0;
		while (i < cmd_table->n_cmds - 1)
		{
			free_and_null(cmd_table->pipes[i]);
			i++;
		}
		free_and_null(cmd_table->pipes);
	}
	free_heredocs(cmd_table->heredoc);
	free_pid_list(cmd_table);
	cmd_table->heredoc = NULL;
	free_and_null(cmd_table);
}

void	free_lexer(t_msh *msh_core)
{
	t_token	*current_token;
	t_token	*next_token;

	if (msh_core == NULL || msh_core->lexer == NULL)
		return ;
	current_token = msh_core->lexer->token_list;
	while (current_token != NULL)
	{
		next_token = current_token->next;
		free_and_null(current_token->data);
		free(current_token);
		current_token = next_token;
	}
	free_and_null(msh_core->lexer);
}
