#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int	main(void)
{
	pid_t	pid;
	pid_t	pid_child;
	int		status;

	pid = fork();
	if (pid == -1)
		printf("Error\n");
	else if (pid == 0)
	{
		printf("I'm child process\n");
		return (99);
	}
	// 4바이트 == 32비트
	// 99 = 0000 0000 / 0000 0000 / 0000 0000 / 0110 0011
	// 0xFF = 1111 1111
	// 0000 0000 / 0000 0000 / 0000 0000 / 0000 0000 
	// wait 가 끝나면 status 의 값에는
	// 0000 0000 / 0000 0000 / 0110 0011 / 0000 0000 => 25344
	// 0000 0000 / 0000 0000 / 0000 0000 / 0110 0011 => status >> 8
	// 0000 0000 / 0000 0000 / 0000 0000 / 1111 1101 => status (오류 발생 시)
	// 0000 0000 / 0000 0000 / 0000 0000 / 1111 1111 == 0
	else
	{
		printf("Parent process waits child %d\n", status);
		pid_child = wait(&status);
		if ((status & 0xff) == 0)
			printf("Successfully child process finished %d, %d\n", status, status >> 8);
		else
			printf("Error occured %d\n", status);
		printf("I'm parent\n");
	}
	return (0);
}