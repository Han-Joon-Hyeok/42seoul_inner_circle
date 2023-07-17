/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:32:30 by joonhan           #+#    #+#             */
/*   Updated: 2022/10/12 16:11:11 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc < 5)
		throw_error(INVALID_INPUT);
	pipex.path = find_path(envp);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		if (argc != 6 || ft_strlen(argv[1]) != 8)
			throw_error(INVALID_HEREDOC_INPUT);
		execute_here_doc(argc, argv, envp, pipex);
	}
	else
	{
		execute_multiple_pipe(argc, argv, envp, &pipex);
		return (WEXITSTATUS(pipex.status));
	}
}
