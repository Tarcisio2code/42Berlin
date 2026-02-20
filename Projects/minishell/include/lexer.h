/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdunkel <fdunkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:58:47 by fdunkel           #+#    #+#             */
/*   Updated: 2024/11/15 11:42:39 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "libraries.h"

bool	is_whitespace(char c);
int		token_type(char c);
int		token_length(char *input);
bool	char_is_delimiter(char c);
int		lexer_main(char *input, t_msh *msh_core);
void	ft_lstadd_back_tok(t_token **lst, t_token *new_token);
void	init_lexer(t_msh *msh_core);
void	handle_quotes_error(int matching_quote_found, t_msh *msh_core);
t_token	*create_token(char *input, int *increment, int type, t_msh *msh_core);
void	move_to_next_token(char **input, int *increm, int *wspace_count);
void	mark_concat(t_token *token, t_token **prev_token, int wspace_count);
int		handle_quotes(char *inp, t_token *token, int type, int *increm);

#endif
