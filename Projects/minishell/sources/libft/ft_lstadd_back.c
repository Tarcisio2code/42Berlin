/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:03:53 by tsilva            #+#    #+#             */
/*   Updated: 2024/11/15 16:17:31 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
	{
		return (NULL);
	}
	while (lst && lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	print_list(t_list *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		lst = lst->next;
	}
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*end_list;

	if (!lst)
	{
		return ;
	}
	if (!*lst)
	{
		*lst = new;
	}
	else
	{
		end_list = ft_lstlast(*lst);
		end_list->next = new;
	}
}
