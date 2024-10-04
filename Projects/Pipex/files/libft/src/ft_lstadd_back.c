/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:03:53 by tsilva            #+#    #+#             */
/*   Updated: 2023/11/30 17:03:53 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*end_list;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	end_list = ft_lstlast(*lst);
	end_list->next = new;
}
