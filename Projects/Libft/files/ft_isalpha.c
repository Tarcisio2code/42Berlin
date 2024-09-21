/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:45:56 by tsilva            #+#    #+#             */
/*   Updated: 2023/12/11 16:57:31 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
// c: represents an ASCII value to be checked
{
  //Checks whether the input c falls within the ASCII range of alphabetic characters
  //65 to 90: range of uppercase letters
  //97 to 122: range of lowercase letters
	if (!((c >= 65 && c <= 90) || (c >= 97 && c <= 122)))
    //If (c) is not an alphabetic character, the function returns 0 (false)
		return (0);
  //If (c) c matches any of these conditions the function returns 1 (true)
	return (1);
}
