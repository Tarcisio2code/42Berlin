/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:53:06 by tsilva            #+#    #+#             */
/*   Updated: 2024/11/12 13:50:40 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libraries.h"
#include "../libft/libft.h"

void	copy_envp(t_list **env_list, char **envp)
{
	t_list	*new_env;
	char	*tmp;
	int		i;

	i = 0;
	while (envp[i])
	{
		tmp = ft_strdup(envp[i]);
		malloc_error_check(tmp);
		new_env = ft_lstnew(tmp);
		if (!new_env)
		{
			free(tmp);
			exit(EXIT_FAILURE);
		}
		ft_lstadd_back(env_list, new_env);
		i++;
	}
}

char	*get_env_var(t_list *env_list, char *key)
{
	t_list	*current_key;
	size_t	key_len;

	key_len = ft_strlen(key);
	current_key = env_list;
	while (current_key)
	{
		if (ft_strncmp(current_key->content, key, key_len) == 0
			&& (((char *)current_key->content)[key_len] == '='
			|| ((char *)current_key->content)[key_len] == '\0'))
		{
			return (ft_strdup((char *)current_key->content + key_len + 1));
		}
		current_key = current_key->next;
	}
	return (NULL);
}

int	has_env_var(t_list *env_list, char *key)
{
	t_list	*current_key;
	size_t	key_len;

	key_len = ft_strlen(key);
	current_key = env_list;
	while (current_key)
	{
		if (ft_strncmp(current_key->content, key, key_len) == 0
			&& (((char *)current_key->content)[key_len] == '='
			|| ((char *)current_key->content)[key_len] == '\0'))
			return (1);
		current_key = current_key->next;
	}
	return (0);
}

void	change_env_var(t_list *env_list, char *key, char *new_value)
{
	t_list	*current;
	char	*new_entry;
	char	*env_var;
	int		size;

	current = env_list;
	size = ft_strlen(key);
	while (current)
	{
		env_var = (char *)current->content;
		if (ft_strncmp(env_var, key, size) == 0
			&& (env_var[size] == '=' || env_var[size] == '\0'))
		{
			free(current->content);
			new_entry = (char *)malloc(size + ft_strlen(new_value) + 2);
			malloc_error_check(new_entry);
			ft_strlcpy(new_entry, key, size + 1);
			ft_strlcat(new_entry, "=", size + ft_strlen(new_value) + 2);
			ft_strlcat(new_entry, new_value, size + ft_strlen(new_value) + 2);
			current->content = new_entry;
			return ;
		}
		current = current->next;
	}
}
