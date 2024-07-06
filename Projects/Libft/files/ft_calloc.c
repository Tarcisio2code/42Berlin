/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:54:03 by tsilva            #+#    #+#             */
/*   Updated: 2023/12/03 14:12:38 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Returns a pointer to the allocated memory, which is set to zero. If the allocation fails, returns NULL.
 * nmemb: Number of elements to allocate.
 * size: Size of each element in bytes.
 */
void *ft_calloc(size_t nmemb, size_t size)
{
    // Declare a pointer to hold the allocated memory.
    void *p;

    // Allocate memory for the array with nmemb elements, each of size bytes.
    // Cast the result to void* since malloc returns a generic pointer.
    p = (void *)malloc(nmemb * size);

    // Check if malloc failed to allocate memory.
    if (!p)
        // If malloc failed, return NULL (0).
        return (0);

    // If malloc succeeded, initialize all allocated memory to zero using ft_bzero.
    ft_bzero(p, size * nmemb);

    // Return the pointer to the allocated and zero-initialized memory.
    return (p);
}
