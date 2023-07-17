/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_one_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:18:09 by joonhan           #+#    #+#             */
/*   Updated: 2023/02/03 13:18:10 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3D.h"

static t_bool	is_player(char c)
{
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

static t_bool	is_find_player(char *line, t_game *game, int height)
{
	int	idx;

	idx = 0;
	while (line[idx] != '\0')
	{
		if (game->player == '\0')
		{
			if (is_player(line[idx]))
			{
				game->player = line[idx];
				game->pos.x = idx + 0.5;
				game->pos.y = height + 0.5;
			}
		}
		else
		{
			if (is_player(line[idx]) == TRUE)
				return (FALSE);
		}
		idx += 1;
	}
	return (TRUE);
}

t_bool	is_one_player(int map_fd, t_game *game)
{
	int		height;
	t_bool	result;
	char	*line;

	height = 0;
	result = TRUE;
	while (result == TRUE)
	{
		line = get_next_line(map_fd);
		if (line == NULL)
			break ;
		if (is_find_player(line, game, height) == FALSE)
			result = FALSE;
		free(line);
		height += 1;
	}
	return (result);
}
