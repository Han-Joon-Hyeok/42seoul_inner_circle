/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:35:57 by joonhan           #+#    #+#             */
/*   Updated: 2022/05/14 20:58:38 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

t_find	exists_new_line(char *buf)
{
	t_find	result;

	result.index = 0;
	result.found = FALSE;
	while (buf[result.index] != '\0')
	{
		if (buf[result.index] == '\n')
		{
			result.found = TRUE;
			break ;
		}
		result.index += 1;
	}
	return (result);
}

char	*get_next_line(int fd)
{
	int				len;
	char			buf[BUFFER_SIZE + 1];
	t_find			result;
	static char		*backup;

	if (fd < 0)
		return (NULL);
	len = read(fd, buf, BUFFER_SIZE);
	if (len <= 0)
		return (NULL);
	result = exists_new_line(buf);
	backup = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (backup == NULL)
		return (NULL);
	backup = buf;
	if (result.found == FALSE)
	{
	}
	return (backup);
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
		printf("%s", buf);
	}
	close(fd);
	// system("leaks a.out");
	return (0);
}
