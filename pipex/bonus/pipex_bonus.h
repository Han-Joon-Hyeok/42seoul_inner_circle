/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:32:41 by joonhan           #+#    #+#             */
/*   Updated: 2022/10/12 16:12:42 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>
# include <stdio.h>

# define CHILD_PROCESS	0

# define WRITE_MODE		0
# define READ_MODE		1
# define APPEND_MODE	2

# define ERROR_CODE_COMMAND_NOT_FOUND	127

# define INVALID_INPUT			"❌[./pipex infile cmd1 cmd2 ... cmdN outfile]"
# define INVALID_HEREDOC_INPUT	"❌[./pipex here_doc LIMITER cmd1 cmd2 outfile]"
# define PIPE_ERROR				"❌Error: pipe function doesn't work."
# define NO_FILE_OR_DIR			"❌Error: No such file or directory: "
# define PERMISSON_DENIED		"❌Error: permission denied: "
# define FAILED_TO_CREATE_FILE	"❌Error: Failed to create outfile."
# define FORK_ERROR				"❌Error: fork error occured."
# define COMMAND_NOT_FOUND		"❌Error: command not found: "

typedef struct s_pipex
{
	char	*cmd_path;
	char	**cmd_argv;
	char	**path;
	int		i;
	int		infile;
	int		outfile;
	int		status;
	int		process_count;
	pid_t	last_pid;
}	t_pipex;

// pipex_utils_bonus.c
void	throw_error(char *msg);
void	print_error(char *msg, char *arg);
char	**find_path(char **envp);
int		open_file(char *file, int mode);

// child_process_bonus.c
void	execute_cmd(char *argv, char **envp, t_pipex pipex);
int		child_process(char *argv, char **envp, t_pipex pipex);

// execute_here_doc_bonus.c
void	execute_here_doc(int argc, char **argv, char **envp, t_pipex pipex);

// execute_multiple_pipe_bonus.c
void	execute_multiple_pipe(\
		int argc, char **argv, char **envp, t_pipex *pipex);

#endif