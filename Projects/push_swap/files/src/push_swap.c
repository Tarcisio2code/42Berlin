/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:26:07 by tsilva            #+#    #+#             */
/*   Updated: 2024/05/14 10:50:13 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
Purpose: Main program entry point
Arguments:
- int argc - argument count
- char **argv - argument array
Returns: int - program exit status
*/
int main(int argc, char **argv)
{
    // Initialize variables
    int     total_nodes;
    t_stack *stack_a;
    t_stack *stack_b;

    // Initialize stacks to NULL
    stack_a = NULL;
    stack_b = NULL;
    
    // Validate input and fill stack A
    check_input(argc, &argv);
    fill_stack_a(&stack_a, argv, argc);
    
    // Count total nodes
    total_nodes = node_count(stack_a);
    
    // Check if already sorted
    if (is_sorted(stack_a))
    {
        free_stack(&stack_a);
        return (0);
    }
    
    // Choose sorting algorithm based on size
    if (total_nodes == 2)
        sa(&stack_a);
    else if (total_nodes == 3)
        rotate_swap(&stack_a);
    else
        super_sort(&stack_a, &stack_b, total_nodes);
        
    // Free memory and exit
    free_stack(&stack_a);
    return (0);
}
