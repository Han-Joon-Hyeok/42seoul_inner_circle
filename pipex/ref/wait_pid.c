#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	pid_t	child_pid;
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		printf("Error\n");
	else if (pid == 0)
	{
		printf("응애 나 자식 프로세스\n");
	}
	else
	{
		child_pid = waitpid(pid, &status, 0);
		printf("나는 내 갈 길을 간다\n");
		if ((status & 0xff) == 0)
			printf("Successfully finished %d\n", status >> 8);
		else
			printf("Error occured %d\n", status);
	}
}

