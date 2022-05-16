/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:35:57 by joonhan           #+#    #+#             */
/*   Updated: 2022/05/16 20:03:39 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	int				len;
	t_node			*p_node;
	static t_node	*p_head;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
}

int	main(void)
{
	int		fd;
	char	*buf;

	fd = open("hello", O_RDONLY);
	if (fd == -1)
		return (-1);
	while (TRUE)
	{
		buf = get_next_line(fd);
		if (buf == NULL)
			break ;
		printf("%s", buf);
		free(buf);
	}
	close(fd);
	// system("leaks a.out");
	return (0);
}
