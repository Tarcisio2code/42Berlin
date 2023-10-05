/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 10:13:21 by tsilva            #+#    #+#             */
/*   Updated: 2023/08/01 15:10:12 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;
	int	alpha;

	i = 0;
	alpha = 1;
	while (str[i] != '\0')
	{
		if (!((str[i] >= 65 && str[i] <= 90) || 
				(str[i] >= 97 && str[i] <= 122)))
		{
			alpha = 0;
			break ;
		}
		i++;
	}
	return (alpha);
}
/* 
#include <stdio.h>
int main(void)
{
    char alpha[] = "BeRLiN";
	char not_alpha[] = ".BeRLiN";
    char empty[] = "";

    printf("%d\n", ft_str_is_alpha(alpha));

    printf("%d\n", ft_str_is_alpha(not_alpha));

    printf("%d\n", ft_str_is_alpha(empty));
}
*/
