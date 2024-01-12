/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:31:38 by tsilva            #+#    #+#             */
/*   Updated: 2023/11/14 15:07:09 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
// c: represents an ASCII value to be checked
{
	//Checks whether the input (c) is within the valid ASCII range.
	if (c < 0 || c > 127)
		//If (c) is not a valid ASCII character, the function returns 0 (false)
		return (0);
	return (1);
}
