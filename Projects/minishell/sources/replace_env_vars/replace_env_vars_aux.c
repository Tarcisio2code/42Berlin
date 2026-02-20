/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env_vars_aux.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:58:21 by tsilva            #+#    #+#             */
/*   Updated: 2024/11/08 13:55:32 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libraries.h"

void	expand_var(char **new_data, char **data, char **environment)
{
	int		pos;
	int		name_size;
	char	*cleaned_value;

	pos = 0;
	name_size = is_valid_var_name(*data);
	while (environment[pos])
	{
		if (ft_strncmp(environment[pos], *data + 1, name_size) == 0
			&& environment[pos][name_size] == '=')
		{
			cleaned_value = clean_env_value(environment[pos] + name_size + 1);
			if (*new_data)
				*new_data = join_and_free(*new_data, cleaned_value, 1, 0);
			else
				*new_data = ft_strdup(cleaned_value);
			malloc_error_check(*new_data);
			free(cleaned_value);
			break ;
		}
		pos++;
	}
	if (!*new_data)
		*new_data = ft_strdup("");
	*data = *data + name_size + 1;
}

void	expand_status(char **new_data, char **curr_data, int exit_status)
{
	char	*str_status;

	str_status = ft_itoa(exit_status);
	if (*new_data)
		*new_data = join_and_free(*new_data, str_status, 1, 0);
	else
		*new_data = ft_strdup(str_status);
	malloc_error_check(*new_data);
	free(str_status);
	*curr_data = *curr_data + 2;
}

int	has_valid_name(char **curr_data, char **new_data, char **non_var)
{
	char	*start;
	char	*end;

	start = *curr_data;
	while (*start)
	{
		end = ft_strchr(start, '$');
		if (end && (*(end + 1) == '?' || is_valid_var_name(end)))
			break ;
		start++;
	}
	if (!*start)
	{
		if (*new_data && **curr_data)
			*new_data = join_and_free(*new_data, *curr_data, 1, 0);
		return (0);
	}
	*non_var = extract_non_var(&*curr_data, end - *curr_data);
	return (1);
}

void	update_token(t_token *current_token, char **new_data)
{
	free(current_token->data);
	current_token->data = ft_strdup(*new_data);
	free(*new_data);
	malloc_error_check(current_token->data);
}

char	*extract_non_var(char **curr_data, int size)
{
	char	*new;

	if (size)
	{
		new = malloc(sizeof(char) * size + 1);
		malloc_error_check(new);
		ft_memcpy(new, *curr_data, size);
		new[size] = '\0';
		*curr_data = *curr_data + size;
		return (new);
	}
	else
		return (NULL);
}
