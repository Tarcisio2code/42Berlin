/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdunkel <fdunkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:35:06 by fdunkel             #+#    #+#           */
/*   Updated: 2024/11/15 13:13:52 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPES_H
# define PIPES_H

# include "libraries.h"
# define PIPE_ERROR -1

int		**init_pipes(int num_pipes);
void	setup_pipes(int **pipes, t_cmd *cmd, int max_index);
void	close_all_pipes(int **pipes, int num_pipes);
#endif
