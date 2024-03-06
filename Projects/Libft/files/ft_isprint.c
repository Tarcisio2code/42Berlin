/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:24:27 by tsilva            #+#    #+#             */
/*   Updated: 2023/11/14 14:55:10 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
// c: represents an ASCII value to be checked
{
  // Check if the value of 'c' is not within the printable ASCII range (32 to 126)
	if (!(c >= 32 && c <= 126))
    // If 'c' is not printable, return 0 (false)
		return (0);
  // If 'c' is within the printable ASCII range, return 1 (true)
	return (1);
}
