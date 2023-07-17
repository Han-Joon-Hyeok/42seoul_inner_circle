#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	/*
		fork();
		return value
			- -1 : 실패
			- 0 : 자식 프로세스. 새로 생성된 프로세스
			- 0 초과 : 생성된 자식 프로세스 PID
	*/
	pid_t	pid;
	int		x;

	printf("Create child process\n");
	x = 0;
	pid = fork();
	/*
		부모 프로세스는 fork 의 반환값으로 자식 프로세스의 pid 를 받는다.
		그리고 자식 프로세스에서 fork의 반환값은 0이다.
	*/
	printf("Hello: %d, x: %d\n", pid, x++);
	if (pid == -1)
		printf("Fail\n");
	else if (pid == 0)
	{
		printf("I'm child process, x: %d\n", x++);
	}
	else
	{
		printf("World: %d, x: %d\n", pid, x++);
	}
}