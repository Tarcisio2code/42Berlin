/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:01:44 by tsilva            #+#    #+#             */
/*   Updated: 2024/09/21 20:48:35 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	to compile: gcc -Wall -Wextra -Werror -o ft_printf main.c -L. -lftprintf
	
	-Wall: Enables most of the common warnings about potential issues in the code.
    -Wextra: Enables extra warnings beyond what -Wall provides.
    -Werror: Treats all warnings as errors.

	-o ft_printf: This specifies the name of the output executable.
	main.c: This is the source file you want to compile.
	-L.: This tells the compiler to look for libraries in the current directory (.).
	-lftprintf: This links the libftprintf.a library (the lib prefix and .a extension are omitted in the command).
*/

#include "ft_printf.h"

int main()
{
	ft_printf("\n%s %d %s%c HexCode: %x, Location: %p, Score: %u%%\n\n", "Welcome to", 42, "Berlin", '!', 0x42, &ft_printf, 42);
}

