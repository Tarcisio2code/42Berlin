/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:56:10 by tsilva            #+#    #+#             */
/*   Updated: 2024/04/02 14:29:09 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	make_child1(char **argv, char **envp, t_pipex *pipex);
static void	make_child2(char **argv, char **envp, t_pipex *pipex);
static int	make_pipe(char **argv, char **envp, t_pipex *pipex);
static char	*get_exec(t_pipex *pipex);

// Main function to handle the pipex process and check argument count
// Parameters:
//   argc - number of command line arguments
//   argv - array of command line arguments
//   envp - array of environment variables
// Returns 0 on successful execution, or exits the program on error
int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex; // Struct to store pipex-related variables

	// Check if the number of arguments is incorrect (should be exactly 5)
	if (argc != 5)
	{
		// Display error message and exit
		msg_error(0, ERROR_ARGS, NULL);
		exit(EXIT_FAILURE);
	}
	else
	{
		// Open input file (argv[1]) in read-only mode
		pipex.infile = open(argv[1], O_RDONLY);
		// Check if opening the input file failed
		if (pipex.infile < 0)
			msg_error(1, argv[1], NULL);
		
		// Open or create output file (argv[4]) with write and read permissions
		pipex.outfile = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0644);
		// Check if opening the output file failed
		if (pipex.outfile < 0)
			msg_error(1, argv[4], NULL);
		
		// If either file couldn't be opened, exit the program
		if (pipex.infile < 0 || pipex.outfile < 0)
			exit(EXIT_FAILURE);
		
		// Proceed to create a pipe and fork child processes
		make_pipe(argv, envp, &pipex);
	}
	return (0); // Return 0 on successful completion
}

// Function to create a pipe and fork two child processes
// Parameters:
//   argv - array of command line arguments
//   envp - array of environment variables
//   pipex - pointer to pipex structure containing file descriptors and paths
// Returns 0 on success
static int	make_pipe(char **argv, char **envp, t_pipex *pipex)
{
	// Create a pipe and check if it fails
	if (pipe(pipex->fd) < 0)
	{
		// Display error message for pipe failure and exit
		msg_error(1, ERROR_PIPE, NULL);
		exit(EXIT_FAILURE);
	}
	
	// Retrieve command paths from the environment variables
	pipex->cmd_paths = get_paths(envp, pipex);
	
	// Fork the first child process
	pipex->pid_1 = fork();
	// If it's the first child process, execute the first command
	if (pipex->pid_1 == 0)
		make_child1(argv, envp, pipex);
	
	// Fork the second child process
	pipex->pid_2 = fork();
	// If it's the second child process, execute the second command
	if (pipex->pid_2 == 0)
		make_child2(argv, envp, pipex);
	
	// Close the pipe and file descriptors in the parent process
	close_files(pipex->fd[0], pipex->fd[1]);
	close_files(pipex->infile, pipex->outfile);
	
	// Wait for both child processes to finish
	waitpid(pipex->pid_1, NULL, 0);
	waitpid(pipex->pid_2, NULL, 0);
	
	// Free memory allocated for command paths
	free_paths(pipex);
	return (0); // Return 0 on success
}

// Function to handle the first child process, execute the first command
// Parameters:
//   argv - array of command line arguments
//   envp - array of environment variables
//   pipex - pointer to pipex structure containing file descriptors and paths
static void	make_child1(char **argv, char **envp, t_pipex *pipex)
{
	// Duplicate stdout to write to the pipe
	pipex->child1[0] = dup2(pipex->fd[1], STDOUT_FILENO);
	// Close unused file descriptors
	close_files(pipex->fd[0], pipex->fd[1]);
	
	// Duplicate stdin to read from the input file
	pipex->child1[1] = dup2(pipex->infile, STDIN_FILENO);
	close_files(pipex->infile, pipex->outfile);
	
	// Check if the command string is empty
	if (!argv[2][0])
	{
		free_paths(pipex);
		msg_error(0, strerror(EACCES), NULL);
		exit(EXIT_FAILURE);
	}
	
	// Split the command string into arguments
	pipex->cmd_args = ft_split(argv[2], ' ');
	// Get the executable path for the command
	pipex->exec = get_exec(pipex);
	
	// If the executable couldn't be found, display error and exit
	if (!(pipex->exec))
	{
		msg_error(0, ERROR_EXEC, pipex->cmd_args[0]);
		free_args(pipex);
		close_files(pipex->child1[0], pipex->child1[1]);
		exit(EXIT_FAILURE);
	}
	
	// Execute the command
	execve(pipex->exec, pipex->cmd_args, envp);
}

// Function to handle the second child process, execute the second command
// Parameters:
//   argv - array of command line arguments
//   envp - array of environment variables
//   pipex - pointer to pipex structure containing file descriptors and paths
static void	make_child2(char **argv, char **envp, t_pipex *pipex)
{
	// Duplicate stdin to read from the pipe
	pipex->child2[0] = dup2(pipex->fd[0], STDIN_FILENO);
	// Close unused file descriptors
	close_files(pipex->fd[0], pipex->fd[1]);
	
	// Duplicate stdout to write to the output file
	pipex->child2[1] = dup2(pipex->outfile, STDOUT_FILENO);
	close_files(pipex->infile, pipex->outfile);
	
	// Check if the command string is empty
	if (!argv[3][0])
	{
		free_paths(pipex);
		msg_error(0, strerror(EACCES), NULL);
		exit(EXIT_FAILURE);
	}
	
	// Split the command string into arguments
	pipex->cmd_args = ft_split(argv[3], ' ');
	// Get the executable path for the command
	pipex->exec = get_exec(pipex);
	
	// If the executable couldn't be found, display error and exit
	if (!(pipex->exec))
	{
		msg_error(0, ERROR_EXEC, pipex->cmd_args[0]);
		free_args(pipex);
		close_files(pipex->child2[0], pipex->child2[1]);
		exit(EXIT_FAILURE);
	}
	
	// Execute the command
	execve(pipex->exec, pipex->cmd_args, envp);
}

// Function to get the executable path for a given command
// Parameters:
//   pipex - pointer to pipex structure containing file descriptors and paths
// Returns the path to the executable or NULL if not found
static char	*get_exec(t_pipex *pipex)
{
	char	*pathname; // Holds the final path of the executable
	char	*path;     // Holds the current path being checked
	char	**paths;   // Array of all possible command paths

	// Iterate over each path in the environment variable paths
	paths = pipex->cmd_paths;
	while (*paths)
	{
		// Join the path with the command to form the full executable path
		path = ft_strjoin(*paths, "/");
		pathname = ft_strjoin(path, *(pipex->cmd_args));
		free(path); // Free the temporary path string
		
		// Check if the executable exists and is accessible
		if (access(pathname, F_OK | X_OK) == 0)
		{
			return (pathname); // Return the executable path if found
		}
		free(pathname); // Free the pathname if it's not valid
		paths++; // Move to the next path in the array
	}
	
	// Free the allocated memory for paths if executable wasn't found
	free_paths(pipex);
	return (NULL); // Return NULL if no executable was found
}

