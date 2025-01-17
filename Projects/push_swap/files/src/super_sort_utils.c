/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:47:28 by tsilva            #+#    #+#             */
/*   Updated: 2024/05/23 19:38:32 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
Purpose: Moves specified node to top of stack
Arguments:
- t_stack **stack - stack to modify
- t_stack *top_node - node to move to top
- int stack_num - identifies which stack (1 for A, 2 for B)
Returns: void
*/
void    move_to_top(t_stack **stack, t_stack *top_node, int stack_num)
{
    // Rotate until desired node is at top
    while (*stack != top_node)
    {
        // For stack A
        if (stack_num == 1)
        {
            if (top_node->before_middle)
                ra(stack);
            else
                rra(stack);
        }
        // For stack B
        else if (stack_num == 2)
        {
            if (top_node->before_middle)
                rb(stack);
            else
                rrb(stack);
        }
    }
}

/*
Purpose: Sets position and middle flags for each node in stack
Arguments: t_stack *stack - stack to process
Returns: void
*/
void    set_node_pos(t_stack *stack)
{
    // Variables for tracking position
    int pos;
    int stack_middle;

    if (!stack)
        return ;
        
    pos = 0;
    stack_middle = node_count(stack) / 2;
    
    // Set position and middle flag for each node
    while (stack)
    {
        stack->pos = pos;
        if (pos <= stack_middle)
            stack->before_middle = true;
        else
            stack->before_middle = false;
        stack = stack->next;
        pos++;
    }
}

/*
Purpose: Finds smallest or largest node in stack
Arguments:
- t_stack *stack - stack to search
- bool smallest - true to find smallest, false for largest
Returns: t_stack* - pointer to found node
*/
t_stack    *get_node(t_stack *stack, bool smallest)
{
    // Variables for tracking extreme values
    long    node_num;
    t_stack *new_node;

    if (!stack)
        return (NULL);
        
    // Initialize comparison value
    if (smallest)
        node_num = LONG_MAX;
    else
        node_num = LONG_MIN;
        
    // Find extreme value node
    while (stack)
    {
        if ((smallest && stack->num < node_num)
            || (!smallest && stack->num > node_num))
        {
            node_num = stack->num;
            new_node = stack;
        }
        stack = stack->next;
    }
    return (new_node);
}

/*
Purpose: Moves smallest number to top of stack A
Arguments: t_stack **stack_a - stack to modify
Returns: void
*/
void    small_first(t_stack **stack_a)
{
    // Node to track smallest value
    t_stack *tmp_node;

    if (!stack_a)
        return ;
        
    // Find and move smallest node to top
    tmp_node = get_node(*stack_a, true);
    while ((*stack_a)->num != tmp_node->num)
    {
        if (tmp_node->before_middle)
            ra(stack_a);
        else
            rra(stack_a);
        tmp_node = get_node(*stack_a, true);
    }
}

/*
Purpose: Marks node with lowest move cost as cheapest
Arguments: t_stack *stack - stack to process
Returns: void
*/
void    set_cheap_node(t_stack *stack)
{
    // Variables for tracking cheapest node
    long    cheap_num;
    t_stack *cheap_node;

    if (!stack)
        return ;
        
    cheap_num = LONG_MAX;
    
    // Find node with lowest cost
    while (stack)
    {
        if (stack->node_price < cheap_num)
        {
            cheap_num = stack->node_price;
            cheap_node = stack;
        }
        stack = stack->next;
    }
    // Mark found node as cheapest
    cheap_node->cheapest = true;
}

