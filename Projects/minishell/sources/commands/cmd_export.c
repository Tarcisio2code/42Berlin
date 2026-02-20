/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 10:44:36 by tsilva            #+#    #+#             */
/*   Updated: 2024/11/19 10:29:50 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/commands.h"

static void	sort_env_list(t_list *env_list);
static int	print_env_list(t_list *clone_list);
static int	set_env_var(t_list **env_list, char *new_var, size_t size);
static int	is_valid_identifier(char *identifier);

int	cmd_export(t_list **env_list, t_cmd *cmd)
{
	char	*equal_sign;
	char	**new_var;
	size_t	size;

	new_var = cmd->cmd_array + 1;
	if (!*new_var)
		return (print_env_list(clone_env_list(*env_list)));
	while (*new_var)
	{
		if (!is_valid_identifier(*new_var))
			return (EXIT_FAILURE);
		else
		{
			equal_sign = ft_strchr(*new_var, '=');
			if (!equal_sign)
				size = ft_strlen(*new_var);
			else
				size = equal_sign - *new_var;
			if (!set_env_var(env_list, *new_var, size))
				return (EXIT_FAILURE);
		}
		new_var++;
	}
	return (EXIT_SUCCESS);
}

static int	is_valid_identifier(char *identifier)
{
	char	*valid_var;
	char	first_char;

	valid_var = identifier;
	while ((*valid_var) && !(*valid_var == '='))
	{
		if (!ft_isalnum(*valid_var) && *valid_var != '_')
		{
			valid_var = NULL;
			break ;
		}
		valid_var++;
	}
	first_char = identifier[0];
	if (!valid_var || (!ft_isalpha(first_char) && first_char != '_'))
	{
		ft_putstr_fd(" not a valid identifier\n", STDERR_FILENO);
		return (0);
	}
	return (1);
}

static int	print_env_list(t_list *clone_list)
{
	t_list	*current;
	char	*equal_sign;
	char	*env_var;

	sort_env_list(clone_list);
	current = clone_list;
	while (current)
	{
		env_var = (char *)current->content;
		equal_sign = ft_strchr(env_var, '=');
		if (equal_sign)
		{
			*equal_sign = '\0';
			printf("declare -x %s=\"%s\"\n", env_var, equal_sign + 1);
			*equal_sign = '=';
		}
		else
			printf("declare -x %s\n", env_var);
		current = current->next;
	}
	ft_lstclear(&clone_list, free);
	return (EXIT_SUCCESS);
}

static void	sort_env_list(t_list *env_list)
{
	int		swapped;
	int		len;
	char	*curr_var;
	t_list	*ptr;
	t_list	*last;

	swapped = 1;
	last = NULL;
	while (swapped)
	{
		swapped = 0;
		ptr = env_list;
		while (ptr->next != last)
		{
			curr_var = (char *)ptr->content;
			len = ft_strlen(curr_var);
			if (ft_strncmp(curr_var, (char *)ptr->next->content, len) > 0)
			{
				swap_content(ptr);
				swapped = 1;
			}
			ptr = ptr->next;
		}
		last = ptr;
	}
}

static int	set_env_var(t_list **env_list, char *new_var, size_t size)
{
	t_list	*current;
	char	*current_var;
	char	*new_content;

	current = *env_list;
	while (current)
	{
		current_var = (char *)current->content;
		if (ft_strncmp(current_var, new_var, size) == 0
			&& (current_var[size] == '=' || !current_var[size]))
		{
			free(current->content);
			current->content = ft_strdup(new_var);
			malloc_error_check(current);
			return (1);
		}
		current = current->next;
	}
	new_content = ft_strdup(new_var);
	malloc_error_check(new_content);
	current = ft_lstnew(new_content);
	malloc_error_check(current);
	ft_lstadd_front(env_list, current);
	return (1);
}
