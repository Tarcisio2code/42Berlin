/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:34:23 by tsilva            #+#    #+#             */
/*   Updated: 2024/05/01 23:02:07 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
Purpose: Skips whitespace characters in a string
Arguments: char *str - string to process
Returns: char* - pointer to first non-whitespace character
*/
static char    *ft_trimspaces(char *str)
{
    // Skip whitespace characters (tabs, newlines, spaces)
    while ((*str >= 9 && *str <= 13) || *str == 32)
        str++;
    return (str);
}

/*
Purpose: Converts string of digits to long integer
Arguments:
- char *src - string containing digits
- bool is_negative - flag for negative numbers
Returns: long - converted number
*/
static long    get_numbers(char *src, bool is_negative)
{
    // Variable to store result
    long n;

    n = 0;
    // Convert each digit
    while (*src >= 48 && *src <= 57)
    {
        n = n * 10 + (*src - 48);
        src++;
    }
    // Apply negative sign if needed
    if (is_negative)
        return (n * -1);
    return (n);
}

/*
Purpose: Converts string to long integer
Arguments: const char *str - string to convert
Returns: long - converted number
*/
long    ft_atoi_long(const char *str)
{
    // Variables for processing
    char    *src;
    bool    is_negative;
    long    result;

    // Skip whitespace
    src = ft_trimspaces((char *)str);
    is_negative = false;
    result = 0;
    
    // Handle sign character
    if ((*src == '+' || *src == '-') && *src++ == '-')
        is_negative = true;
        
    // Convert if valid digit found
    if (*src && ft_isdigit(*src))
        result = get_numbers(src, is_negative);
        
    return (result);
}

