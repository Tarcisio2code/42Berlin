/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:27:46 by tsilva            #+#    #+#             */
/*   Updated: 2024/11/15 16:11:31 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/commands.h"

static void	handle_unset_pwd(char *key);
static int	is_matching_env(const char *content, const char *key, size_t len);
static int	unset_single_key(t_list **env_list, char *key);

int	cmd_unset(t_list **env_list, char **keys)
{
	int	i;

	if (!keys)
		return (EXIT_SUCCESS);
	i = 0;
	while (keys[i])
	{
		unset_single_key(env_list, keys[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	unset_single_key(t_list **env_list, char *key)
{
	t_list	*current;
	t_list	*prev;
	size_t	len;

	current = *env_list;
	prev = NULL;
	len = ft_strlen(key);
	while (current)
	{
		if (is_matching_env(current->content, key, len))
		{
			if (prev == NULL)
				*env_list = current->next;
			else
				prev->next = current->next;
			ft_lstdelone(current, free);
			handle_unset_pwd(key);
			return (EXIT_SUCCESS);
		}
		prev = current;
		current = current->next;
	}
	return (EXIT_SUCCESS);
}

static void	handle_unset_pwd(char *key)
{
	char	*cwd;

	if (ft_strncmp(key, "PWD", 3) == 0)
	{
		cwd = getcwd(NULL, 0);
		if (!cwd)
		{
			if (chdir("/") != 0)
				perror("chdir failed");
			cwd = getcwd(NULL, 0);
			free(cwd);
		}
		else
			free(cwd);
	}
}

static int	is_matching_env(const char *content, const char *key, size_t len)
{
	return (ft_strncmp(content, key, len) == 0
		&& (content[len] == '=' || content[len] == '\0'));
}
