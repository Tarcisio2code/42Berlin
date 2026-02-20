/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 08:50:28 by tsilva            #+#    #+#             */
/*   Updated: 2024/11/07 13:31:01 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/commands.h"

int	cmd_pwd(t_list *env_list)
{
	char	curr_work_dir[PATH_MAX];
	char	*last_pwd;

	last_pwd = get_env_var(env_list, "PWD");
	if (!last_pwd && !getcwd(curr_work_dir, sizeof(curr_work_dir)))
	{
		if (last_pwd)
			free(last_pwd);
		print_shell_error(strerror(errno), "pwd");
		return (EXIT_FAILURE);
	}
	if (last_pwd)
	{
		printf("%s\n", last_pwd);
		free(last_pwd);
	}
	else
		printf("%s\n", curr_work_dir);
	return (EXIT_SUCCESS);
}
