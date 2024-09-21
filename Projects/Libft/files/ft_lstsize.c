/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:57:06 by tsilva            #+#    #+#             */
/*   Updated: 2023/11/29 16:15:08 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * lst: The pointer to the first node of the list.
 *
 * This function traverses the list and counts the number of nodes present.
 *
 * Return: The number of nodes in the list.
*/
int ft_lstsize(t_list *lst)
{
    // Declare a counter to keep track of the number of nodes.
    int counter;

    // Initialize the counter to 0.
    counter = 0;

    // Traverse the list until the end is reached.
    while (lst)
    {
        // Increment the counter for each node encountered.
        counter++;

        // Move to the next node in the list.
        lst = lst->next;
    }

    // Return the total number of nodes in the list.
    return (counter);
}
