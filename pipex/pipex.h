/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:32:41 by joonhan           #+#    #+#             */
/*   Updated: 2022/10/13 10:48:18 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>
# include <stdio.h>

# define CHILD_PROCESS	0

# define WRITE_MODE		0
# define READ_MODE		1

# define EXIT_COMMAND_NOT_EXECUTE	126
# define EXIT_COMMAND_NOT_FOUND		127
# define EXIT_INVALID_ARGUEMENT		128

# define INVALID_INPUT			"❌Usage: [./pipex infile cmd1 cmd2 outfile]"
# define PIPE_ERROR				"❌Error: pipe function doesn't work."
# define FORK_ERROR				"❌Error: fork error occured."
# define NO_FILE_OR_DIR			"❌Error: No such file or directory: "
# define PERMISSON_DENIED		"❌Error: Permission denied: "
# define FAILED_TO_CREATE_FILE	"❌Error: Failed to create outfile."
# define COMMAND_NOT_FOUND		"❌Error: command not found: "

typedef struct s_pipex
{
	char	*cmd_path;
	char	**cmd_argv;
	char	**path;
	int		status;
	int		infile;
	int		outfile;
	int		count;
}	t_pipex;

// pipex_utils.c
void	throw_error(char *msg);
void	print_error(char *msg, char *arg);
char	**find_path(char **envp);
char	*find_cmd(char **path, char *cmd);
int		open_file(char *file, int mode);

// fork.c
void	fork_cmd1(char *argv, char **envp, char *infile, t_pipex *pipex);
void	fork_cmd2(char *argv, char **envp, char *outfile, t_pipex *pipex);
void	wait_child(t_pipex *pipex);

#endif