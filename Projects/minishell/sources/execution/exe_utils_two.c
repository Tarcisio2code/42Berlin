/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_utils_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:03:25 by fdunkel           #+#    #+#             */
/*   Updated: 2024/11/15 16:19:45 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libraries.h"
#include "../../include/execution.h"
#include "../../include/environment.h"
#include "../../include/parser.h"
#include "../libft/libft.h"

bool	has_rel_path(char *cmd_array[])
{
	if (!cmd_array || !cmd_array[0])
		return (false);
	return (cmd_array[0][0] == '.');
}

bool	has_abs_path(char *cmd_array[])
{
	if (!cmd_array || !cmd_array[0])
		return (false);
	return (cmd_array[0][0] == '/');
}

char	*get_path_from_env(char **env_path, char *cmd_name)
{
	char		*path_with_cmd;
	int			i;
	struct stat	file_info;

	i = 0;
	path_with_cmd = NULL;
	if (env_path == NULL)
		return (NULL);
	while (env_path[i] != NULL)
	{
		path_with_cmd = ft_strjoin(env_path[i], cmd_name);
		if (stat(path_with_cmd, &file_info) == EXIT_SUCCESS)
			return (path_with_cmd);
		free(path_with_cmd);
		i++;
	}
	return (NULL);
}

bool	ends_with_minishell(const char *str)
{
	const char	*suffix;
	size_t		str_len;
	size_t		suffix_len;

	suffix = "minishell";
	str_len = ft_strlen(str);
	suffix_len = ft_strlen(suffix);
	if (str_len < suffix_len)
		return (false);
	return (ft_strncmp(str + str_len - suffix_len, suffix, suffix_len) == 0);
}

void	increment_shlvl(t_list *env_list)
{
	t_list	*current;
	char	*env_var;
	int		shlvl;
	char	*new_value;

	current = env_list;
	while (current)
	{
		env_var = (char *)current->content;
		if (ft_strncmp(env_var, "SHLVL=", 6) == 0)
		{
			shlvl = ft_atoi(env_var + 6);
			shlvl++;
			new_value = ft_itoa(shlvl);
			malloc_error_check(new_value);
			change_env_var(env_list, "SHLVL", new_value);
			free(new_value);
			return ;
		}
		current = current->next;
	}
}
