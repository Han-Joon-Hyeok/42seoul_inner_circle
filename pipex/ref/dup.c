#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char *pathname;
	char *pathname2;
	int fd;
	int fd2;
    int dup_fd;

	pathname = "./hello.txt";
	pathname2 = "./world.txt";
	fd = open(pathname, O_RDWR);
	fd2 = open(pathname2, O_RDWR);
	write(fd, "hello\n", 6);
	dup_fd = dup2(fd2, fd);
	printf("%d\n", dup_fd);
	write(fd, "42seoul\n", 8);
	write(fd2, "happy\n", 6);
	write(dup_fd, "world\n", 6);
	close(fd2);
	close(dup_fd);
	return (0);
}
