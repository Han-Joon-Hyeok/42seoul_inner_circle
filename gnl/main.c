#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*buf;

	printf("\nInvalid fd: \n");
	fd = open("./gnlTester/files/empty", O_RDWR);
	buf = get_next_line(1000);
	printf("1: %s\n", buf);
	
	buf = get_next_line(-1);
	printf("2: %s\n", buf);
	close(fd);

	buf = get_next_line(fd);
	printf("3: %s\n", buf);

	printf("\nempty: \n");
	fd = open("./gnlTester/files/empty", O_RDWR);
	buf = get_next_line(fd);
	printf("1: %s\n", buf);
	free(buf);
	
	buf = get_next_line(fd);
	printf("2: %s\n", buf);
	free(buf);
	close(fd);

	printf("\nnl: \n");
	fd = open("./gnlTester/files/nl", O_RDWR);
	buf = get_next_line(fd);
	printf("1: %s\n", buf);
	free(buf);
	
	buf = get_next_line(fd);
	printf("2: %s\n", buf);
	free(buf);

	close(fd);

	printf("\n41_no_nl: \n");
	fd = open("./gnlTester/files/41_no_nl", O_RDWR);
	buf = get_next_line(fd);
	printf("1: %s\n", buf);
	free(buf);
	
	buf = get_next_line(fd);
	printf("2: %s\n", buf);
	free(buf);
	close(fd);

	printf("\n41_with_nl: \n");
	fd = open("./gnlTester/files/41_with_nl", O_RDWR);
	buf = get_next_line(fd);
	printf("1: %s\n", buf);
	free(buf);
	
	buf = get_next_line(fd);
	printf("2: %s\n", buf);
	free(buf);

	buf = get_next_line(fd);
	printf("3: %s\n", buf);
	close(fd);

	// system("leaks a.out");
	return (0);
}
