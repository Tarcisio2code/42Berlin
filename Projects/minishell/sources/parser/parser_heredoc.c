/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdunkel <fdunkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 09:08:20 by fdunkel             #+#    #+#           */
/*   Updated: 2024/11/15 15:17:35 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

t_token	*get_last_heredoc(t_token **token)
{
	t_token	*temp_heredoc;

	temp_heredoc = NULL;
	while (*token)
	{
		if ((*token)->type == PIPE)
			break ;
		if (ft_strncmp((*token)->data, "<<", 2) == 0)
			temp_heredoc = *token;
		*token = (*token)->next;
	}
	return (temp_heredoc);
}

void	create_heredoc_list(t_cmd_table *cmd_table, t_token *token)
{
	t_token	*last_heredoc_token;
	t_h_doc	*new_heredoc;

	while (token)
	{
		last_heredoc_token = get_last_heredoc(&token);
		if (last_heredoc_token)
		{
			new_heredoc = init_heredoc_node();
			if (!new_heredoc)
				return ;
			new_heredoc->delimiter = ft_strdup(last_heredoc_token->next->data);
			add_heredoc_back(&cmd_table->heredoc, new_heredoc);
		}
		if (token)
			token = token->next;
	}
}

void	add_heredoc_back(t_h_doc **head, t_h_doc *new_node)
{
	t_h_doc	*current;

	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
}
