/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdunkel <fdunkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:56:03 by tsilva            #+#    #+#             */
/*   Updated: 2024/11/15 16:14:01 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include "libraries.h"

int			cmd_echo(t_cmd *cmd);
int			cmd_cd(t_cmd *cmd, t_list *env_list);
int			cmd_pwd(t_list *env_list);
int			cmd_env(t_list **env_list, t_cmd *cmd);
int			cmd_export(t_list **env_list, t_cmd *cmd);
int			cmd_unset(t_list **env_list, char **keys);
int			cmd_exit(char **argv, t_msh *msh_core);
int			is_valid_number(const char *str);
void		swap_content(t_list *ptr);
t_list		*clone_env_list(t_list *env_list);
bool		is_numeric(char *str);
int			exit_arg_error(char **argv);
long long	custom_strtol(const char *str, char **endptr, int base);
void		handle_exit_arg(char *arg, char **argv, t_msh *msh_core);
void		cleanup_cd(char *old_pwd, char *new_path, char *msg_error);
bool		handle_exit_arg_return(int exit_arg_return, t_msh *msh_core);

#endif
