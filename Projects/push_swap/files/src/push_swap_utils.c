/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:23:14 by tsilva            #+#    #+#             */
/*   Updated: 2024/05/14 10:50:07 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
Purpose: Displays error message and exits program
Arguments: none
Returns: int - never returns, exits program
*/
int    error_msg(void)
{
    // Write error message and exit
    write(1, "Error\n", 6);
    exit(EXIT_FAILURE);
}

/*
Purpose: Validates input arguments format
Arguments:
- char **argv - argument array
- int argc - argument count
Returns: int - 1 if valid, 0 if invalid
*/
int    valid_input(char **argv, int argc)
{
    // Variables to track position in arguments
    int pos;
    int i;

    // Set starting position based on argument count
    if (argc == 2)
        pos = 0;
    else
        pos = 1;
        
    // Check each argument
    while (argv[pos])
    {
        i = 0;
        while (argv[pos][i])
        {
            // Check for valid sign placement
            if ((argv[pos][i] == '-' || argv[pos][i] == '+')
                && (!(ft_isdigit(argv[pos][i + 1])) || i > 0))
                return (0);
            // Check for valid characters
            else if (!(argv[pos][i] == '-') && !(argv[pos][i] == '+')
                && !(ft_isdigit(argv[pos][i])))
                return (0);
            i++;
        }
        pos++;
    }
    return (1);
}

/*
Purpose: Validates and processes input arguments
Arguments:
- int argc - argument count
- char ***argv - pointer to argument array
Returns: void
*/
void    check_input(int argc, char ***argv)
{
    // Check minimum arguments
    if (argc < 2)
        exit(EXIT_FAILURE);
    // Split single argument if needed
    else if (argc == 2)
        *argv = ft_split((*argv)[1], ' ');
    // Validate input format
    if (!*argv || !**argv || !(valid_input(*argv, argc)))
    {
        if (*argv && argc == 2)
            free_argv(*argv);
        error_msg();
    }
}
