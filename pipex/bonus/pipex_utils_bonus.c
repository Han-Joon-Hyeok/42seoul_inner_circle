/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:32:38 by joonhan           #+#    #+#             */
/*   Updated: 2022/10/12 15:59:57 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

int	open_file(char *file, int mode)
{
	int	fd;

	fd = 0;
	if (mode == READ_MODE)
	{
		if (access(file, F_OK) == ERROR)
			print_error(NO_FILE_OR_DIR, file);
		else if (access(file, R_OK) == ERROR)
			print_error(PERMISSON_DENIED, file);
		return (open(file, O_RDONLY));
	}
	else if (mode == WRITE_MODE)
	{
		fd = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (fd == ERROR)
		{
			if (access(file, F_OK) == ERROR)
				print_error(NO_FILE_OR_DIR, file);
			else if (access(file, W_OK | X_OK) == ERROR)
				print_error(PERMISSON_DENIED, file);
		}
		return (fd);
	}
	return (ERROR);
}
