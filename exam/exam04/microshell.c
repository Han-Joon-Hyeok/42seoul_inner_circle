#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

#define ERROR		 -1

#define CHILD_PROCESS 	0
#define PARENT_PROCESS	1

#define CD_BAD_ARGUMENTS		"error: cd: bad arguments"
#define CD_CHANGE_DIR_FAILED	"error: cd: cannot change directory to "
#define EXECVE_FAILED			"error: cannot execute "
#define FATAL_ERROR				"error: fatal"

typedef enum e_bool {
	FALSE,
	TRUE
}	t_bool;

enum e_pipe {
	READ,
	WRITE
};

typedef enum _e_exec {
	PIPE,
	NORMAL
} e_exec;

int	g_exit_code;

size_t	ft_strlen(char *str)
{
	size_t	len;

	if (str == NULL)
		return (0);
	len = 0;
	while (str[len] != '\0')
		len += 1 ;
	return (len);
}

void	ft_putstr_fd(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

void	print_error(char *msg, char *arg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	if (arg != NULL)
		ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	throw_error(char *msg, char *arg)
{
	print_error(msg, arg);
	exit(EXIT_FAILURE);
}

char	*ft_strdup(char *src)
{
	unsigned int	idx;
	char			*copy;

	if (src == NULL)
		return (NULL);
	idx = 0;
	copy = malloc(sizeof(char) * (ft_strlen(src) + 1));
	while (src[idx] != '\0')
	{
		copy[idx] = src[idx];
		idx += 1;
	}
	copy[idx] = '\0';
	return (copy);
}

void	close_pipes(int pipe_fd[2])
{
	close(pipe_fd[READ]);
	close(pipe_fd[WRITE]);
}

void	close_pipe_and_dup(int pipe_fd[2], int type)
{
	if (type == CHILD_PROCESS)
	{
		close(pipe_fd[READ]);
		dup2(pipe_fd[WRITE], STDOUT_FILENO);
		close(pipe_fd[WRITE]);
	}
	else
	{
		close(pipe_fd[WRITE]);
		dup2(pipe_fd[READ], STDIN_FILENO);
		close(pipe_fd[READ]);
	}
}

void	save_origin_fd(int origin_fd[2])
{
	origin_fd[STDIN_FILENO] = dup(STDIN_FILENO);
	origin_fd[STDOUT_FILENO] = dup(STDOUT_FILENO);
}

void	rollback_fd(int origin_fd[2])
{
	dup2(origin_fd[STDIN_FILENO], STDIN_FILENO);
	dup2(origin_fd[STDOUT_FILENO], STDOUT_FILENO);
	close(origin_fd[STDIN_FILENO]);
	close(origin_fd[STDOUT_FILENO]);
}

int	execute_cmd(char *cmd_name, char **cmd_argv, char **envp, e_exec type)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (pipe(pipe_fd) == ERROR)
		throw_error(FATAL_ERROR, NULL);
	pid = fork();
	if (pid == ERROR)
		throw_error(FATAL_ERROR, NULL);
	if (pid == CHILD_PROCESS)
	{
		if (type == PIPE)
		{
			close_pipe_and_dup(pipe_fd, CHILD_PROCESS);
		}
		else
		{
			close_pipes(pipe_fd);
		}
		if (execve(cmd_name, cmd_argv, envp) == ERROR)
			throw_error(EXECVE_FAILED, cmd_name);
	}
	else
	{
		if (type == PIPE)
		{
			close_pipe_and_dup(pipe_fd, PARENT_PROCESS);
		}
		else
		{
			close_pipes(pipe_fd);
		}
		waitpid(pid, NULL, 0);
	}
	return (1);
}

void	free_all(char **argv)
{
	unsigned int	idx;

	idx = 0;
	while (argv[idx] != NULL)
	{
		free(argv[idx]);
		idx += 1;
	}
	*argv = NULL;
}

void	free_command_info(char **cmd, char **argv)
{
	if (*cmd != NULL)
	{
		free(*cmd);
		*cmd = NULL;
	}
	if (argv != NULL)
		free_all(argv);
}

unsigned int	count_arguments(char **argv)
{
	unsigned int	count;

	count = 0;
	while (argv[count] != NULL)
	{
		if (strcmp(argv[count], "|") == 0 || strcmp(argv[count], ";") == 0)
			break ;
		count += 1;
	}
	return (count);
}

char	**merge_arguments(char **argv, unsigned int *idx)
{
	unsigned int	argv_idx;
	unsigned int	count;
	char			**cmd_argv;

	argv_idx = 0;
	count = count_arguments(argv);
	cmd_argv = malloc(sizeof(char *) * (count + 1));
	cmd_argv[count] = NULL;
	while (argv[argv_idx] != NULL)
	{
		if (strcmp(argv[argv_idx], "|") == 0 || strcmp(argv[argv_idx], ";") == 0)
			break ;
		else
		{
			cmd_argv[argv_idx] = ft_strdup(argv[argv_idx]);
			argv_idx += 1;
			*idx += 1;
		}
	}
	return (cmd_argv);
}

void	last_child_process(char *cmd_name, char **cmd_argv, char **envp, int origin_fd[2])
{
	pid_t	pid;

	pid = fork();
	if (pid == ERROR)
		throw_error(FATAL_ERROR, NULL);
	if (pid == CHILD_PROCESS)
	{
		if (execve(cmd_name, cmd_argv, envp) == ERROR)
			throw_error(EXECVE_FAILED, cmd_name);
	}
	else
	{
		rollback_fd(origin_fd);
		waitpid(pid, &g_exit_code, 0);
		g_exit_code = WEXITSTATUS(g_exit_code);
	}
}

void	execute_cd(char **cmd_argv)
{
	unsigned int	argv_count;
	char			*target_path;

	argv_count = count_arguments(cmd_argv);
	if (argv_count > 2)
		print_error(CD_BAD_ARGUMENTS, NULL);
	target_path = cmd_argv[1];
	if (chdir(target_path) == ERROR)
		print_error(CD_CHANGE_DIR_FAILED, target_path);
}

void	execute_commands(char **argv, char **envp)
{
	int				origin_fd[2];
	unsigned int	idx;
	unsigned int	child_count;
	char			*cmd_name;
	char			**cmd_argv;

	idx = 0;
	child_count = 0;
	cmd_name = NULL;
	cmd_argv = NULL;
	save_origin_fd(origin_fd);
	while (argv[idx] != NULL)
	{
		if (strcmp(argv[idx], "|") == 0)
		{
			child_count += execute_cmd(cmd_name, cmd_argv, envp, PIPE);
			free_command_info(&cmd_name, cmd_argv);
			idx += 1;
		}
		else if (strcmp(argv[idx], ";") == 0)
		{
			if (cmd_name != NULL)
			{
				if (strcmp(cmd_name, "cd") == 0)
					execute_cd(cmd_argv);
				else
					execute_cmd(cmd_name, cmd_argv, envp, NORMAL);
				free_command_info(&cmd_name, cmd_argv);
				rollback_fd(origin_fd);
			}
			idx += 1;
		}
		else
		{
			cmd_name = ft_strdup(argv[idx]);
			cmd_argv = merge_arguments(&argv[idx], &idx);
		}
	}
	if (cmd_name != NULL)
	{
		if (strcmp(cmd_name, "cd") == 0)
			execute_cd(cmd_argv);
		else
			last_child_process(cmd_name, cmd_argv, envp, origin_fd);
	}
	free_command_info(&cmd_name, cmd_argv);
	while (child_count != 0)
	{
		if (wait(NULL) == -1)
			exit(EXIT_FAILURE);
		child_count -= 1;
	}
}

int	main(int argc, char **argv, char **envp)
{
	if (argc == 1)
		return (EXIT_SUCCESS);
	g_exit_code = EXIT_SUCCESS;
	execute_commands(&argv[1], envp);
	return (g_exit_code);
}

/*

	argv 를 순회하면서 파이프와 세미콜론 여부를 확인한다.
	만약 다음 argv 가 파이프라면 현재까지 모은 cmd, argv 를 실행시켜서 파이프로 넘긴다.
	만약 세미콜론이라면 파이프를 열지 않고 실행시킨다.

	- 실행 파일 경로는 절대 경로 또는 상대 경로로 들어온다.
		- 이때, 프로그램의 경로를 PATH 환경변수에서 가져오면 안된다.
	- 파이프와 세미콜론을 구현해야 한다.
		- 세미콜론은 newline 과 동일함. 
		- 즉, 앞에 어떤 명령어가 오든 무조건 실행한다.
	- cd 커맨드를 구현해야 한다.
		- '~' 나 '-' 는 구현할 필요 없다.
		- argument 수가 잘못되었다면 error: cd: bad arguments 출력
		- 경로를 찾을 수 없다면 error: cd: cannot change directory to path_to_change 출력
		- cd 커맨드는 파이프 전후로 올 수 없다.

	./microshell /bin/ls
	./microshell /bin/ls "|" /bin/grep micro
	./microshell /bin/echo hello ";" /bin/echo world
	./microshell /bin/echo hello "|" /bin/grep h "|" /bin/wc -l


*/