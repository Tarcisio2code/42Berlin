/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:16:56 by tsilva            #+#    #+#             */
/*   Updated: 2023/12/04 16:09:03 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * lst: The pointer to the first node of the list.
 *
 * This function traverses the list to find the last node.
 *
 * Return: The last node of the list, or NULL if the list is empty.
*/
t_list *ft_lstlast(t_list *lst)
{
    // Traverse the list until the end is reached.
    while (lst && lst->next)
        lst = lst->next;

    // Return the last node (or NULL if the list was empty).
    return (lst);
}
