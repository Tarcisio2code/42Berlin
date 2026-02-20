/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdunkel <fdunkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:56:48 by fdunkel             #+#    #+#           */
/*   Updated: 2024/11/15 12:19:54 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libraries.h"

t_token			*get_last_heredoc(t_token **token);
void			create_heredoc_list(t_cmd_table *cmd_table, t_token *token);
void			add_heredoc_back(t_h_doc **head, t_h_doc *new_node);
t_redir_types	get_redir_type(char *data);
int				cmd_length(t_token *cur_token);
void			handle_redirects(t_token **cur, t_redir **redir, t_cmd *cmd);
void			add_redirect(t_redir **redirs, t_redir *new);
t_redir			*fill_redirect(t_token **cur_token);
void			fill_cmd(t_cmd *cmd, t_token **cur_token, int process_num);
void			concat_current_with_next(t_token *current);
void			concatenate_tokens(t_token *tokens);
void			process_tokens(t_msh *msh_core, t_token **cur, int process_n);
void			parser_main(t_msh *msh_core);
t_h_doc			*init_heredoc_node(void);
t_cmd_table		*init_cmd_table(void);
t_redir			*init_redir(void);
t_cmd			*init_cmd(t_token *cur_token);

#endif
