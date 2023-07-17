/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:46:44 by joonhan           #+#    #+#             */
/*   Updated: 2022/10/13 10:49:37 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	execute_cmd(char *argv, char **envp, t_pipex pipex)
{
	pipex.cmd_argv = ft_split(argv, ' ');
	pipex.cmd_path = find_cmd(pipex.path, pipex.cmd_argv[0]);
	if (execve(pipex.cmd_path, pipex.cmd_argv, envp) == ERROR)
	{
		print_error(COMMAND_NOT_FOUND, pipex.cmd_argv[0]);
		free_double_arr(pipex.cmd_argv);
		free(pipex.cmd_path);
		exit(EXIT_COMMAND_NOT_FOUND);
	}
}

static void	close_pipe(int pipe_fd[2])
{
	close(pipe_fd[0]);
	close(pipe_fd[1]);
}

void	fork_cmd1(char *argv, char **envp, char *infile, t_pipex *pipex)
{
	pid_t	pid;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == ERROR)
		throw_error(PIPE_ERROR);
	pid = fork();
	if (pid == ERROR)
		throw_error(FORK_ERROR);
	if (pid == CHILD_PROCESS)
	{
		pipex->infile = open_file(infile, READ_MODE);
		if (pipex->infile == ERROR)
			exit(EXIT_FAILURE);
		dup2(pipex->infile, STDIN_FILENO);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close_pipe(pipe_fd);
		execute_cmd(argv, envp, *pipex);
	}
	else
	{
		dup2(pipe_fd[0], STDIN_FILENO);
		close_pipe(pipe_fd);
		pipex->count += 1;
	}
}

void	fork_cmd2(char *argv, char **envp, char *outfile, t_pipex *pipex)
{
	pid_t	pid;

	pid = fork();
	if (pid == ERROR)
		throw_error(FORK_ERROR);
	if (pid == CHILD_PROCESS)
	{
		pipex->outfile = open_file(outfile, WRITE_MODE);
		if (pipex->outfile == ERROR)
			exit(EXIT_FAILURE);
		dup2(pipex->outfile, STDOUT_FILENO);
		execute_cmd(argv, envp, *pipex);
	}
	else
	{
		close(STDIN_FILENO);
		waitpid(pid, &pipex->status, 0);
	}
}

void	wait_child(t_pipex *pipex)
{
	while (pipex->count > 0)
	{
		if (wait(NULL) == ERROR)
			exit(EXIT_FAILURE);
		else
			pipex->count -= 1;
	}
}
