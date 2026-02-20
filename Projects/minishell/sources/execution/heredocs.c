/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdunkel <fdunkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:43:33 by fdunkel           #+#    #+#             */
/*   Updated: 2024/11/15 16:19:14 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/heredocs.h"

int	handle_heredoc(t_h_doc *cur_hdoc, char **env_array, t_msh *msh_core)
{
	pid_t	fork_return;

	if (create_heredoc_pipe(cur_hdoc, env_array, msh_core))
		return (1);
	fork_return = fork();
	if (fork_return == 0)
	{
		setup_heredoc_signals();
		fill_heredoc(cur_hdoc, env_array, msh_core);
	}
	wait_heredoc_child(fork_return, msh_core);
	close(cur_hdoc->fds[1]);
	return (0);
}

void	setup_heredocs(t_h_doc *hdoc_list, t_msh *msh_core)
{
	t_h_doc	*cur_hdoc;
	char	**env_array;

	cur_hdoc = hdoc_list;
	env_array = convert_env_to_arr(msh_core->envp);
	while (cur_hdoc)
	{
		if (handle_heredoc(cur_hdoc, env_array, msh_core))
			break ;
		cur_hdoc = cur_hdoc->next;
	}
	free_two_dim_array(env_array);
}

void	fill_heredoc(t_h_doc *cur_hdoc, char **env, t_msh *msh_core)
{
	char			*line;
	char			*expanded_line;
	t_delim_data	data;

	close(cur_hdoc->fds[0]);
	while (true)
	{
		line = readline("> ");
		if (!line)
			handle_eof_exit(cur_hdoc, env, msh_core);
		expanded_line = get_expanded_line(line, cur_hdoc, env, msh_core);
		if (check_delim(expanded_line, cur_hdoc))
		{
			data = (t_delim_data){line, expanded_line, env, msh_core};
			handle_delim_exit(cur_hdoc, &data);
		}
		write(cur_hdoc->fds[1], expanded_line, ft_strlen(expanded_line));
		write(cur_hdoc->fds[1], "\n", 1);
		free(line);
		free(expanded_line);
	}
}

void	link_heredoc_to_cmd(t_cmd_table *cmd_table)
{
	t_cmd	*cur_cmd;
	t_h_doc	*orig_heredoc;

	if (!cmd_table || !cmd_table->heredoc)
		return ;
	cur_cmd = cmd_table->entry;
	orig_heredoc = cmd_table->heredoc;
	while (cur_cmd)
	{
		if (cur_cmd->has_heredoc == true && cmd_table->heredoc)
		{
			if (cmd_table->heredoc->fds)
				cur_cmd->heredoc_ptr = cmd_table->heredoc;
			cmd_table->heredoc = cmd_table->heredoc->next;
		}
		cur_cmd = cur_cmd->next;
	}
	cmd_table->heredoc = orig_heredoc;
}

t_h_doc	*init_heredoc(void)
{
	t_h_doc	*new_heredoc;

	new_heredoc = malloc(sizeof(t_h_doc));
	if (!new_heredoc)
		return (NULL);
	new_heredoc->delimiter = NULL;
	new_heredoc->fds = malloc(sizeof(int) * 2);
	if (!new_heredoc->fds)
	{
		free(new_heredoc);
		return (NULL);
	}
	new_heredoc->fds[0] = -1;
	new_heredoc->fds[1] = -1;
	new_heredoc->next = NULL;
	return (new_heredoc);
}
