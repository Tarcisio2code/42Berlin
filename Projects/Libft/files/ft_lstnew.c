/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:32:27 by tsilva            #+#    #+#             */
/*   Updated: 2023/11/29 13:35:34 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * content: The content to store in the new node.
 *
 * This function allocates memory for a new node, initializes its content and next pointer,
 * and returns a pointer to the new node. If memory allocation fails, it returns NULL.
*/
t_list *ft_lstnew(void *content)
{
    // Declare a pointer to hold the new node.
    t_list *root;

    // Allocate memory for the new node.
    root = (t_list *)malloc(sizeof(t_list));

    // Check if malloc failed to allocate memory.
    if (!root)
        // Return NULL if memory allocation failed.
        return (NULL);

    // Set the content of the new node to the provided content.
    root->content = content;

    // Set the next pointer of the new node to NULL (it is the only node in the list so far).
    root->next = NULL;

    // Return the pointer to the newly created node.
    return (root);
}
