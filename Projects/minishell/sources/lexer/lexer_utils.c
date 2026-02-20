/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdunkel <fdunkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:52:53 by fdunkel           #+#    #+#             */
/*   Updated: 2024/11/15 16:05:49 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lexer.h"

void	ft_lstadd_back_tok(t_token **lst, t_token *new_token)
{
	t_token	*tmp;

	if (*lst == NULL)
	{
		*lst = new_token;
		return ;
	}
	tmp = *lst;
	while (tmp -> next)
		tmp = tmp -> next;
	tmp -> next = new_token;
}

bool	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f');
}

bool	is_quote(char c)
{
	if (c == '\'' || c == '\"')
		return (true);
	return (false);
}

bool	char_is_delimiter(char c)
{
	if (is_whitespace(c) || is_quote(c) || c == '<' || c == '>'
		|| c == '|' || c == '\0')
		return (true);
	return (false);
}

void	handle_quotes_error(int match_found_flag, t_msh *msh_core)
{
	if (match_found_flag == false)
	{
		printf("minishell: matching quote missing\n");
		msh_core->exit_status = 1;
	}
}
