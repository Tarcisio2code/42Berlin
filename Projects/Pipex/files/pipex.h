/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:52:42 by tsilva            #+#    #+#             */
/*   Updated: 2024/03/28 18:35:44 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Header guard to prevent multiple inclusions of this header file.
#ifndef PIPEX_H
# define PIPEX_H

// Error message macros for different types of failures.
# define ERROR_ARGS "Invalid number of Arguments"   // Error when argument count is incorrect.
# define ERROR_PIPE "Error creating Pipe"           // Error when pipe creation fails.
# define ERROR_ENVP "Error reading envp"            // Error when reading environment variables fails.
# define ERROR_EXEC "Command not found"             // Error when a command cannot be executed.

// Includes necessary libraries and external functions:

# include "./libft/src/libft.h"  // Include libft library for custom utilities (e.g., string manipulation).
# include <fcntl.h>          // For file control operations (e.g., open, close, read, write).
# include <sys/wait.h>       // For process control (e.g., waitpid, managing child processes).
# include <errno.h>          // For handling system-level errors and retrieving error codes.

// Struct that contains variables for managing pipex processes and file descriptors.
typedef struct s_pipex
{
	pid_t	pid_1;     // Process ID of the first child.
	pid_t	pid_2;     // Process ID of the second child.
	int		pipe[2];   // Array for pipe file descriptors (pipe[0] for reading, pipe[1] for writing).
	int		fd[2];     // Array for input/output file descriptors.
	int		infile;    // File descriptor for input file.
	int		outfile;   // File descriptor for output file.
	int		child1[2]; // File descriptors for first child's input/output redirection.
	int		child2[2]; // File descriptors for second child's input/output redirection.
	char	**cmd_paths; // Array of paths where commands can be found.
	char	**cmd_args;  // Array of arguments for the current command.
	char	*exec;       // Full path to the executable command.
}	t_pipex;  // Alias for the structure `s_pipex`, which is used to store pipex-related data.

void	msg_error(int isperror, char *err_msg, char *file);
void	close_files(int file1, int file2);
void	free_args(t_pipex *pipex);
void	free_paths(t_pipex *pipex);
char	**get_paths(char **envp, t_pipex *pipex);

#endif
