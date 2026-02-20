/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdunkel <fdunkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:24:01 by fdunkel           #+#    #+#             */
/*   Updated: 2024/11/15 16:32:57 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

volatile sig_atomic_t	g_signal_value = 0;

void	init_minishell(t_msh *msh_core, char **envp, t_list **env_list)
{
	*env_list = NULL;
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
	copy_envp(env_list, envp);
	init_msh(msh_core);
	msh_core->envp = *env_list;
	msh_core->first_home_path = get_env_var(*env_list, "HOME");
	malloc_error_check(msh_core->first_home_path);
}

int	handle_input(char *input, t_msh *msh_core)
{
	if (validate_user_input(input))
	{
		msh_core->exit_status = 2;
		free(input);
		input = NULL;
		return (1);
	}
	return (0);
}

int	prepare_execution(t_msh *msh_core, char *input)
{
	char	**env_array;

	if (lexer_main(input, msh_core) == 1)
	{
		free_lexer(msh_core);
		free(input);
		return (1);
	}
	if (g_signal_value != 0)
	{
		msh_core->exit_status = g_signal_value + 128;
		g_signal_value = 0;
	}
	env_array = convert_env_to_arr(msh_core->envp);
	if (!msh_core->lexer || !env_array)
	{
		free(input);
		free_two_dim_array(env_array);
		return (1);
	}
	replace_env_vars(msh_core, env_array, msh_core->exit_status);
	free_two_dim_array(env_array);
	return (0);
}

int	run_minishell(t_msh *msh_core)
{
	char	*input;

	input = NULL;
	while (1)
	{
		input = get_user_input();
		if (handle_ctrl_d(input, msh_core))
			break ;
		else if (handle_input(input, msh_core))
			continue ;
		if (prepare_execution(msh_core, input))
			continue ;
		parser_main(msh_core);
		if (!msh_core->cmd_table || !msh_core->cmd_table->entry)
		{
			free(input);
			free_everything(msh_core);
			continue ;
		}
		execute_main(msh_core);
		free(input);
		input = NULL;
		free_everything(msh_core);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_msh	msh_core;
	t_list	*env_list;

	(void)argc;
	(void)argv;
	init_minishell(&msh_core, envp, &env_list);
	run_minishell(&msh_core);
	if (msh_core.envp)
	{
		free_env_list(msh_core.envp);
		msh_core.envp = NULL;
		env_list = NULL;
	}
	if (msh_core.first_home_path)
	{
		free(msh_core.first_home_path);
		msh_core.first_home_path = NULL;
	}
	return (0);
}
