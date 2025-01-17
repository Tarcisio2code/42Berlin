/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:38:03 by tsilva            #+#    #+#             */
/*   Updated: 2024/05/14 10:09:16 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
Purpose: Moves top node from one stack to another
Arguments: 
- t_stack **to_stack - destination stack
- t_stack **from_stack - source stack
Returns: void
*/
static void    push(t_stack **to_stack, t_stack **from_stack)
{
    // Node to be moved between stacks
    t_stack *tmp_node;

    if (!*from_stack)
        return ;
    tmp_node = *from_stack;
    *from_stack = (*from_stack)->next; 
    if (*from_stack)
        (*from_stack)->prev = NULL;
    tmp_node->prev = NULL;
    if (!(*to_stack))
    {
        *to_stack = tmp_node;
        tmp_node->next = NULL;
    }
    else
    {
        tmp_node->next = *to_stack;
        tmp_node->next->prev = tmp_node; 
        *to_stack = tmp_node;
    }
}

/*
Purpose: Pushes top node from stack B to stack A
Arguments:
- t_stack **stack_a - destination stack
- t_stack **stack_b - source stack
Returns: void
*/
void    pa(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_a, stack_b);
    write(1, "pa\n", 3);
}

/*
Purpose: Pushes top node from stack A to stack B
Arguments:
- t_stack **stack_b - destination stack
- t_stack **stack_a - source stack
Returns: void
*/
void    pb(t_stack **stack_b, t_stack **stack_a)
{
    push(stack_b, stack_a);
    write(1, "pb\n", 3);
}

/*
Purpose: Rotates both stacks simultaneously until target nodes are at top
Arguments:
- t_stack **stack_a - first stack
- t_stack **stack_b - second stack
- t_stack *cheap_node - node to be moved
- bool reverse - direction of rotation
Returns: void
*/
static void    rotate_top(t_stack **stack_a, t_stack **stack_b, 
                        t_stack *cheap_node, bool reverse)
{
    // Rotate both stacks until target nodes are at top
    while (*stack_b != cheap_node->target && *stack_a != cheap_node)
    {
        if (reverse)
            rrr(stack_a, stack_b);
        else
            rr(stack_a, stack_b);
    }
    // Update positions after rotation
    set_node_pos(*stack_a);
    set_node_pos(*stack_b);
}

/*
Purpose: Pushes cheapest node from stack A to stack B
Arguments:
- t_stack **stack_a - source stack
- t_stack **stack_b - destination stack
Returns: void
*/
void    push_to_stack(t_stack **stack_a, t_stack **stack_b)
{
    // Variables to track nodes
    t_stack *cheap_node;
    t_stack *tmp_stack;

    cheap_node = NULL;
    tmp_stack = *stack_a;
    
    // Find cheapest node
    while (tmp_stack)
    {
        if (tmp_stack->cheapest)
        {
            cheap_node = tmp_stack;
            break ;
        }
        tmp_stack = tmp_stack->next;
    }
    
    // Rotate both stacks based on node positions
    if (cheap_node->before_middle && cheap_node->target->before_middle)
        rotate_top(stack_a, stack_b, cheap_node, false);
    else if (!(cheap_node->before_middle) 
        && !(cheap_node->target->before_middle))
        rotate_top(stack_a, stack_b, cheap_node, true); 
        
    // Move nodes to top and push
    move_to_top(stack_a, cheap_node, 1);
    move_to_top(stack_b, cheap_node->target, 2);
    pb(stack_b, stack_a);
}

