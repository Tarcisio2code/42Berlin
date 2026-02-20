/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:54:29 by tsilva            #+#    #+#             */
/*   Updated: 2024/11/15 10:46:04 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include "libraries.h"

void	copy_envp(t_list **env_list, char **envp);
char	*get_env_var(t_list *env_list, char *key);
int		has_env_var(t_list *env_list, char *key);
void	change_env_var(t_list *env_list, char *key, char *new_value);
void	clean_env_list(t_list *head);
char	**convert_env_to_arr(t_list *env);
int		ft_env_list_size(t_list *env);

#endif
