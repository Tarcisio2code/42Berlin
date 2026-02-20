/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:00:42 by tsilva            #+#    #+#             */
/*   Updated: 2024/11/15 16:24:07 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTIONS_H
# define REDIRECTIONS_H

# include "libraries.h"

# define WRITE_PERM 0777
# define OPEN_ERROR -1
# define CLOSE_ERROR -1

int				setup_redirs(t_redir *redirs, t_cmd *cmd, t_msh *msh_core);
void			alloc_redirs(t_cmd *cmd, t_redir *redirs, int *in, int *out);
int				open_files(t_redir *redirs, t_cmd *cmd);
void			close_files(t_cmd *cmd, int in_size, int out_size);
int				count_redirs(t_redir *redirs, t_redir_types type);
int				file_err(int value, int err, char *file);
t_redir_types	get_redir_type(char *data);
int				handle_redir_out(t_cmd *cmd, t_redir *redirs, int *out_index);

#endif
