/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:35:00 by tsilva            #+#    #+#             */
/*   Updated: 2023/11/17 10:53:07 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int ch)
// ch: represents an ASCII character code
{
   // checks if the character represented by (ch) is a lowercase letter (ASCII codes 97 to 122)
	if ((ch >= 97 && ch <= 122))
    //If the character is a lowercase letter, it returns the uppercase version of 
    //that character by subtracting 32 from its ASCII code
		return (ch - 32);
	else
    // otherwise it returns the character unchanged
		return (ch);
}
