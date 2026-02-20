/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdunkel <fdunkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:42:19 by fdunkel             #+#    #+#           */
/*   Updated: 2024/11/18 16:27:59 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/commands.h"

int		exit_arg_error(char **argv);
bool	is_numeric(char *str);

static void	handle_overflow(int sign, long long *result)
{
	errno = ERANGE;
	if (sign == 1)
		*result = LLONG_MAX;
	else
		*result = LLONG_MIN;
}

static void	handle_sign_and_whitespace(const char **str, int *sign)
{
	while (is_whitespace(**str))
		(*str)++;
	if (**str == '-')
	{
		*sign = -1;
		(*str)++;
	}
	else if (**str == '+')
		(*str)++;
}

long long	custom_strtol(const char *str, char **endptr, int base)
{
	long long	result;
	int			sign;
	int			digit;

	result = 0;
	sign = 1;
	handle_sign_and_whitespace(&str, &sign);
	while (*str && isdigit(*str))
	{
		digit = *str - '0';
		if ((sign == 1 && result > (LLONG_MAX - digit) / base)
			|| (sign == -1 && (-result < (LLONG_MIN + digit) / base)))
		{
			handle_overflow(sign, &result);
			break ;
		}
		result = result * base + digit;
		str++;
	}
	if (endptr)
		*endptr = (char *)str;
	return (sign * result);
}

void	free_msh_core_resources(t_msh *msh_core)
{
	if (msh_core->envp)
	{
		free_env_list(msh_core->envp);
		msh_core->envp = NULL;
	}
	if (msh_core->first_home_path)
	{
		free(msh_core->first_home_path);
		msh_core->first_home_path = NULL;
	}
}

int	cmd_exit(char **argv, t_msh *msh_core)
{
	if (msh_core->cmd_table->n_cmds == 1 && !ft_strncmp("exit", argv[0], 5))
		ft_putstr_fd("exit\n", STDERR_FILENO);
	if (argv == NULL)
	{
		free_msh_core_resources(msh_core);
		free_everything(msh_core);
		exit (msh_core->exit_status);
	}
	if (!ft_strncmp("exit", argv[0], 5))
	{
		if (argv[1] != NULL)
			handle_exit_arg(argv[1], argv, msh_core);
		if (msh_core->exit_status == -1)
			return (1);
		free_msh_core_resources(msh_core);
		free_everything(msh_core);
		exit(msh_core->exit_status);
	}
	else
	{
		free_msh_core_resources(msh_core);
		free_everything(msh_core);
		exit (msh_core->exit_status);
	}
}
