/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:05:27 by tsilva            #+#    #+#             */
/*   Updated: 2023/08/10 18:06:35 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*str;
	int		pos;

	pos = argc - 1;
	while (pos > 0)
	{
		str = argv[pos--];
		while (*str)
			write(1, str++, 1);
		write(1, "\n", 2);
	}
}
