/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:38:22 by tsilva            #+#    #+#             */
/*   Updated: 2024/10/31 14:16:31 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/commands.h"

int	cmd_env(t_list **env_list, t_cmd *cmd)
{
	t_list	*current;

	current = *env_list;
	if (cmd->cmd_array[1])
	{
		print_shell_error("too many arguments", "env");
		return (EXIT_FAILURE);
	}
	else if (!current)
		ft_putstr_fd("\n", STDOUT_FILENO);
	else
	{
		while (current)
		{
			if (ft_strchr((char *)current->content, '='))
			{
				if (!current->next)
					printf("%s\n", "_=/usr/bin/env");
				else
					printf("%s\n", (char *)current->content);
			}
			current = current->next;
		}
	}
	return (EXIT_SUCCESS);
}
