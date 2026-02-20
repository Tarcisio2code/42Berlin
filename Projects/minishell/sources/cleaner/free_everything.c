/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_everything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdunkel <fdunkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:28:32 by fdunkel           #+#    #+#             */
/*   Updated: 2024/11/18 16:38:04 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cleaner.h"

void	free_everything(t_msh *msh_core)
{
	if (!msh_core)
		return ;
	if (msh_core->lexer)
	{
		free_lexer(msh_core);
		msh_core->lexer = NULL;
	}
	if (msh_core->cmd_table)
	{
		free_cmd_table(msh_core->cmd_table);
		msh_core->cmd_table = NULL;
	}
	if (msh_core->path_slash)
	{
		free_two_dim_array(msh_core->path_slash);
		msh_core->path_slash = NULL;
	}
}

void	free_and_null(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	free_pid_list(t_cmd_table *cmd_table)
{
	t_list	*current;
	t_list	*next;
	int		status;

	if (!cmd_table || !cmd_table->children_pids)
		return ;
	current = cmd_table->children_pids;
	while (current)
	{
		next = current->next;
		waitpid((pid_t)(intptr_t)current->content, &status, WNOHANG);
		free(current);
		current = next;
	}
	cmd_table->children_pids = NULL;
}
