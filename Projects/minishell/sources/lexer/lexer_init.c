/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdunkel <fdunkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:39:12 by fdunkel           #+#    #+#             */
/*   Updated: 2024/11/15 16:04:46 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lexer.h"

void	init_lexer(t_msh *msh_core)
{
	msh_core->lexer = malloc (sizeof(t_lexer));
	msh_core->lexer->n_of_tokens = 0;
	msh_core->lexer->token_list = NULL;
	msh_core->lexer->type_of_token = -1;
}

int	token_type(char c)
{
	int	type;

	if (c == '|')
		type = PIPE;
	else if (c == '\'')
		type = SINGLE_QUOTE;
	else if (c == '\"')
		type = DBL_QUOTE;
	else if (c == '>' || c == '<')
		type = REDIR;
	else if (c == '\0')
		type = CHAR_NULL;
	else
		type = WORD;
	return (type);
}

int	token_length(char *input)
{
	int	token_len;

	token_len = 0;
	if (*input == '|' || *input == '<' || *input == '>')
	{
		if ((*input == '<' && *(input + 1) == '<')
			|| (*input == '>' && *(input + 1) == '>'))
			return (2);
		return (1);
	}
	while (*input && !char_is_delimiter(*input))
	{
		token_len++;
		input++;
	}
	return (token_len);
}

void	mark_concat(t_token *token, t_token **prev_tok, int wspace_count)
{
	int	prev_type;

	if (token != NULL && *prev_tok != NULL)
	{
		prev_type = (*prev_tok)->type;
		if (wspace_count == 0 && (prev_type == WORD
				|| (prev_type == SINGLE_QUOTE || prev_type == DBL_QUOTE))
			&& prev_type != PIPE && token->type != PIPE
			&& token->type != REDIR)
			(*prev_tok)->concat_next = 1;
	}
}
