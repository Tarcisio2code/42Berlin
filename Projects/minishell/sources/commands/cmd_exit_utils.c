/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exit_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdunkel <fdunkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:40:15 by fdunkel           #+#    #+#             */
/*   Updated: 2024/11/15 16:14:06 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/commands.h"

bool	is_numeric(char *str)
{
	int		i;
	bool	has_digit;

	if (!str || !*str)
		return (false);
	i = 0;
	has_digit = false;
	while (str[i] && is_whitespace(str[i]))
		i++;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1])
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			has_digit = true;
		else if (!is_whitespace(str[i]))
			return (false);
		i++;
	}
	return (has_digit);
}

int	exit_arg_error(char **argv)
{
	if (argv[1] && is_numeric(argv[1]))
	{
		if (argv[2])
		{
			print_shell_error("too many arguments", "exit");
			return (1);
		}
	}
	else if (argv[1] && !is_numeric(argv[1]))
	{
		print_shell_erro_exit("numeric argument required", argv[1]);
		return (2);
	}
	return (0);
}

bool	handle_exit_arg_return(int exit_arg_return, t_msh *msh_core)
{
	if (exit_arg_return == 2)
	{
		msh_core->exit_status = 2;
		return (true);
	}
	else if (exit_arg_return == 1)
	{
		msh_core->exit_status = -1;
		return (true);
	}
	return (false);
}

void	handle_exit_arg(char *arg, char **argv, t_msh *msh_core)
{
	char		*endptr;
	long long	exit_status;
	int			exit_arg_return;

	errno = 0;
	exit_arg_return = exit_arg_error(argv);
	if (handle_exit_arg_return(exit_arg_return, msh_core))
		return ;
	exit_status = custom_strtol(arg, &endptr, 10);
	if (errno == ERANGE)
	{
		print_shell_erro_exit("numeric argument required", argv[1]);
		msh_core->exit_status = 2;
		return ;
	}
	if (exit_status < 0)
		exit_status = 256 + (exit_status % 256);
	msh_core->exit_status = exit_status % 256;
}
