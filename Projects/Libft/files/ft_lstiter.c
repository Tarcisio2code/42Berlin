/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:31:24 by tsilva            #+#    #+#             */
/*   Updated: 2023/12/01 13:40:36 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * @lst: The pointer to the first node of the list.
 * @f: A function pointer to apply to the content of each node.
 *
 * This function iterates through the list and applies the function `f` to the content of each node.
*/
void ft_lstiter(t_list *lst, void (*f)(void *))
{
    // Check if the list pointer or the function pointer is NULL.
    if (!lst || !f)
        return;

    // Iterate through the list until the end is reached.
    while (lst)
    {
        // Apply the function `f` to the content of the current node.
        (*f)(lst->content);

        // Move to the next node in the list.
        lst = lst->next;
    }
}
