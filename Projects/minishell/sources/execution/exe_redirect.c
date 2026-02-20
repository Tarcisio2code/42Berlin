/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 20:18:16 by fdunkel           #+#    #+#             */
/*   Updated: 2024/11/15 16:24:17 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/redirections.h"

int	setup_redirs(t_redir *redirs, t_cmd *cmd, t_msh *msh_core)
{
	int	in_size;
	int	out_size;
	int	ret;

	in_size = -1;
	out_size = -1;
	if (redirs == NULL && !cmd->has_heredoc)
		return (0);
	alloc_redirs(cmd, redirs, &in_size, &out_size);
	ret = open_files(redirs, cmd);
	msh_core->exit_status = ret;
	if (ret != 0)
		return (ret);
	if (cmd->has_heredoc)
	{
		dup2(cmd->heredoc_ptr->fds[0], STDIN_FILENO);
		close(cmd->heredoc_ptr->fds[0]);
	}
	else if (cmd->redir_in && !cmd->has_heredoc)
		dup2(cmd->redir_in[in_size - 1], STDIN_FILENO);
	if (cmd->redir_out)
		dup2(cmd->redir_out[out_size - 1], STDOUT_FILENO);
	close_files(cmd, in_size, out_size);
	return (ret);
}

void	alloc_redirs(t_cmd *cmd, t_redir *redirs, int *in_size, int *out_size)
{
	*in_size = count_redirs(redirs, REDIR_IN);
	*out_size = count_redirs(redirs, REDIR_OUT)
		+ count_redirs(redirs, REDIR_APPEND);
	if (*in_size > 0)
	{
		cmd->redir_in = malloc(sizeof(int) * (*in_size));
		malloc_error_check(cmd->redir_in);
	}
	if (*out_size > 0)
	{
		cmd->redir_out = malloc(sizeof(int) * (*out_size));
		malloc_error_check(cmd->redir_out);
	}
}

int	handle_redir_out(t_cmd *cmd, t_redir *redirs, int *out_index)
{
	int	ret;

	if (redirs->type == REDIR_APPEND)
		cmd->redir_out[*out_index] = open(redirs->file, O_WRONLY | O_CREAT
				| O_APPEND, 0666);
	else
		cmd->redir_out[*out_index] = open(redirs->file, O_WRONLY | O_CREAT
				| O_TRUNC, 0666);
	ret = file_err(cmd->redir_out[*out_index], OPEN_ERROR, redirs->file);
	if (ret != 0)
		return (ret);
	(*out_index)++;
	return (0);
}

int	open_files(t_redir *redirs, t_cmd *cmd)
{
	int	in_index;
	int	out_index;
	int	ret;

	in_index = 0;
	out_index = 0;
	while (redirs != NULL)
	{
		if (redirs->type == REDIR_IN)
		{
			cmd->redir_in[in_index] = open(redirs->file, O_RDONLY);
			ret = file_err(cmd->redir_in[in_index], OPEN_ERROR, redirs->file);
			if (ret != 0)
				return (ret);
			in_index++;
		}
		else if (redirs->type == REDIR_OUT || redirs->type == REDIR_APPEND)
		{
			ret = handle_redir_out(cmd, redirs, &out_index);
			if (ret != 0)
				return (ret);
		}
		redirs = redirs->next;
	}
	return (0);
}

void	close_files(t_cmd *cmd, int in_size, int out_size)
{
	int	i;
	int	close_ret_val;

	i = -1;
	while (++i < in_size)
	{
		close_ret_val = close(cmd->redir_in[i]);
		file_err(close_ret_val, CLOSE_ERROR, "input file");
	}
	i = -1;
	while (++i < out_size)
	{
		close_ret_val = close(cmd->redir_out[i]);
		file_err(close_ret_val, CLOSE_ERROR, "output file");
	}
}
