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
/*
 * lst: A pointer to the pointer of the first node of the list.
 * new: A pointer to the new node to be added.
 *
 * This function inserts the new node at the end of the list.
*/
void ft_lstadd_back(t_list **lst, t_list *new)
{
    // Declare a pointer to hold the last node of the list.
    t_list *end_list;

    // If the list pointer is NULL, return immediately.
    if (!lst)
        return;

    // If the list is empty, set the new node as the first node.
    if (!*lst)
    {
        *lst = new;
        return;
    }

    // Find the last node of the list.
    end_list = ft_lstlast(*lst);

    // Set the next pointer of the last node to the new node.
    end_list->next = new;
}
