/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:39:02 by tsilva            #+#    #+#             */
/*   Updated: 2023/12/11 16:56:15 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
// c: represents an ASCII value to be checked
{
	//Checks whether the input c falls within the ASCII range of alphanumeric characters
	//48 -> 57: range of digits (0-9)
	//65 -> 90: range of uppercase letters (A-Z)
	//97 -> 122: range of lowercase letters (a-z)
	if (!((c >= 48 && c <= 57) || (c >= 65 && c <= 90)
			|| (c >= 97 && c <= 122)))
		//If (c) is not an alphanumeric character, the function returns 0 (false)
		return (0);
	return (1);
}
