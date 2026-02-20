/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdunkel <fdunkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:53:08 by fdunkel           #+#    #+#             */
/*   Updated: 2023/11/13 17:00:20 by fdunkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int character)
{
	if (character >= 'a' && character <= 'z')
		return (1);
	else if (character >= 'A' && character <= 'Z')
		return (1);
	return (0);
}
