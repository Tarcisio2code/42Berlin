/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:20:51 by tsilva            #+#    #+#             */
/*   Updated: 2023/12/04 16:02:35 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * s: The string to be written.
 * fd: The file descriptor where the string and newline will be written.
 *
 * This function uses `ft_putstr_fd` to write the string and `ft_putchar_fd` to write the newline character.
*/
void ft_putendl_fd(char *s, int fd)
{
    // Write the string `s` to the file descriptor `fd`.
    ft_putstr_fd(s, fd);

    // Write a newline character to the file descriptor `fd`.
    ft_putchar_fd('\n', fd);
}
