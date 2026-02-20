/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdunkel <fdunkel@student.42.fr>                +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:00:00 by fdunkel           #+#    #+#             */
/*   Updated: 2024/11/10 14:37:38 by fdunkel            ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cleaner.h"

void	free_two_dim_array(char **path_wslash)
{
	int	i;

	if (!path_wslash)
		return ;
	i = 0;
	while (path_wslash[i])
	{
		free(path_wslash[i]);
		path_wslash[i] = NULL;
		i++;
	}
	free(path_wslash);
	path_wslash = NULL;
}
