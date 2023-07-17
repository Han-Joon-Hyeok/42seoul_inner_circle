#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	int		fd[2];
	char	buffer[12];
	pid_t	pid;

	if (pipe(fd) == -1)
		printf("Error occured\n");
    pid = fork();
	// fork 를 수행하면 pipe 로 생성한 fd 도 공유를 한다.
	// fd[0] : 읽기 전용 
	// fd[1] : 쓰기 전용
	printf("fd[0]: %d, fd[1]: %d\n", fd[0], fd[1]);
    if (pid == -1)
		printf("Error occured\n");
	else if (pid == 0)
	{
		read(fd[0], buffer, 12);
		printf("%s", buffer);
		write(fd[1], "I'm child\n", 12);
		read(fd[0], buffer, 12);
		printf("%s", buffer);
	}
	else
	{
		write(fd[1], "Hello Child\n", 12);
	}
}