/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:27:31 by tsilva            #+#    #+#             */
/*   Updated: 2024/11/18 17:34:36 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/history.h"

char	*get_user_input(void)
{
	char	*input_line;

	input_line = readline(GREEN"minishell> "RESET);
	if (!input_line)
		return (NULL);
	if (input_line[0] != '\0')
		add_history(input_line);
	return (input_line);
}
