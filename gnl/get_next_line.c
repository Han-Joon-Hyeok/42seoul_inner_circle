#include "get_next_line.h"
#include <fcntl.h>

char	*get_next_line(int fd)
{
	int	len;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (buf == NULL)
		return (NULL);
	len = read(fd, buf, BUFFER_SIZE);
	if (len <= 0)
		return (NULL);
	return (buf);
}

int	main(void)
{
	int	fd;
	int	result;
	char	*buf;

	fd = open("hello", O_RDONLY);
	if (fd == -1)
		return (-1);
	result = 1;
	while (result != 0)
	{
		buf = get_next_line(fd);
		if (buf == NULL)
			result = 0;
		write(1, buf, BUFFER_SIZE);
	}
	return (0);
}
