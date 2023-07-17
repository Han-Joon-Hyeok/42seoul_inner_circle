/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_here_doc_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:17:50 by joonhan           #+#    #+#             */
/*   Updated: 2022/10/12 16:04:40 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	is_equal_to_limiter(char *line, char *limiter)
{
	ssize_t	line_len;
	ssize_t	limiter_len;

	line_len = ft_strlen(line);
	limiter_len = ft_strlen(limiter);
	if (ft_strncmp(line, limiter, limiter_len) != 0)
		return (FALSE);
	if (line_len - 1 != limiter_len)
		return (FALSE);
	return (TRUE);
}

static void	get_user_input(char **argv)
{
	pid_t	pid;
	char	*line;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		throw_error(PIPE_ERROR);
	pid = fork();
	if (pid == 0)
	{
		close(pipe_fd[0]);
		while (TRUE)
		{
			ft_putstr_fd("heredoc> ", STDIN_FILENO);
			line = get_next_line(STDIN_FILENO);
			if (is_equal_to_limiter(line, argv[2]))
				exit(EXIT_SUCCESS);
			ft_putstr_fd(line, pipe_fd[1]);
		}
	}
	else
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

static int	open_heredoc_outfile(char *file)
{
	int		fd;
	ssize_t	file_name_len;

	fd = 0;
	file_name_len = ft_strlen(file);
	if (file_name_len == 0)
	{
		print_error(NO_FILE_OR_DIR, NULL);
		return (ERROR);
	}
	fd = open(file, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd == ERROR)
	{
		if (access(file, F_OK) == ERROR)
			print_error(NO_FILE_OR_DIR, file);
		else if (access(file, W_OK) == ERROR)
			print_error(PERMISSON_DENIED, file);
	}
	return (fd);
}

void	execute_here_doc(int argc, char **argv, char **envp, t_pipex pipex)
{
	get_user_input(argv);
	pipex.outfile = open_heredoc_outfile(argv[argc - 1]);
	child_process(argv[3], envp, pipex);
	wait(NULL);
	if (pipex.outfile == ERROR)
		exit(EXIT_FAILURE);
	else
	{
		dup2(pipex.outfile, STDOUT_FILENO);
		execute_cmd(argv[4], envp, pipex);
	}
}
