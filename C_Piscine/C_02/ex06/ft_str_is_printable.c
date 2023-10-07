/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:22:43 by tsilva            #+#    #+#             */
/*   Updated: 2023/07/29 12:26:30 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;
	int	is_print;

	i = 0;
	is_print = 1;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 32 && str[i] <= 126))
		{
			is_print = 0;
			break ;
		}
		i++;
	}
	return (is_print);
}
/* 
#include <stdio.h>
int main(void)
{
    char printable[] = " !'/2<?T[^`t{~";
	char not_printable[] = "!'/2<?T[^`t{~\1F";
    char empty[] = "";

    printf("%d\n", ft_str_is_printable(printable));

    printf("%d\n", ft_str_is_printable(not_printable));

    printf("%d\n", ft_str_is_printable(empty));

}
*/