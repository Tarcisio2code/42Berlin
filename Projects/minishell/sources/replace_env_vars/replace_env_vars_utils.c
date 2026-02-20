/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env_vars_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:05:33 by tsilva            #+#    #+#             */
/*   Updated: 2024/11/08 13:31:37 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libraries.h"

int	is_valid_var_name(char *str)
{
	char	*name_var;
	char	*name_end;

	if (*str != '$')
		return (0);
	str = str + 1;
	name_var = str;
	name_end = name_var;
	if (ft_isdigit(name_var[0]))
		name_end++;
	while (*name_end && !ft_isdigit(name_var[0]))
	{
		if ((ft_isalnum(*name_end) == 0 && *name_end != '_'))
			break ;
		name_end++;
	}
	return (name_end - name_var);
}

int	is_not_quote(t_token *token)
{
	return (token->type != SINGLE_QUOTE && token->type != DBL_QUOTE);
}

char	*clean_env_value(const char *value)
{
	char	*trimmed;
	char	*result;
	char	**split;
	int		i;

	trimmed = ft_strtrim(value, " ");
	malloc_error_check(trimmed);
	split = ft_split(trimmed, ' ');
	free(trimmed);
	if (!split || !split[0])
		return (free_two_dim_array(split), NULL);
	result = ft_strdup(split[0]);
	if (!result)
		return (free_two_dim_array(split), NULL);
	i = 0;
	while (split[++i])
	{
		result = join_and_free(result, " ", 1, 0);
		result = join_and_free(result, split[i], 1, 0);
	}
	free_two_dim_array(split);
	return (result);
}

char	*join_and_free(char *s1, char *s2, int free_s1, int free_s2)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	if (free_s1)
		free(s1);
	if (free_s2)
		free(s2);
	malloc_error_check(result);
	return (result);
}

void	delete_token(t_token **token_list, t_token *token_to_delete)
{
	t_token	*current;
	t_token	*prev;

	if (!token_list || !*token_list || !token_to_delete)
		return ;
	current = *token_list;
	prev = NULL;
	while (current && current != token_to_delete)
	{
		prev = current;
		current = current->next;
	}
	if (!current)
		return ;
	if (!prev)
		*token_list = current->next;
	else
		prev->next = current->next;
	free(token_to_delete->data);
	free(token_to_delete);
}
