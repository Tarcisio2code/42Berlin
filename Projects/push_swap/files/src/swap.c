/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:46:44 by tsilva            #+#    #+#             */
/*   Updated: 2024/05/24 17:18:26 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
Purpose: Swaps top two nodes of a stack
Arguments: t_stack **stack - stack to perform swap on
Returns: void
*/
static void    swap(t_stack **stack)
{
    // Variable to track stack size
    int total_nodes;

    // Get total number of nodes
    total_nodes = node_count(*stack);
    
    // Return if stack has less than 2 nodes or is invalid
    if (total_nodes == 1 || !stack || !*stack)
        return ;
        
    // Perform swap operation
    *stack = (*stack)->next;
    (*stack)->prev->prev = *stack;
    (*stack)->prev->next = (*stack)->next;
    if ((*stack)->next)
        (*stack)->next->prev = (*stack)->prev;
    (*stack)->next = (*stack)->prev;
    (*stack)->prev = NULL;
}

/*
Purpose: Swaps top two nodes of stack A
Arguments: t_stack **stack_a - stack to swap
Returns: void
*/
void    sa(t_stack **stack_a)
{
    swap(stack_a);
    write(1, "sa\n", 3);
}

/*
Purpose: Swaps top two nodes of stack B
Arguments: t_stack **stack_b - stack to swap
Returns: void
*/
void    sb(t_stack **stack_b)
{
    swap(stack_b);
    write(1, "sb\n", 3);
}

/*
Purpose: Swaps top two nodes of both stacks
Arguments:
- t_stack **stack_a - first stack to swap
- t_stack **stack_b - second stack to swap
Returns: void
*/
void    ss(t_stack **stack_a, t_stack **stack_b)
{
    swap(stack_a);
    swap(stack_b);
    write(1, "ss\n", 3);
}
