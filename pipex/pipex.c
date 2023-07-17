/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:32:30 by joonhan           #+#    #+#             */
/*   Updated: 2022/10/13 10:45:49 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		throw_error(INVALID_INPUT);
	pipex.status = 0;
	pipex.count = 0;
	pipex.path = find_path(envp);
	fork_cmd1(argv[2], envp, argv[1], &pipex);
	fork_cmd2(argv[3], envp, argv[4], &pipex);
	wait_child(&pipex);
	return (WEXITSTATUS(pipex.status));
}
