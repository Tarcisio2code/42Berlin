/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:15:07 by tsilva            #+#    #+#             */
/*   Updated: 2023/11/28 14:39:45 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * s: The string to be written.
 * fd: The file descriptor where the string will be written.
 *
 * This function uses `ft_putchar_fd` to write each character of the string `s` to the file descriptor `fd`.
*/
void ft_putstr_fd(char *s, int fd)
{
    // Iterate through each character of the string `s`.
    while (*s)
    {
        // Write the current character to the file descriptor `fd` using `ft_putchar_fd`.
        ft_putchar_fd(*s++, fd);
    }
}
