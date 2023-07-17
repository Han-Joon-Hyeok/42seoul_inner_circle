#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	char	buffer[5000];
	int		status;
	char	*new_argv[3];
	pid_t	pid;
	pid_t	child_pid;

	new_argv[0] = "/bin/ls";
	new_argv[1] = "-al";
	new_argv[2] = NULL;
	if (pipe(fd) == -1)
		printf("Error\n");
	pid = fork();
	if (pid == -1)
		printf("Fork error\n");
	else if (pid == 0)
	{
		printf("Hi\n");
		dup2(fd[1], 1);
		execve("/bin/ls", new_argv, envp);
	}
	else
	{
		child_pid = waitpid(pid, &status, 0);
		read(fd[0], buffer, 5000);
		printf("%s", buffer);
		printf("End\n");
	}
    return (0);
}