/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_user_input.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:40:05 by tsilva            #+#    #+#             */
/*   Updated: 2024/11/18 17:17:12 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/input_handling.h"

static int	invalid_redirection(const char *input);
static int	invalid_pipe(const char *input);
static int	process_pipe_chars(char **curr_char, int *has_cmd, char *temp);

int	validate_user_input(const char *input)
{
	if (!in_quotes(input))
	{
		if (invalid_redirection(input))
			return (1);
		if (ft_strchr(input, '|') && invalid_pipe(input))
			return (1);
	}
	return (0);
}

static int	invalid_redirection(const char *input)
{
	char	*curr;

	curr = (char *)input;
	while (curr && *curr)
	{
		if (*curr == '>' || *curr == '<')
		{
			if (check_redir(&curr))
				return (1);
			curr++;
			if (*curr == '>' || *curr == '<')
				curr++;
			while (*curr == ' ')
				curr++;
			if (*curr == '>' || *curr == '<')
				return (msg_error(ERR_REDIR_OUT));
			if (!*curr)
				return (msg_error(ERR_NEWLINE));
			continue ;
		}
		curr++;
	}
	return (0);
}

static int	invalid_pipe(const char *input)
{
	int		has_cmd;
	char	*curr_char;
	char	*temp;

	has_cmd = 0;
	curr_char = remove_whitespace((char *)input);
	temp = curr_char;
	if (*curr_char == '|')
	{
		free(temp);
		return (msg_error(ERR_PIPE));
	}
	if (process_pipe_chars(&curr_char, &has_cmd, temp))
		return (1);
	if (*(curr_char - 1) == '|')
	{
		free(temp);
		return (msg_error(ERR_PIPE));
	}
	free(temp);
	return (0);
}

static int	process_pipe_chars(char **curr_char, int *has_cmd, char *temp)
{
	while (*curr_char && **curr_char)
	{
		if (**curr_char != '|' && **curr_char != '<' && **curr_char != '>'
			&& **curr_char != ';' && **curr_char != '&')
			*has_cmd = 1;
		if (**curr_char == '|')
		{
			if (check_pipe(curr_char, *has_cmd))
			{
				free(temp);
				return (1);
			}
			*has_cmd = 0;
		}
		if (*curr_char)
			(*curr_char)++;
	}
	return (0);
}
