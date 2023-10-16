/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:34:00 by tsilva            #+#    #+#             */
/*   Updated: 2023/08/09 12:35:27 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}
/* 
#include <stdio.h>
int 	main(void)
{
	char *str;
	str = "42Berlin is an excellent place to learn :)";
	printf("number of char = %d\n", ft_strlen(str));
}
*/