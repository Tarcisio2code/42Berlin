/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_del_first.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:08:16 by fdunkel           #+#    #+#             */
/*   Updated: 2024/10/04 14:06:59 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_del_first(t_list **list)
{
	t_list	*tmp;

	if (list == NULL || *list == NULL)
		return ;
	tmp = *list;
	tmp = tmp->next;
	free(*list);
	*list = tmp;
}
