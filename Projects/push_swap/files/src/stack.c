/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:35:11 by tsilva            #+#    #+#             */
/*   Updated: 2024/05/23 19:59:25 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

#include "stdlib.h"

/*
Purpose: Adds new node to end of stack
Arguments:
- t_stack **stack - stack to add to
- int number - value for new node
Returns: void
*/
void    insert_node(t_stack **stack, int number)
{
    // Nodes for creating and linking
    t_stack *new_node;
    t_stack *last_node;

    // Return if stack pointer is NULL
    if (!stack)
        return ;
        
    // Create new node
    new_node = malloc(sizeof(t_stack));
    if (!new_node)
        return ;
        
    // Initialize new node
    new_node->next = NULL;
    new_node->num = number;
    
    // If stack is empty
    if (!(*stack))
    {
        *stack = new_node;
        new_node->prev = NULL;
    }
    // Add to end of stack
    else
    {
        last_node = get_last_node(*stack);
        last_node->next = new_node;
        new_node->prev = last_node;
    }
}

/*
Purpose: Fills stack A with validated input numbers
Arguments:
- t_stack **stack - stack to fill
- char **argv - input arguments
- int argc - argument count
Returns: void
*/
void    fill_stack_a(t_stack **stack, char **argv, int argc)
{
    // Variables for position tracking and number conversion
    int     pos;
    long    num;

    // Set starting position based on argument count
    if (argc == 2)
        pos = 0;
    else
        pos = 1;
        
    // Process each argument
    while (argv[pos])
    {
        // Convert string to number
        num = ft_atoi_long(argv[pos]);
        
        // Validate number and check for duplicates
        if (num > INT_MAX || num < INT_MIN || number_exists(*stack, num))
            free_all(stack, argc, argv, true);
            
        // Add number to stack
        insert_node(stack, num);
        if (!*stack)
            free_all(stack, argc, argv, true);
            
        pos++;
    }
    
    // Free split arguments if needed
    if (argc == 2)
        free_argv(argv);
}
