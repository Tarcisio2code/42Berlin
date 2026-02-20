/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_user_input_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:40:05 by tsilva            #+#    #+#             */
/*   Updated: 2024/11/12 20:51:20 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/input_handling.h"

int	in_quotes(const char *input)
{
	int	i;
	int	quote_type;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\'' || input[i] == '"')
		{
			quote_type = input[i++];
			while (input[i] && input[i] != quote_type)
				i++;
			if (!input[i] || input[i] == quote_type)
				return (1);
		}
		i++;
	}
	return (0);
}

int	msg_error(char *str)
{
	printf("minishell: %s\n", str);
	return (1);
}

char	*remove_whitespace(char *str)
{
	char	*result;
	int		i;
	int		j;
	size_t	len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (!is_whitespace(str[i]))
		{
			result[j] = str[i];
			j++;
		}
		i++;
	}
	result[j] = '\0';
	return (result);
}

int	check_pipe(char **input, int has_cmd)
{
	if (!has_cmd)
		return (msg_error(ERR_PIPE));
	if (*(*input + 1) == '|')
		return (msg_error(ERR_PIPE_DOUBLE));
	(*input)++;
	while (**input && **input == ' ')
		(*input)++;
	if (!**input)
		return (msg_error(ERR_PIPE));
	return (0);
}

int	check_redir(char **redir)
{
	if (ft_strncmp(*redir, ">>>>", 4) == 0)
		return (msg_error(ERR_REDIR_OUT_DOUBLE));
	else if (ft_strncmp(*redir, ">>>", 3) == 0)
		return (msg_error(ERR_REDIR_OUT));
	else if (ft_strncmp(*redir, "<<<<<", 5) == 0)
		return (msg_error(ERR_REDIR_IN_DOUBLE));
	else if (ft_strncmp(*redir, "<<<<", 4) == 0)
		return (msg_error(ERR_REDIR_IN));
	else if (ft_strncmp(*redir, "><", 2) == 0)
		return (msg_error(ERR_REDIR_IN));
	else if (**redir && ((**redir == '>' || **redir == '<')
			&& !*(*redir + 1)))
		return (msg_error(ERR_NEWLINE));
	return (0);
}
