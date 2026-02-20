/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 13:47:57 by fdunkel           #+#    #+#             */
/*   Updated: 2026/02/13 16:17:36 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "libraries.h"

void	execute_builtin(t_cmd *cmd, t_list **env_list, t_msh *msh_core);
void	execute_cmd(t_cmd *cmd, t_cmd_table *cmd_table, t_msh *msh_core);
void	execute_main(t_msh *msh_core);
int		n_of_paths(char **path);
char	**path_w_slash(t_msh *msh_core);
void	find_path(t_cmd *cmd, char **env_path);
bool	cmd_is_builtin(t_cmd *cmd);
void	wait_for_children(t_msh *msh_core, t_cmd *first_cmd);
void	process_external_cmd(t_cmd *cmd, t_cmd_table *cmd_table,
			char **path_slash, t_msh *msh_core);
void	default_stdin_stdout(char *action, int *saved_stdin, int *saved_stdout);
bool	ends_with_minishell(const char *str);
void	increment_shlvl(t_list *env_list);

bool	has_rel_path(char *cmd_array[]);

bool	has_abs_path(char *cmd_array[]);

char	*get_path_from_env(char **env_path, char *cmd_name);
void	setup_signal_handling(bool is_child);
void	update_exit_status(t_msh *msh_core, t_cmd *last_cmd, 
			int exit_info, bool signaled);
t_cmd	*get_last_command(t_cmd *first_cmd);

#endif