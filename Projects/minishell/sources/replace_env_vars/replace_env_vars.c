/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env_vars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:05:33 by tsilva            #+#    #+#             */
/*   Updated: 2024/11/15 15:12:09 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libraries.h"

static void	expand_home(t_token *curr_token, char **new_data, char *home);
static void	find_var(char *curr_data, char **new_data, char **env, int status);
static int	to_expand(t_token *curr_token, t_token *next_token);

void	replace_env_vars(t_msh *msh_core, char **environment, int status)
{
	t_token	*current_token;
	t_token	*next_token;
	char	*new_data;

	current_token = msh_core->lexer->token_list;
	while (current_token)
	{
		next_token = current_token->next;
		if (to_expand(current_token, next_token))
		{
			new_data = NULL;
			expand_home(current_token, &new_data, msh_core->first_home_path);
			find_var(current_token->data, &new_data, environment, status);
			if (new_data && !*new_data && is_not_quote(current_token))
			{
				free(new_data);
				delete_token(&msh_core->lexer->token_list, current_token);
				msh_core->lexer->n_of_tokens--;
			}
			else if (new_data && current_token->type != SINGLE_QUOTE)
				update_token(current_token, &new_data);
		}
		current_token = next_token;
	}
}

static void	expand_home(t_token *curr_token, char **new_data, char *home)
{
	char	*curr_data;

	curr_data = curr_token->data;
	if (is_not_quote(curr_token) && (ft_strncmp(curr_data, "~/", 2) == 0
			|| (*curr_data == '~' && !*(curr_data + 1))))
	{
		*new_data = join_and_free(*new_data, home, 1, 0);
	}
}

static void	find_var(char *curr_data, char **new_data, char **env, int status)
{
	char	*non_var;

	non_var = NULL;
	if (*curr_data == '~' && *(curr_data + 1) != '$')
		curr_data++;
	while (has_valid_name(&curr_data, new_data, &non_var))
	{
		if (non_var && !*new_data)
		{
			*new_data = ft_strdup(non_var);
			malloc_error_check(*new_data);
		}
		else if (*new_data && non_var)
			*new_data = join_and_free(*new_data, non_var, 1, 0);
		if (ft_strncmp(curr_data, "$?", 2) == 0)
			expand_status(new_data, &curr_data, status);
		else
			expand_var(new_data, &curr_data, env);
		if (non_var)
			free(non_var);
	}
}

static int	to_expand(t_token *curr_token, t_token *next_token)
{
	char	*empty_str;
	bool	is_home;
	bool	is_home_and_escaped;

	empty_str = NULL;
	is_home_and_escaped = ft_strncmp(curr_token->data, "~/", 2) == 0;
	is_home = ft_strchr(curr_token->data, '~') && is_not_quote(curr_token);
	if (is_home_and_escaped || is_home || (ft_strchr(curr_token->data, '$')
			&& curr_token->type != SINGLE_QUOTE))
	{
		if (ft_strlen(curr_token->data) == 1 && next_token
			&& !is_not_quote(next_token))
		{
			empty_str = ft_strdup("");
			update_token(curr_token, &empty_str);
			return (0);
		}
		return (1);
	}
	return (0);
}

char	*expand_heredoc(char *line, int cmd_exit_status, char **environment)
{
	char	*new_data;
	char	*curr_data;

	new_data = NULL;
	curr_data = line;
	find_var(curr_data, &new_data, environment, cmd_exit_status);
	return (new_data);
}
