/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdunkel <fdunkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:17:11 by fdunkel           #+#    #+#             */
/*   Updated: 2024/11/15 14:04:36 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOCS_H
# define HEREDOCS_H

# include "libraries.h"

/* Heredoc initialization and setup */
t_h_doc	*init_heredoc(void);
void	setup_heredocs(t_h_doc *hdoc_list, t_msh *msh_core);
void	link_heredoc_to_cmd(t_cmd_table *cmd_table);

/* Core heredoc handling */
int		handle_heredoc(t_h_doc *cur_hdoc, char **env_array, t_msh *msh_core);
void	fill_heredoc(t_h_doc *cur_hdoc, char **env, t_msh *msh_core);

/* Heredoc utilities - Part 1 */
bool	check_delim(char *expanded_line, t_h_doc *cur_hdoc);
void	handle_delim_exit(t_h_doc *cur_hdoc, t_delim_data *data);
void	handle_eof_exit(t_h_doc *cur_hdoc, char **env, t_msh *msh_core);
char	*get_expanded_line(char *line, t_h_doc *cur_hdoc, char **env,
			t_msh *msh_core);

/* Heredoc utilities - Part 2 */
void	setup_heredoc_signals(void);
int		create_heredoc_pipe(t_h_doc *cur_hdoc, char **env, t_msh *msh_core);
void	wait_heredoc_child(pid_t fork_return, t_msh *msh_core);

#endif
