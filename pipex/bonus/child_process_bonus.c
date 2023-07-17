/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:10:09 by joonhan           #+#    #+#             */
/*   Updated: 2022/10/14 08:55:34 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	*find_cmd(char **path, char *cmd)
{
	int		i;
	char	*temp;
	char	*cmd_path;

	i = 0;
	if (access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));
	while (path != NULL && path[i] != NULL)
	{
		temp = ft_strjoin(path[i], "/");
		cmd_path = ft_strjoin(temp, cmd);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(temp);
		free(cmd_path);
		i += 1;
	}
	return (NULL);
}

void	execute_cmd(char *argv, char **envp, t_pipex pipex)
{
	pipex.cmd_argv = ft_split(argv, ' ');
	pipex.cmd_path = find_cmd(pipex.path, pipex.cmd_argv[0]);
	if (execve(pipex.cmd_path, pipex.cmd_argv, envp) == ERROR)
	{
		print_error(COMMAND_NOT_FOUND, pipex.cmd_argv[0]);
		free_double_arr(pipex.cmd_argv);
		free(pipex.cmd_path);
		exit(ERROR_CODE_COMMAND_NOT_FOUND);
	}
}

int	child_process(char *argv, char **envp, t_pipex pipex)
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
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		execute_cmd(argv, envp, pipex);
	}
	else
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		waitpid(pid, NULL, WNOHANG);
	}
	return (1);
}
