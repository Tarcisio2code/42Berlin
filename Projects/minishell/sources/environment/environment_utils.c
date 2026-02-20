/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdunkel <fdunkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:08:46 by fdunkel           #+#    #+#             */
/*   Updated: 2024/11/14 17:18:47 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/environment.h"

int	ft_envsize(t_list *env)
{
	int	count;

	count = 0;
	while (env)
	{
		count++;
		env = env->next;
	}
	return (count);
}

char	**convert_env_to_arr(t_list *env)
{
	char	**string_array;
	int		i;
	int		len;

	i = 0;
	len = ft_envsize(env);
	string_array = malloc(sizeof(char *) * (len + 1));
	malloc_error_check(string_array);
	while (i < len)
	{
		string_array[i] = ft_strdup((char *)env->content);
		malloc_error_check(string_array[i]);
		env = env->next;
		i++;
	}
	string_array[i] = NULL;
	return (string_array);
}
