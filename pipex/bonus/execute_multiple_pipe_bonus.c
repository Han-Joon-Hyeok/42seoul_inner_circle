/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_multiple_pipe.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:53:58 by joonhan           #+#    #+#             */
/*   Updated: 2022/10/12 15:54:41 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	last_child_process(int argc, char **argv, char **envp, t_pipex *pipex)
{
	int		pipe_fd[2];

	if (pipe(pipe_fd) == ERROR)
		throw_error(PIPE_ERROR);
	pipex->last_pid = fork();
	if (pipex->last_pid == ERROR)
		throw_error(FORK_ERROR);
	if (pipex->last_pid == CHILD_PROCESS)
	{
		pipex->outfile = open_file(argv[argc - 1], WRITE_MODE);
		if (pipex->outfile == ERROR)
			exit(EXIT_FAILURE);
		close(pipe_fd[0]);
		dup2(pipex->outfile, STDOUT_FILENO);
		close(pipe_fd[1]);
		execute_cmd(argv[pipex->i], envp, *pipex);
	}
	else
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		waitpid(pipex->last_pid, &pipex->status, 0);
	}
}

void	execute_multiple_pipe(
	int argc, char **argv, char **envp, t_pipex *pipex)
{
	pipex->i = 2;
	pipex->process_count = 0;
	pipex->infile = open_file(argv[1], READ_MODE);
	dup2(pipex->infile, STDIN_FILENO);
	if (pipex->infile == ERROR)
		pipex->i = 3;
	while (pipex->i < argc - 2)
		pipex->process_count += child_process(argv[pipex->i++], envp, *pipex);
	last_child_process(argc, argv, envp, pipex);
	while (pipex->process_count > 0)
	{
		if (wait(NULL) == ERROR)
			exit(EXIT_FAILURE);
		else
			pipex->process_count -= 1;
	}
}
