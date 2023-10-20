/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:07:31 by tsilva            #+#    #+#             */
/*   Updated: 2023/08/10 18:14:45 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_comp(char *str1, char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

void	ft_swap(char **str1, char **str2)
{
	char	*temp;

	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

void	ft_sort(int arg_pos, int size, char **argv)
{
	int	str_pos;

	str_pos = 1;
	while (str_pos < (size - arg_pos))
	{
		if (ft_comp(argv[str_pos], argv[str_pos + 1]) > 0)
		{
			ft_swap(&argv[str_pos], &argv[str_pos + 1]);
		}
		str_pos++;
	}
}

int	main(int argc, char **argv)
{
	char	*str;
	int		arg_pos;

	arg_pos = 1;
	while (arg_pos < argc)
	{
		ft_sort(arg_pos, argc, argv);
		arg_pos++;
	}
	arg_pos = 1;
	while (arg_pos < argc)
	{
		str = argv[arg_pos++];
		while (*str)
		{
			write(1, str++, 1);
		}
		write(1, "\n", 2);
	}
}
