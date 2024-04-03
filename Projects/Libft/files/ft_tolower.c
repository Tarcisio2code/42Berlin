/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:50:41 by tsilva            #+#    #+#             */
/*   Updated: 2023/11/17 10:53:12 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int ch)
// ch: represents an ASCII character code
{
  // checks if the character represented by (ch) is a uppercase letter (ASCII codes 65 to 90)
  if ((ch >= 65 && ch <= 90))
    //If the character is a uppercase letter, it returns the lowercase version of 
    //that character by adding 32 from its ASCII code
    return (ch + 32);
  else
    // otherwise it returns the character unchanged
    return (ch);
}
