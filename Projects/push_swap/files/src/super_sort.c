/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:50:46 by tsilva            #+#    #+#             */
/*   Updated: 2024/05/23 19:17:04 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	set_values(int stack_num, t_stack *stack_a, t_stack *stack_b);
static void	connect_nodes(int stack_num, long index, t_stack *stack_to, 
				t_stack *stack_from);
static void	set_node_price(t_stack *stack_a, t_stack *stack_b);

/*
Purpose: Main sorting algorithm for stacks larger than 3 elements
Arguments:
- t_stack **stack_a - main stack
- t_stack **stack_b - auxiliary stack
- int total_nodes - number of nodes to sort
Returns: void
*/
void    super_sort(t_stack **stack_a, t_stack **stack_b, int total_nodes)
{
    // Push first two nodes to stack B
    if (total_nodes-- > 3 && !is_sorted(*stack_a))
        pb(stack_b, stack_a);
    if (total_nodes-- > 3 && !is_sorted(*stack_a))
        pb(stack_b, stack_a);
        
    // Sort remaining nodes
    while (total_nodes-- > 3 && !is_sorted(*stack_a))
    {
        set_values(1, *stack_a, *stack_b);
        push_to_stack(stack_a, stack_b);
    }
    
    // Sort remaining three nodes
    rotate_swap(stack_a);
    
    // Push back nodes from stack B
    while (*stack_b)
    {
        set_values(2, *stack_a, *stack_b);
        move_to_top(stack_a, (*stack_b)->target, 1);
        pa(stack_a, stack_b);
    }
    
    // Final adjustments
    set_node_pos(*stack_a);
    small_first(stack_a);
}

/*
Purpose: Sets position and target values for nodes
Arguments:
- int stack_num - which stack is being processed
- t_stack *stack_a - main stack
- t_stack *stack_b - auxiliary stack
Returns: void
*/
static void    set_values(int stack_num, t_stack *stack_a, t_stack *stack_b)
{
    // Process stack A
    if (stack_num == 1)
    {
        set_node_pos(stack_a);
        set_node_pos(stack_b);
        connect_nodes(stack_num, LONG_MIN, stack_a, stack_b);
        set_node_price(stack_a, stack_b);
        set_cheap_node(stack_a);
    }
    // Process stack B
    else if (stack_num == 2)
    {
        set_node_pos(stack_a);
        set_node_pos(stack_b);
        connect_nodes(stack_num, LONG_MAX, stack_b, stack_a);
    }
}

/*
Purpose: Calculates cost of moving each node
Arguments:
- t_stack *stack_a - main stack
- t_stack *stack_b - auxiliary stack
Returns: void
*/
static void    set_node_price(t_stack *stack_a, t_stack *stack_b)
{
    // Variables for total nodes in each stack
    int total_nodes_a;
    int total_nodes_b;

    total_nodes_a = node_count(stack_a);
    total_nodes_b = node_count(stack_b);
    
    // Calculate price for each node
    while (stack_a)
    {
        stack_a->cheapest = false;
        stack_a->node_price = stack_a->pos;
        if (!(stack_a->before_middle))
            stack_a->node_price = total_nodes_a - (stack_a->pos);
        if (stack_a->target->before_middle)
            stack_a->node_price += stack_a->target->pos;
        else
            stack_a->node_price += total_nodes_b - (stack_a->target->pos);
        stack_a = stack_a->next;
    }
}

/*
Purpose: Determines target node based on index and stack number
Arguments:
- int num - stack number
- long index - current index value
- t_stack *stack - stack to search
- t_stack *node - current node
Returns: t_stack* - pointer to target node
*/
static t_stack    *set_target(int num, long index, t_stack *stack, t_stack *node)
{
    if ((num == 1 && index == LONG_MIN) || (num == 2 && index == LONG_MAX))
        return (get_node(stack, num == 2));
    else
        return (node);
}

/*
Purpose: Connects nodes between stacks for sorting
Arguments:
- int stack_num - which stack is being processed
- long index - current index value
- t_stack *stack_to - destination stack
- t_stack *stack_from - source stack
Returns: void
*/
static void    connect_nodes(int stack_num, long index, t_stack *stack_to, 
                            t_stack *stack_from)
{
    // Variables for node matching
    t_stack *tmp_node;
    t_stack *match_node;
    long    match_index;

    match_node = NULL;
    // Process each node in destination stack
    while (stack_to)
    {
        match_index = index;
        tmp_node = stack_from;
        // Find matching node in source stack
        while (tmp_node)
        {
            if ((stack_num == 1 && tmp_node->num < stack_to->num 
                    && tmp_node->num > match_index) || (stack_num == 2 
                    && tmp_node->num > stack_to->num 
                    && tmp_node->num < match_index))
            {
                match_index = tmp_node->num;
                match_node = tmp_node;
            }
            tmp_node = tmp_node->next;
        }
        stack_to->target = set_target(stack_num, match_index, stack_from, 
                match_node);
        stack_to = stack_to->next;
    }
}
