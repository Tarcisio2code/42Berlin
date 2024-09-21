/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:32:28 by tsilva            #+#    #+#             */
/*   Updated: 2023/11/14 15:07:16 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
// c: represents an ASCII value to be checked
{
	// Checks if (c) lies within the ASCII range of digits (0-9)
	if (!(c >= 48 && c <= 57))
		//if (c) is not a digit, the function returns 0 (false)
		return (0);
	return (1);
}
