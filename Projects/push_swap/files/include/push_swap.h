/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:10:20 by tsilva            #+#    #+#             */
/*   Updated: 2024/05/23 19:48:09 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Purpose: Header file for push_swap project
Contains structure definitions and function prototypes
*/

// Header guard to prevent multiple inclusions
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Required header files
# include <stdbool.h>    // For boolean type
# include <limits.h>      // For INT_MAX and INT_MIN
# include "../libft/src/libft.h"  // Custom library functions

// Structure for doubly linked list nodes
typedef struct s_stack
{
    long            num;            // Number stored in node
    long            pos;           // Position in stack
    long            node_price;    // Cost to move this node
    bool            before_middle; // True if node is in first half of stack
    bool            cheapest;      // True if this is cheapest node to move
    struct s_stack  *target;      // Target node in other stack
    struct s_stack  *next;        // Pointer to next node
    struct s_stack  *prev;        // Pointer to previous node
}   t_stack;

// Memory management functions
void        free_argv(char **argv);           // Frees split argument array
void        free_stack(t_stack **stack);      // Frees all nodes in stack
void        free_all(t_stack **stack, int argc, char **argv, bool is_error);  // Frees all allocated memory

// Stack utility functions
long        ft_atoi_long(const char *str);    // Converts string to long int
int         number_exists(t_stack *stack, int number);  // Checks for duplicate numbers
t_stack     *get_last_node(t_stack *stack);   // Returns pointer to last node
int         is_sorted(t_stack *stack);        // Checks if stack is sorted
int         node_count(t_stack *stack);       // Counts nodes in stack
void        insert_node(t_stack **stack, int number);  // Adds new node to stack
void        fill_stack_a(t_stack **stack, char **argv, int argc);  // Fills stack A with input

// Input validation functions
int         error_msg(void);                  // Displays error message
int         valid_input(char **argv, int argc);  // Validates input format
void        check_input(int argc, char ***argv); // Processes and validates input

// Stack operations - Swap
void        sa(t_stack **stack);              // Swaps top two elements of stack A
void        sb(t_stack **stack_b);            // Swaps top two elements of stack B
void        ss(t_stack **stack_a, t_stack **stack_b);  // Swaps top two elements of both stacks

// Stack operations - Push
void        pa(t_stack **stack_a, t_stack **stack_b);  // Pushes top element from B to A
void        pb(t_stack **stack_b, t_stack **stack_a);  // Pushes top element from A to B

// Stack operations - Rotate
void        rotate(t_stack **stack, bool reverse);  // Rotates stack up or down
void        rotate_swap(t_stack **stack);     // Rotates and swaps as needed
void        ra(t_stack **stack);              // Rotates stack A up
void        rb(t_stack **stack_b);            // Rotates stack B up
void        rr(t_stack **stack_a, t_stack **stack_b);  // Rotates both stacks up
void        rra(t_stack **stack);             // Rotates stack A down
void        rrb(t_stack **stack_b);           // Rotates stack B down
void        rrr(t_stack **stack_a, t_stack **stack_b);  // Rotates both stacks down

// Sorting algorithms
void        super_sort(t_stack **stack_a, t_stack **stack_b, int stack_a_nodes);  // Main sorting algorithm
void        push_to_stack(t_stack **stack_a, t_stack **stack_b);  // Pushes nodes between stacks
void        move_to_top(t_stack **stack, t_stack *top_node, int stack_num);  // Moves node to top
t_stack     *get_node(t_stack *stack, bool smallest);  // Finds smallest/largest node
void        set_node_pos(t_stack *stack);     // Sets position for each node
void        small_first(t_stack **stack_a);   // Moves smallest number to top
void        set_cheap_node(t_stack *stack);   // Marks cheapest node to move

#endif