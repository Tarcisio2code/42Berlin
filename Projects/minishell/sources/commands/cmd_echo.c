/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:00:21 by tsilva            #+#    #+#             */
/*   Updated: 2024/10/28 16:26:17 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/commands.h"

static int	has_valid_newline(char *str);

int	cmd_echo(t_cmd *cmd)
{
	int		no_newline;
	char	**curr_arg;

	curr_arg = cmd->cmd_array + 1;
	no_newline = has_valid_newline(*curr_arg);
	while (no_newline && has_valid_newline(*curr_arg))
		curr_arg++;
	while (*curr_arg) 
	{
		ft_putstr_fd(*curr_arg, STDOUT_FILENO);
		if (*(curr_arg + 1)) 
			ft_putchar_fd(' ', STDOUT_FILENO);
		curr_arg++;
	}
	if (!no_newline)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (EXIT_SUCCESS);
}

static int	has_valid_newline(char *str)
{
	if (str && *str == '-')
	{
		str++;
		while (*str)
		{
			if (!(*str++ == 'n'))
				return (0);
		}
	}
	else
		return (0);
	return (1);
}
