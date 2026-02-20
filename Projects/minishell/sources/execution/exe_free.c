/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:59:17 by fdunkel           #+#    #+#             */
/*   Updated: 2024/11/15 16:01:17 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libraries.h"
#include "../../include/execution.h"
#include "../../include/environment.h"

void	free_paths(char **path)
{
	int	i;

	if (path == NULL) 
	{
		printf("Path is NULL. Nothing to free.\n");
		return ;
	}
	i = 0;
	while (path[i] != NULL) 
	{
		printf("Freeing path[%d]: %s\n", i, path[i]);
		free(path[i]);
		i++;
	}
	printf("Freeing path array.\n");
	free(path);
}
