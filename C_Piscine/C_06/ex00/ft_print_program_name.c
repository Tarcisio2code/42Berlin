/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:57:35 by tsilva            #+#    #+#             */
/*   Updated: 2023/08/10 18:00:21 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*str;

	if (argc > 0)
	{
		str = argv[0];
		while (*str)
			write(1, str++, 1);
		write(1, "/n", 2);
	}
}
