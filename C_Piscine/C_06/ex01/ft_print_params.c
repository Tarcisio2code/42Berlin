/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:02:34 by tsilva            #+#    #+#             */
/*   Updated: 2023/08/10 18:04:59 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*str;
	int		pos;

	pos = 1;
	while (pos < argc)
	{
		str = argv[pos++];
		while (*str)
			write(1, str++, 1);
		write(1, "\n", 2);
	}
}
