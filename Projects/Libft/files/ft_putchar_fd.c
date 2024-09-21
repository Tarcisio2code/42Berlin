/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:06:12 by tsilva            #+#    #+#             */
/*   Updated: 2023/11/25 11:12:43 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * c: The character to be written.
 * fd: The file descriptor where the character will be written.
 *
 * This function uses the `write` system call to write the character `c` to the file descriptor `fd`.
*/
void ft_putchar_fd(char c, int fd)
{
    // Use the `write` system call to write the character `c` to the file descriptor `fd`.
    write(fd, &c, 1);
}
