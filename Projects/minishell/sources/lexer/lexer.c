/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdunkel <fdunkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:57:21 by fdunkel           #+#    #+#             */
/*   Updated: 2024/11/15 16:01:25 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lexer.h"

void	move_to_next_token(char **input, int *increm, int *wspace_count)
{
	*wspace_count = 0;
	*input += *increm;
	while (is_whitespace(**input))
	{
		(*wspace_count)++;
		(*input)++;
	}
}

int	handle_quotes(char *inp, t_token *token, int type, int *increm)
{
	int		quoted_token_length;
	int		matching_quote_found;
	char	*saved_input;

	quoted_token_length = 0;
	matching_quote_found = 0;
	saved_input = inp;
	while (*inp != '\0')
	{
		if (token_type(*(inp)) == type)
		{
			matching_quote_found = 1;
			break ;
		}
		quoted_token_length++;
		inp++;
	}
	if (!matching_quote_found)
		return (1);
	*increm = quoted_token_length + 2;
	token->data = malloc(sizeof(char) * (quoted_token_length + 1));
	ft_strlcpy(token->data, saved_input, quoted_token_length + 1);
	return (0);
}

t_token	*create_token(char *input, int *increm, int type, t_msh *msh_core)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	malloc_error_check(token);
	token->type = type;
	token->next = NULL;
	token->concat_next = 0;
	if (type == DBL_QUOTE || type == SINGLE_QUOTE)
	{
		if (handle_quotes(input + 1, token, type, increm))
		{
			handle_quotes_error(0, msh_core);
			free(token);
			return (NULL);
		}
	}
	else
	{
		*increm = token_length(input);
		token->data = malloc(sizeof(char) * (*increm + 1));
		malloc_error_check(token->data);
		ft_strlcpy(token->data, input, *increm + 1);
	}
	return (token);
}

int	proc_tok(char **inp, t_proc_data *data, t_msh *msh)
{
	int		type;
	t_token	*token;

	move_to_next_token(inp, &data->increm, &data->wspace);
	type = token_type(**inp);
	if (type == CHAR_NULL)
		return (0);
	token = create_token(*inp, &data->increm, type, msh);
	if (!token)
		return (1);
	mark_concat(token, &data->prev, data->wspace);
	ft_lstadd_back_tok(&msh->lexer->token_list, token);
	msh->lexer->n_of_tokens++;
	data->prev = token;
	return (0);
}

// Modified lexer_main to use the new structure
int	lexer_main(char *input, t_msh *msh_core)
{
	t_proc_data	data;

	data.increm = 0;
	data.prev = NULL;
	init_lexer(msh_core);
	while (*input)
	{
		if (proc_tok(&input, &data, msh_core))
			return (1);
	}
	return (0);
}
