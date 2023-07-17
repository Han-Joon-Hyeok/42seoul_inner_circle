/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:32:38 by joonhan           #+#    #+#             */
/*   Updated: 2022/10/14 08:54:39 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	throw_error(char *msg)
{
	print_error(msg, NULL);
	exit(EXIT_FAILURE);
}

void	print_error(char *msg, char *arg)
{
	char	*error_msg;

	error_msg = ft_strjoin(msg, arg);
	ft_putstr_fd(error_msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	free(error_msg);
}

char	**find_path(char **envp)
{
	int		i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
			return (ft_split(envp[i] + 5, ':'));
		i += 1;
	}
	return (NULL);
}

char	*find_cmd(char **path, char *cmd)
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

int	open_file(char *file, int mode)
{
	int	fd;

	fd = 0;
	if (mode == READ_MODE)
	{
		fd = open(file, O_RDONLY);
		if (access(file, F_OK) == ERROR)
			print_error(NO_FILE_OR_DIR, file);
		else if (access(file, R_OK) == ERROR)
			print_error(PERMISSON_DENIED, file);
		else if (fd == ERROR)
		{
			perror("");
			print_error(NULL, file);
		}
	}
	else if (mode == WRITE_MODE)
	{
		fd = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (access(file, F_OK) == ERROR)
			print_error(NO_FILE_OR_DIR, file);
		else if (fd == ERROR)
			print_error(FAILED_TO_CREATE_FILE, file);
	}
	return (fd);
}
