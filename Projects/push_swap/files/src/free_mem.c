/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:51:33 by tsilva            #+#    #+#             */
/*   Updated: 2024/04/19 09:59:26 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
Purpose: Frees memory allocated for command line arguments
Arguments: char **argv - array of strings to free
Returns: void
*/
void    free_argv(char **argv)
{
    // Variable to track position in array
    int pos;

    // Return if argv is NULL
    if (!argv)
        return ;
    // Free each string in array
    pos = 0;
    while (argv[pos])
        free(argv[pos++]);
    // Free the array itself
    free(argv);
}

/*
Purpose: Frees memory allocated for stack nodes
Arguments: t_stack **stack - pointer to stack to free
Returns: void
*/
void    free_stack(t_stack **stack)
{
    // Temporary pointers for traversing stack
    t_stack *temp;
    t_stack *node;

    // Return if stack pointer is NULL
    if (!stack)
        return ;
    // Traverse stack freeing each node
    node = *stack;
    while (node)
    {
        temp = node->next;
        free(node);
        node = temp;
    }
    // Set stack pointer to NULL
    *stack = NULL;
}

/*
Purpose: Frees all allocated memory and exits program
Arguments: 
- t_stack **stack - stack to free
- int argc - argument count
- char **argv - arguments to free
- bool is_error - whether to display error message
Returns: void
*/
void    free_all(t_stack **stack, int argc, char **argv, bool is_error)
{
    // Free argv if single argument was split
    if (argc == 2)
        free_argv(argv);
    // Free the stack
    free_stack(stack);
    // Display error if needed and exit
    if (is_error)
        error_msg();
    exit(EXIT_FAILURE);
}