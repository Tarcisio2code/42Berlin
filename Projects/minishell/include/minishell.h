/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdunkel <fdunkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:30:00 by fdunkel           #+#    #+#             */
/*   Updated: 2024/11/13 12:30:00 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../include/libraries.h"

void	init_msh(t_msh *msh_core);
void	init_minishell(t_msh *msh_core, char **envp, t_list **env_list);
int		handle_input(char *input, t_msh *msh_core);
int		prepare_execution(t_msh *msh_core, char *input);
int		run_minishell(t_msh *msh_core);
int		handle_ctrl_d(char *input, t_msh *msh_core);
int		main(int argc, char **argv, char **envp);

#endif /* MINISHELL_H */
