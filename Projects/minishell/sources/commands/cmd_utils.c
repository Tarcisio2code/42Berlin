/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:33:13 by tsilva            #+#    #+#             */
/*   Updated: 2024/11/15 16:10:52 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/commands.h"

int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	swap_content(t_list *ptr)
{
	void	*temp;

	temp = ptr->content;
	ptr->content = ptr->next->content;
	ptr->next->content = temp;
}

t_list	*create_new_node(const char *content)
{
	char	*content_copy;
	t_list	*new_node;

	content_copy = ft_strdup(content);
	if (!content_copy)
		return (NULL);
	new_node = ft_lstnew(content_copy);
	if (!new_node)
	{
		free(content_copy);
		return (NULL);
	}
	return (new_node);
}

t_list	*clone_env_list(t_list *env_list)
{
	t_list	*copy_head;
	t_list	*new_node;

	copy_head = NULL;
	while (env_list)
	{
		new_node = create_new_node(env_list->content);
		if (!new_node)
		{
			ft_lstclear(&copy_head, free);
			return (NULL);
		}
		ft_lstadd_front(&copy_head, new_node);
		if (env_list->next && *(char *)env_list->next->content == '_')
			env_list = env_list->next->next;
		else
			env_list = env_list->next;
	}
	return (copy_head);
}

void	cleanup_cd(char *old_pwd, char *new_path, char *msg_error)
{
	if (old_pwd)
	{
		free(old_pwd);
		old_pwd = NULL;
	}
	if (new_path)
	{
		free(new_path);
		new_path = NULL;
	}
	if (msg_error)
	{
		free(msg_error);
		msg_error = NULL;
	}
}
