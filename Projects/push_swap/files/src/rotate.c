/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:45:47 by tsilva            #+#    #+#             */
/*   Updated: 2024/05/24 17:17:52 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
Purpose: Rotates stack nodes up or down
Arguments:
- t_stack **stack - stack to rotate
- bool reverse - true for reverse rotation (bottom to top)
Returns: void
*/
void    rotate(t_stack **stack, bool reverse)
{
    // Node to track last position
    t_stack *top_node;

    // Return if stack is empty or has only one node
    if (!stack || !(*stack)->next)
        return ;
        
    // Get last node
    top_node = get_last_node(*stack);
    
    // Regular rotation (top to bottom)
    if (!reverse)
    {
        top_node->next = *stack;
        *stack = (*stack)->next;
        (*stack)->prev = NULL;
        top_node->next->prev = top_node;
        top_node->next->next = NULL;
    }
    // Reverse rotation (bottom to top)
    else
    {
        top_node->prev->next = NULL;
        top_node->next = *stack;
        top_node->prev = NULL;
        *stack = top_node;
        top_node->next->prev = top_node;
    }
}

/*
Purpose: Rotates stack A up (top to bottom)
Arguments: t_stack **stack_a - stack to rotate
Returns: void
*/
void    ra(t_stack **stack_a)
{
    rotate(stack_a, false);
    write(1, "ra\n", 3);
}

/*
Purpose: Rotates stack B up (top to bottom)
Arguments: t_stack **stack_b - stack to rotate
Returns: void
*/
void    rb(t_stack **stack_b)
{
    rotate(stack_b, false);
    write(1, "rb\n", 3);
}

/*
Purpose: Rotates both stacks up simultaneously
Arguments:
- t_stack **stack_a - first stack to rotate
- t_stack **stack_b - second stack to rotate
Returns: void
*/
void    rr(t_stack **stack_a, t_stack **stack_b)
{
    rotate(stack_a, false);
    rotate(stack_b, false);
    write(1, "rr\n", 3);
}

/*
Purpose: Rotates and swaps nodes to optimize position
Arguments: t_stack **stack - stack to rotate and swap
Returns: void
*/
void    rotate_swap(t_stack **stack)
{
    // Node to track highest value
    t_stack *higher_node;

    // Find highest value node
    higher_node = get_node(*stack, false);
    
    // Rotate based on highest node position
    if (*stack == higher_node)
        ra(stack);
    else if ((*stack)->next == higher_node)
        rra(stack);
        
    // Swap if needed
    if ((*stack)->num > (*stack)->next->num)
        sa(stack);
}
