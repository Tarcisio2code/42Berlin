/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:03:31 by tsilva            #+#    #+#             */
/*   Updated: 2023/11/30 18:01:36 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * @lst: The node to be deleted.
 * @del: A function pointer to delete the content of the node.
 *
 * This function deletes the node `lst` using the function `del` to free its content, and then frees the node itself.
*/
void ft_lstdelone(t_list *lst, void (*del)(void*))
{
    // Check if the node to be deleted and the delete function are not NULL.
    if (lst && del)
    {
        // Call the delete function to free the content of the node.
        (del)(lst->content);

        // Free the memory allocated for the node itself.
        free(lst);
    }
}
