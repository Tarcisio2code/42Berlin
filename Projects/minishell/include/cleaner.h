/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdunkel <fdunkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:04:15 by fdunkel           #+#    #+#             */
/*   Updated: 2024/11/15 13:18:32 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANER_H
# define CLEANER_H

# include "libraries.h"

void	free_pid_list(t_cmd_table *cmd_table);
void	free_redirects(t_redir *redirs);
void	free_heredocs(t_h_doc *heredoc);
void	free_cmd(t_cmd *cmd);
void	free_cmd_table(t_cmd_table *cmd_table);
void	free_everything(t_msh *msh_core);
void	free_lexer(t_msh *msh_core);
void	free_two_dim_array(char **path_wslash);
void	free_env_list(t_list *env_list);
void	free_and_null(void *ptr);

#endif
