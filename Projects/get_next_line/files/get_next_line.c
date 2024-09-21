/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:33:30 by tsilva            #+#    #+#             */
/*   Updated: 2024/02/28 10:11:15 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*clean_line(char **full_line, char **buffer, int bytes_read);
static char	*extract_next(char **full_line, int size);
static char	*feth_line(char **line, char *buffer);
/*
     get_next_line is a function that reads from a file descriptor (fd) and 
     returns the next line, including the newline character if it exists. 
*/
char	*get_next_line(int fd)
{    	
	char		*buffer; 		// Buffer to temporarily hold the data read from the file
	int		next_pos;		// Position of the next newline character in full_line
	int		bytes_read;		// Number of bytes read from the file
	static char	*full_line = NULL;	// Static variable to hold the accumulated line content between function calls

	// Error handling: if the file descriptor is invalid or BUFFER_SIZE is not set correctly, clean up and return NULL
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (clean_line(&full_line, NULL, -1));

    	// Allocate memory for the buffer to hold data read from the file
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    	// If memory allocation fails, clean up and return NULL
	if (!buffer)
		return (clean_line(&full_line, NULL, -1));

	// Find the position of the next newline in the accumulated line (if any exists)
	next_pos = find_next(full_line);

	// Loop to continue reading from the file until a newline is found
	while (next_pos == -1)
	{
        	// Read up to BUFFER_SIZE bytes from the file into the buffer
		bytes_read = read(fd, buffer, BUFFER_SIZE);
 	       // If no bytes were read or an error occurred, clean up and return NULL or the full line read so far
		if (bytes_read <= 0)
			return (clean_line(&full_line, &buffer, bytes_read));

        	// Null-terminate the buffer after the read operation
		buffer[bytes_read] = '\0';
        
        	// Append the content from the buffer to the full_line
		full_line = feth_line(&full_line, buffer);

        	// If a newline is found in the buffer, exit the loop
		if (!(find_next(buffer) < 0))
			next_pos = -2;
	}

    	// Free the buffer after reading is done
	free(buffer);

    	// Extract the next line from the accumulated content and return it
	return (extract_next(&full_line, next_pos));
}

// Helper function to clean up memory and return the appropriate line or NULL
static char	*clean_line(char **full_line, char **buffer, int bytes_read)
{
	char	*tmp_line;

    	// Free the buffer if it was allocated
	if (buffer)
		free(*buffer);

    	// If there was an error during reading (bytes_read < 0), free the full_line and return NULL
	if (bytes_read < 0)
	{
		free(*full_line);
		*full_line = NULL;
		return (NULL);
	}

    	// If full_line is empty, return NULL (nothing left to read)
	if (!*full_line)
		return (NULL);

    	// Create a temporary string to hold the current content of full_line
	tmp_line = "";
	tmp_line = ft_strjoin(tmp_line, *full_line);

    	// Free the full_line after transferring its content
	free(*full_line);
	*full_line = NULL;

    	// Return the temporary string which holds the full line read so far
	return (tmp_line);
}

// Extract the next line from full_line up to the next newline character
static char	*extract_next(char **full_line, int size)
{
	char	*next;
	char	*tmp_line;

    	// If there is no content in full_line, return NULL
	if (!*full_line)
		return (NULL);

    	// If the size is negative, find the position of the next newline in full_line
	if (size < 0)
		size = find_next(*full_line);

    	// Allocate memory for the next line, including space for the newline and null terminator
	next = (char *)malloc((size + 2) * sizeof(char));
    	// If memory allocation fails, clean up and return NULL
	if (!next)
		return (clean_line(&(*full_line), NULL, -1));

    	// Copy the content of full_line up to the next newline into next
	ft_memcpy(next, *full_line, size + 1);
	next[size + 1] = '\0';  // Null-terminate the extracted line

    	// If there's more content in full_line after the newline, keep it for the next call
	if ((*full_line)[size + 1])
	{
		tmp_line = ft_strjoin("", *full_line + (size + 1));
		free(*full_line);
		*full_line = tmp_line;
	}
    	// Otherwise, clean the full_line (nothing more to read)
	else
		clean_line(&(*full_line), NULL, -1);

    	// Return the extracted line
	return (next);
}

// Append the content of buffer to full_line
static char	*feth_line(char **line, char *buffer)
{
	char	*result;

    	// If line is NULL, start with an empty string
	if (!(*line))
		result = "";
	else
		result = *line;

    	// Join the current content of line and the buffer into a new string
	result = ft_strjoin(result, buffer);

    	// Free the old content of line
	free(*line);

    	// Return the newly joined string (updated full_line)
	return (result);
}

