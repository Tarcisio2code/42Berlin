/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:34:13 by tsilva            #+#    #+#             */
/*   Updated: 2024/05/02 19:58:14 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
Purpose: Checks if a number already exists in the stack
Arguments:
- t_stack *stack - stack to search
- int number - number to look for
Returns: int - 1 if number exists, 0 if not
*/
int    number_exists(t_stack *stack, int number)
{
    // Return 0 if stack is empty
    if (!stack)
        return (0);
        
    // Check each node for the number
    while (stack)
    {
        if (stack->num == number)
            return (1);
        stack = stack->next;
    }
    return (0);
}

/*
Purpose: Returns pointer to last node in stack
Arguments: t_stack *stack - stack to search
Returns: t_stack* - pointer to last node, NULL if stack empty
*/
t_stack    *get_last_node(t_stack *stack)
{
    // Return NULL if stack is empty
    if (!stack)
        return (NULL);
        
    // Traverse to last node
    while (stack->next)
        stack = stack->next;
    return (stack);
}

/*
Purpose: Checks if stack is sorted in ascending order
Arguments: t_stack *stack - stack to check
Returns: int - 1 if sorted, 0 if not sorted
*/
int    is_sorted(t_stack *stack)
{
    // Compare each node with next node
    while (stack->next)
    {
        if (stack->num > stack->next->num)
            return (0);
        stack = stack->next;
    }
    return (1);
}

/*
Purpose: Counts total nodes in stack
Arguments: t_stack *stack - stack to count
Returns: int - number of nodes
*/
int    node_count(t_stack *stack)
{
    // Variable to track count
    int count;

    // Count nodes while traversing stack
    count = 0;
    while (stack)
    {
        count++;
        stack = stack->next;
    }
    return (count);
}
