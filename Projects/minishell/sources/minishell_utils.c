/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdunkel <fdunkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:51:37 by fdunkel           #+#    #+#             */
/*   Updated: 2024/11/18 18:04:58 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	init_msh(t_msh *msh_core)
{
	msh_core->lexer = NULL;
	msh_core->cmd_table = NULL;
	msh_core->exit_status = 0;
	msh_core->minishell_pid = 0;
	msh_core->envp = NULL;
	msh_core->path_slash = NULL;
	msh_core->heredoc_error = false;
	msh_core->first_home_path = NULL;
}

int	handle_ctrl_d(char *input, t_msh *msh_core)
{
	if (!input || input == NULL)
	{
		if (isatty(STDIN_FILENO))
			printf("exit\n");
		msh_core->exit_status = 0;
		return (1);
	}
	return (0);
}
