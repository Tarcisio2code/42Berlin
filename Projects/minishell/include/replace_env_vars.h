/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env_vars.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:56:03 by tsilva            #+#    #+#             */
/*   Updated: 2024/11/14 12:23:06 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_ENV_VARS_H
# define REPLACE_ENV_VARS_H

# include "libraries.h"

int		is_not_quote(t_token *token);
void	replace_env_vars(t_msh *msh_core, char **environment, int status);
int		has_valid_name(char **curr_data, char **new_data, char **non_var);
void	update_token(t_token *current_token, char **new_data);
char	*extract_non_var(char **curr_data, int size);
int		is_valid_var_name(char *str);
char	*expand_heredoc(char *line, int exit_status, char **environment);
void	delete_token(t_token **token_list, t_token *token_to_delete);
char	*clean_env_value(const char *value);
char	*join_and_free(char *s1, char *s2, int free_s1, int free_s2);
void	expand_var(char **new_data, char **data, char **environment);
void	expand_status(char **new_data, char **curr_data, int exit_status);

#endif
