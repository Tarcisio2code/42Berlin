/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:56:03 by tsilva            #+#    #+#             */
/*   Updated: 2024/11/11 19:19:05 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_HANDLING_H
# define INPUT_HANDLING_H

# include "libraries.h"

# define ERR_PIPE "syntax error near unexpected token `|'"
# define ERR_PIPE_DOUBLE "syntax error near unexpected token `||'"
# define ERR_REDIR_OUT_DOUBLE "syntax error near unexpected token `>>'"
# define ERR_REDIR_OUT "syntax error near unexpected token `>'"
# define ERR_REDIR_IN_DOUBLE "syntax error near unexpected token `<<'"
# define ERR_REDIR_IN "syntax error near unexpected token `<'"
# define ERR_NEWLINE "syntax error near unexpected token `newline'"

int		validate_user_input(const char *input);
int		in_quotes(const char *input);
int		check_pipe(char **input, int has_cmd);
int		check_redir(char **redir);
char	*remove_whitespace(char *str);
int		msg_error(char *str);

#endif
