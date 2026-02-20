/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdunkel <fdunkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:39:47 by fdunkel           #+#    #+#             */
/*   Updated: 2024/11/15 15:18:53 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

t_redir_types	get_redir_type(char *data)
{
	if (data[0] == '<' && data[1] == '<')
		return (REDIR_HEREDOC);
	else if (data[0] == '<')
		return (REDIR_IN);
	else if (data[0] == '>' && data[1] == '>')
		return (REDIR_APPEND);
	else if (data[0] == '>')
		return (REDIR_OUT);
	return (-1);
}

int	cmd_length(t_token *cur_token)
{
	int	length_of_cmd;

	length_of_cmd = 0;
	while (cur_token && cur_token->type != PIPE)
	{
		while (cur_token && cur_token->type == REDIR)
		{
			cur_token = cur_token->next->next;
		}
		if (cur_token == NULL)
			break ;
		length_of_cmd++;
		cur_token = cur_token->next;
	}
	return (length_of_cmd);
}

void	handle_redirects(t_token **cur_token, t_redir **redirs, t_cmd *cmd)
{
	t_redir	*redirect;

	redirect = NULL;
	if (ft_strncmp((*cur_token)->data, "<<", 2) == 0)
	{
		*cur_token = (*cur_token)->next->next;
		cmd->has_heredoc = true;
	}
	else
	{
		redirect = fill_redirect(cur_token);
		add_redirect(redirs, redirect);
	}
}

void	add_redirect(t_redir **redirs, t_redir *new)
{
	t_redir	*current;

	current = *redirs;
	if (*redirs == NULL)
		*redirs = new;
	else
	{
		current = *redirs;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
}

t_redir	*fill_redirect(t_token **cur_token)
{
	t_redir	*redirect;

	redirect = init_redir();
	if (*cur_token && (*cur_token)->type == REDIR)
	{
		redirect->type = get_redir_type((*cur_token)->data);
		*cur_token = (*cur_token)->next;
		redirect->file = ft_strdup((*cur_token)->data);
		malloc_error_check(redirect->file);
		*cur_token = (*cur_token)->next;
	}
	return (redirect);
}
