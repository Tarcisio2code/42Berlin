/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:09:14 by tsilva            #+#    #+#             */
/*   Updated: 2023/11/29 14:57:24 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * lst: A pointer to the pointer of the first node of the list.
 * new: A pointer to the new node to be added.
 *
 * This function inserts the new node at the start of the list, updating the head pointer to point to the new node.
*/
void ft_lstadd_front(t_list **lst, t_list *new)
{
    // Check if both `lst` and `new` are not NULL.
    if (lst && new)
    {
        // Set the `next` pointer of the new node to the current head of the list.
        new->next = *lst;

        // Update the head of the list to point to the new node.
        *lst = new;
    }
}
