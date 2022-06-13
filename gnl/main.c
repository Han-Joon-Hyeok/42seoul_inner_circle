#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	// int		fd;
	char	*buf;

	// printf("\nInvalid fd: \n");
	// fd = open("./gnlTester/files/empty", O_RDWR);
	// buf = get_next_line(1000);
	// printf("1: %s\n", buf);
	
	// buf = get_next_line(-1);
	// printf("2: %s\n", buf);
	// close(fd);

	// buf = get_next_line(fd);
	// printf("3: %s\n", buf);

	// printf("\nempty: \n");
	// fd = open("./gnlTester/files/empty", O_RDWR);
	// buf = get_next_line(fd);
	// printf("1: %s\n", buf);
	// free(buf);
	
	// buf = get_next_line(fd);
	// printf("2: %s\n", buf);
	// free(buf);
	// close(fd);

	// printf("\nnl: \n");
	// fd = open("./gnlTester/files/nl", O_RDWR);
	// buf = get_next_line(fd);
	// printf("1: %s\n", buf);
	// free(buf);
	
	// buf = get_next_line(fd);
	// printf("2: %s\n", buf);
	// free(buf);

	// close(fd);

	// printf("\n41_no_nl: \n");
	// fd = open("./gnlTester/files/41_no_nl", O_RDWR);
	// buf = get_next_line(fd);
	// printf("1: %s\n", buf);
	// free(buf);
	
	// buf = get_next_line(fd);
	// printf("2: %s\n", buf);
	// free(buf);
	// close(fd);

	// printf("\n41_with_nl: \n");
	// fd = open("./gnlTester/files/41_with_nl", O_RDWR);
	// buf = get_next_line(fd);
	// printf("1: %s\n", buf);
	// free(buf);
	
	// buf = get_next_line(fd);
	// printf("2: %s\n", buf);
	// free(buf);

	// buf = get_next_line(fd);
	// printf("3: %s\n", buf);
	// close(fd);

	printf("Multiple fd: \n");
	int	fd[4] = {open("gnlTester/files/41_with_nl", O_RDWR), open("gnlTester/files/42_with_nl", O_RDWR), open("gnlTester/files/43_with_nl", O_RDWR), open("gnlTester/files/nl", O_RDWR)};

	buf = get_next_line(1000);
	printf("1: %s\n", buf);

	buf = get_next_line(fd[0]);
	printf("2: %s\n", buf);
	free(buf);

	buf = get_next_line(1001);
	printf("3: %s\n", buf);

	buf = get_next_line(fd[1]);
	printf("4: %s\n", buf);
	free(buf);

	buf = get_next_line(1002);
	printf("5: %s\n", buf);

	buf = get_next_line(fd[2]);
	printf("6: %s\n", buf);
	free(buf);

	buf = get_next_line(1003);
	printf("7: %s\n", buf);

	buf = get_next_line(fd[0]);
	printf("8: %s\n", buf);
	free(buf);

	buf = get_next_line(1004);
	printf("9: %s\n", buf);

	buf = get_next_line(fd[1]);
	printf("10: %s\n", buf); // BUFFER_SIZE = 1000000
	free(buf);

	buf = get_next_line(1005);
	printf("11: %s\n", buf);

	buf = get_next_line(fd[2]);
	printf("12: %s\n", buf); // BUFFER_SIZE = 42
	free(buf);

	buf = get_next_line(fd[0]);
	printf("13: %s\n", buf);

	buf = get_next_line(fd[1]);
	printf("14: %s\n", buf);

	buf = get_next_line(fd[2]);
	printf("15: %s\n", buf); // BUFFER_SIZE = 1

	buf = get_next_line(1006);
	printf("16: %s\n", buf);

	buf = get_next_line(fd[3]);
	printf("17: %s\n", buf);
	free(buf);

	buf = get_next_line(1007);
	printf("18: %s\n", buf);

	buf = get_next_line(fd[3]);
	printf("19: %s\n", buf);

	// system("leaks a.out");
	return (0);
}
