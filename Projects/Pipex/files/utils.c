/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:13:00 by tsilva            #+#    #+#             */
/*   Updated: 2024/03/28 18:21:59 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Function to handle and display error messages
// Parameters:
//   isperror - flag to indicate whether to use perror (1) or a custom message (0)
//   err_msg - the error message to display
//   file_name - optional file name associated with the error (can be NULL)
void	msg_error(int isperror, char *err_msg, char *file_name)
{
	// If isperror is 0, print a custom error message
	if (!isperror)
	{
		// Write the error message to standard error (file descriptor 2)
		write(2, err_msg, ft_strlen(err_msg));
		
		// If a file name is provided, print it as part of the error
		if (file_name)
		{
			write(2, ": ", 2); // Print a colon and space after the error message
			write(2, file_name, strlen(file_name)); // Print the file name
			write(2, "\n", 2); // Print a newline character
		}
		else
			write(2, "\n", 2); // If no file name, just print a newline
	}
	// If isperror is 1, use perror to print the error message based on errno
	else
	{
		perror(err_msg); // perror automatically appends the system error message
	}
}

// Function to close two file descriptors
// Parameters:
//   file1 - first file descriptor to close
//   file2 - second file descriptor to close
void	close_files(int file1, int file2)
{
	// Only close the file descriptors if they are valid (not negative)
	if (!(file1 < 0) && !(file2 < 0))
	{
		// Close both file descriptors
		close(file1);
		close(file2);
	}
}

// Function to free memory allocated for command arguments and executable path
// Parameters:
//   pipex - pointer to the pipex structure containing the command arguments and executable path
void	free_args(t_pipex *pipex)
{
	int	i;

	i = 0;
	// Free each argument string in the cmd_args array
	while (pipex->cmd_args[i])
		free(pipex->cmd_args[i++]);
	// Free the cmd_args array itself
	free(pipex->cmd_args);
	// Free the executable path
	free(pipex->exec);
}

// Function to free memory allocated for command paths and close input/output files
// Parameters:
//   pipex - pointer to the pipex structure containing file descriptors and command paths
void	free_paths(t_pipex *pipex)
{
	int	i;

	i = 0;
	// Close the input and output file descriptors
	close_files(pipex->infile, pipex->outfile);
	
	// Free each path string in the cmd_paths array
	while (pipex->cmd_paths[i])
		free(pipex->cmd_paths[i++]);
	// Free the cmd_paths array itself
	free(pipex->cmd_paths);
}

// Function to retrieve the command paths from the environment variables
// Parameters:
//   envp - array of environment variables
//   pipex - pointer to the pipex structure containing file descriptors
// Returns an array of paths where executables may be found
char	**get_paths(char **envp, t_pipex *pipex)
{
	// Search for the "PATH" variable in the environment variables
	while (*envp && ft_strncmp("PATH", *envp, 4))
		envp++;
	
	// If "PATH" is not found, print an error and close files
	if (!*envp)
	{
		// Close the file descriptors
		close_files(pipex->fd[0], pipex->fd[1]);
		close_files(pipex->infile, pipex->outfile);
		// Print an error message indicating missing environment variables
		msg_error(1, ERROR_ENVP, NULL);
		// Exit the program with failure
		exit(EXIT_FAILURE);
	}
	
	// Split the "PATH" environment variable into individual paths and return them
	return (ft_split(*envp + 5, ':'));
}

