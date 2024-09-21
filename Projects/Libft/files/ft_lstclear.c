/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:03:38 by tsilva            #+#    #+#             */
/*   Updated: 2023/12/14 16:02:54 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * lst: A pointer to the pointer of the first node of the list.
 * del: A function pointer to delete the content of each node.
 *
 * This function iterates through the list, deletes each node using `ft_lstdelone`, and sets the list pointer to NULL.
*/
void ft_lstclear(t_list **lst, void (*del)(void*))
{
    // Declare a temporary pointer to hold the current node.
    t_list *temp;

    // Check if the list pointer, the first node, and the delete function are not NULL.
    if (lst && *lst && del)
    {
        // Iterate through the list until the end is reached.
        while (*lst)
        {
            // Store the current node in the temporary pointer.
            temp = *lst;

            // Move the list pointer to the next node.
            *lst = (*lst)->next;

            // Delete the current node using `ft_lstdelone`.
            ft_lstdelone(temp, del);
        }

        // Set the list pointer to NULL to indicate the list is empty.
        *lst = NULL;
    }
}
