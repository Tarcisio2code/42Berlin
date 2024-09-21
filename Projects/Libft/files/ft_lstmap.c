/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:50:32 by tsilva            #+#    #+#             */
/*   Updated: 2023/12/14 16:55:10 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * lst: The pointer to the first node of the original list.
 * f: A function pointer to apply to the content of each node.
 * del: A function pointer to delete the content of a node if needed.
 *
 * This function iterates through the original list, applies the function `f` to the content of each node,
 * and creates a new list with the results. If memory allocation fails, it clears the new list and returns NULL.
 *
 * Return: A pointer to the first node of the new list, or NULL if memory allocation fails.
*/
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    // Declare pointers for the new list and new nodes.
    t_list *new_list;
    t_list *new_node;
    void *content;

    // Initialize the new list to NULL.
    new_list = NULL;

    // Check if the original list is NULL.
    if (!lst)
        return (NULL);

    // Iterate through the original list.
    while (lst)
    {
        // Apply the function `f` to the content of the current node.
        content = f(lst->content);

        // Create a new node with the transformed content.
        new_node = ft_lstnew(content);

        // If memory allocation fails for the new node:
        if (!new_node)
        {
            // Delete the transformed content using the `del` function.
            del(content);

            // Clear the new list to free allocated memory.
            ft_lstclear(&new_list, (*del));

            // Return NULL to indicate failure.
            return (NULL);
        }

        // Add the new node to the end of the new list.
        ft_lstadd_back(&new_list, new_node);

        // Move to the next node in the original list.
        lst = lst->next;
    }

    // Return the pointer to the first node of the new list.
    return (new_list);
}
