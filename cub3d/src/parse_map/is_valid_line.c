/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:18:07 by joonhan           #+#    #+#             */
/*   Updated: 2023/02/03 13:18:08 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_bool	is_valid_char(char c)
{
	if (c == '1')
		return (TRUE);
	if (c == '0')
		return (TRUE);
	if (c == ' ')
		return (TRUE);
	if (c == 'N')
		return (TRUE);
	if (c == 'S')
		return (TRUE);
	if (c == 'E')
		return (TRUE);
	if (c == 'W')
		return (TRUE);
	return (FALSE);
}

static t_bool	is_valid_character(char *line)
{
	int	idx;

	idx = 0;
	while (line[idx] != '\0')
	{
		if (line[idx] == '\n')
			break ;
		if (is_valid_char(line[idx]) == FALSE)
		{
			return (FALSE);
		}
		idx++;
	}
	return (TRUE);
}

t_bool	is_valid_line(int map_fd)
{
	t_bool	result;
	char	*line;

	result = TRUE;
	while (result == TRUE)
	{
		line = get_next_line(map_fd);
		if (line == NULL)
			break ;
		if (is_valid_character(line) == FALSE)
			result = FALSE;
		free(line);
	}
	return (result);
}
