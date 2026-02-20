/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_pipes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:43:33 by fdunkel             #+#    #+#           */
/*   Updated: 2024/11/15 16:06:08 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipes.h"
#include "../../include/parser.h"
#include "../../include/redirections.h"

int	**init_pipes(int num_pipes)
{
	int	i;
	int	**pipes;

	i = -1;
	pipes = malloc(sizeof(int *) * num_pipes);
	malloc_error_check(pipes);
	while (++i < (num_pipes - 1))
	{
		pipes[i] = malloc(sizeof(int) * 2);
		malloc_error_check(pipes[i]);
		if (pipe(pipes[i]) == PIPE_ERROR)
			malloc_error_check(pipes[i]);
	}
	pipes[i] = NULL;
	return (pipes);
}

void	setup_pipes(int **pipes, t_cmd *cmd, int max_index)
{
	if (max_index == 0)
		return ;
	if (cmd->index == 0)
	{
		if (!cmd->redir_out)
			dup2(pipes[0][1], STDOUT_FILENO);
	}
	else if (cmd->index == max_index)
	{
		if (!cmd->redir_in && !cmd->has_heredoc)
			dup2(pipes[cmd->index - 1][0], STDIN_FILENO);
	}
	else
	{
		if (!cmd->redir_in && !cmd->has_heredoc)
			dup2(pipes[cmd->index - 1][0], STDIN_FILENO);
		if (!cmd->redir_out)
			dup2(pipes[cmd->index][1], STDOUT_FILENO);
	}
}

void	close_all_pipes(int	**pipes, int num_pipes)
{
	int	i;

	i = -1;
	while (++i < num_pipes)
	{
		if (close(pipes[i][0]) == -1)
			perror("close");
		if (close(pipes[i][1]) == -1)
			perror("close");
	}
}
