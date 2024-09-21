/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:34:34 by tsilva            #+#    #+#             */
/*   Updated: 2024/09/21 20:44:39 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	to compile: gcc -Wall -Wextra -Werror -o test_gnl -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
	
    gcc: This is the GNU Compiler Collection, a compiler used for compiling C and C++ programs.

    -Wall: Enables most of the common warnings about potential issues in the code.
    -Wextra: Enables extra warnings beyond what -Wall provides.
    -Werror: Treats all warnings as errors.

    -o test_gnl: This tells the compiler to name the output executable file test_gnl instead of the default a.out.

    -D BUFFER_SIZE=42: This defines a preprocessor macro BUFFER_SIZE with the value 42.
    It’s useful for making buffer sizes configurable during compilation without modifying the source code.
*/

#include <stdio.h> 
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    fd = open("goals.txt", O_RDONLY);
    if (fd == -1){
        perror("Error opening file");
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL){
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}

