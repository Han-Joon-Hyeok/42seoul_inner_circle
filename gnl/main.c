#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
    char	*buf;

	printf("41_no_nl: \n");
	fd = open("./gnlTester/files/41_no_nl", O_RDWR);
    buf = get_next_line(fd);
	printf("1: %s\n", buf);
    free(buf);
	
    buf = get_next_line(fd);
	printf("2: %s\n", buf);
    free(buf);
	close(fd);
	// system("leaks a.out");
	return (0);
}
