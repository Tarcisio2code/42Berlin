/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdunkel <fdunkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:12:08 by fdunkel           #+#    #+#             */
/*   Updated: 2024/11/15 16:22:21 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/heredocs.h"

bool	check_delim(char *expanded_line, t_h_doc *cur_hdoc)
{
	int	delimiter_length;
	int	line_length;

	delimiter_length = ft_strlen(cur_hdoc->delimiter);
	line_length = ft_strlen(expanded_line);
	if (delimiter_length == line_length
		&& !ft_strncmp(cur_hdoc->delimiter, expanded_line, delimiter_length))
		return (true);
	return (false);
}

void	handle_delim_exit(t_h_doc *cur_hdoc, t_delim_data *data)
{
	close(cur_hdoc->fds[1]);
	free(data->line);
	free(data->expanded_line);
	free_two_dim_array(data->env);
	data->msh_core->exit_status = 0;
	free_env_list(data->msh_core->envp);
	free_everything(data->msh_core);
	exit(0);
}

void	handle_eof_exit(t_h_doc *cur_hdoc, char **env, t_msh *msh_core)
{
	print_shell_error(
		"warning: here-document delimited by end-of-file (wanted `eof')",
		cur_hdoc->delimiter);
	close(cur_hdoc->fds[1]);
	free_two_dim_array(env);
	msh_core->exit_status = 0;
	free_everything(msh_core);
	exit(0);
}

char	*get_expanded_line(char *line, t_h_doc *cur_hdoc, char **env,
	t_msh *msh_core)
{
	char	*expanded_line;

	expanded_line = NULL;
	if (!(cur_hdoc->delimiter[0] == '"'
			&& cur_hdoc->delimiter[ft_strlen(cur_hdoc->delimiter) - 1] == '"'))
	{
		expanded_line = expand_heredoc(line, msh_core->exit_status, env);
		if (!expanded_line)
			expanded_line = ft_strdup(line);
	}
	else
		expanded_line = ft_strdup(line);
	return (expanded_line);
}
