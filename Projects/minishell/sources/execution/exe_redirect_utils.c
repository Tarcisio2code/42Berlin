/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_redirect_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 20:18:13 by fdunkel           #+#    #+#             */
/*   Updated: 2024/11/15 16:24:07 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/redirections.h"

int	file_err(int value, int err, char *file)
{
	if (value == err)
	{
		if (errno == EACCES)
			print_shell_error("Permission denied", file);
		else if (errno == ENOENT)
			print_shell_error("No such file or directory", file);
		else
			print_shell_error(strerror(errno), file);
		return (1);
	}
	return (0);
}

int	count_redirs(t_redir *redirs, t_redir_types type)
{
	int	redir_counter;

	redir_counter = 0;
	while (redirs)
	{
		if (redirs->type == type)
			redir_counter++;
		redirs = redirs->next;
	}
	return (redir_counter);
}
