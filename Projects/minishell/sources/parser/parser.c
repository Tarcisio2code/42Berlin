/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdunkel <fdunkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:16:29 by fdunkel           #+#    #+#             */
/*   Updated: 2024/11/19 12:57:29 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

void	fill_cmd(t_cmd *cmd, t_token **cur_token, int process_num)
{
	int	i;

	i = 0;
	cmd->index = process_num;
	process_num++;
	while (*cur_token && (*cur_token)->type != PIPE)
	{
		while (*cur_token && (*cur_token)->type == REDIR)
			handle_redirects(cur_token, &cmd->redirs, cmd);
		if (*cur_token == NULL || (*cur_token)->type == PIPE)
			break ;
		cmd->cmd_array[i] = ft_strdup((*cur_token)->data);
		malloc_error_check(cmd->cmd_array[i]);
		i++;
		*cur_token = (*cur_token)->next;
	}
	if (i > 0)
		cmd->n_args = i - 1;
	cmd->cmd_array[i] = NULL;
}

void	concat_current_with_next(t_token *current)
{
	t_token	*next;
	char	*new_data;
	size_t	current_len;
	size_t	next_len;

	next = current->next;
	if (!next)
		return ;
	current_len = ft_strlen(current->data);
	next_len = ft_strlen(next->data);
	new_data = malloc(current_len + next_len + 1);
	if (!new_data)
		return ;
	ft_strlcpy(new_data, current->data, current_len + 1);
	ft_strlcat(new_data, next->data, current_len + next_len + 1);
	free(current->data);
	current->data = new_data;
	current->next = next->next;
	current->concat_next = next->concat_next;
	free(next->data);
	free(next);
}

void	concatenate_tokens(t_token *tokens)
{
	t_token	*current;

	current = tokens;
	while (current && current->next)
	{
		if (current->concat_next)
			concat_current_with_next(current);
		else
			current = current->next;
	}
}

void	process_tokens(t_msh *msh_core, t_token **cur_token, int process_num)
{
	t_cmd		*new_cmd;
	t_cmd		*entry_head;

	while (*cur_token != NULL)
	{
		new_cmd = init_cmd(*cur_token);
		fill_cmd(new_cmd, cur_token, process_num);
		if (msh_core->cmd_table->entry == NULL)
		{
			msh_core->cmd_table->entry = new_cmd;
			entry_head = msh_core->cmd_table->entry;
		}
		else
		{
			msh_core->cmd_table->entry->next = new_cmd;
			msh_core->cmd_table->entry = msh_core->cmd_table->entry->next;
		}
		msh_core->cmd_table->n_cmds++;
		if (*cur_token != NULL)
			*cur_token = (*cur_token)->next;
		process_num++;
	}
	msh_core->cmd_table->entry = entry_head;
}

void	parser_main(t_msh *msh_core)
{
	t_token		*cur_token;
	int			process_num;

	process_num = 0;
	msh_core->cmd_table = init_cmd_table();
	if (!msh_core->cmd_table)
		return ;
	cur_token = msh_core->lexer->token_list;
	if (!cur_token)
	{
		free(msh_core->cmd_table);
		msh_core->cmd_table = NULL;
		return ;
	}
	concatenate_tokens(cur_token);
	create_heredoc_list(msh_core->cmd_table, cur_token);
	process_tokens(msh_core, &cur_token, process_num);
}
