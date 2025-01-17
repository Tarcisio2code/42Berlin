/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:38:35 by tsilva            #+#    #+#             */
/*   Updated: 2024/04/25 17:27:08 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
Purpose: Rotates stack A down (bottom to top)
Arguments: t_stack **stack_a - stack to rotate
Returns: void
*/
void    rra(t_stack **stack_a)
{
    rotate(stack_a, true);
    write(1, "rra\n", 4);
}

/*
Purpose: Rotates stack B down (bottom to top)
Arguments: t_stack **stack_b - stack to rotate
Returns: void
*/
void    rrb(t_stack **stack_b)
{
    rotate(stack_b, true);
    write(1, "rrb\n", 4);
}

/*
Purpose: Rotates both stacks down simultaneously
Arguments:
- t_stack **stack_a - first stack to rotate
- t_stack **stack_b - second stack to rotate
Returns: void
*/
void    rrr(t_stack **stack_a, t_stack **stack_b)
{
    rotate(stack_a, true);
    rotate(stack_b, true);
    write(1, "rrr\n", 4);
}

