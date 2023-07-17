/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:18:06 by joonhan           #+#    #+#             */
/*   Updated: 2023/02/03 13:18:07 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

int	open_file(char *file, int line_idx)
{
	int		i;
	int		map_fd;
	char	*line;

	i = 0;
	map_fd = open(file, O_RDONLY, 0644);
	while (i < line_idx)
	{
		line = get_next_line(map_fd);
		free(line);
		i++;
	}
	return (map_fd);
}
