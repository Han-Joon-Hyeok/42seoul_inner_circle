/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:18:05 by joonhan           #+#    #+#             */
/*   Updated: 2023/02/03 13:18:06 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "libft.h"

static int	get_height(char *line, int *height, t_game *game)
{
	int		exclude_cnt;

	exclude_cnt = *height;
	if (game->map.is_n_continue == TRUE && ft_strcmp(line, "\n") != 0)
	{
		exclude_cnt += game->map.n_cnt;
		game->map.is_n_continue = FALSE;
		game->map.n_cnt = 0;
		exclude_cnt += 1;
	}
	else if (game->map.is_n_continue == FALSE && ft_strcmp(line, "\n") != 0)
		exclude_cnt += 1;
	else if (ft_strcmp(line, "\n") == 0)
	{
		game->map.is_n_continue = TRUE;
		game->map.n_cnt += 1;
	}
	return (exclude_cnt);
}

static void	get_max_width(t_game *game, char *line)
{
	int	idx;

	idx = 0;
	while (line[idx] != '\0')
	{
		if (line[idx] == '\n')
		{
			if (game->map.width == 0)
				game->map.width = idx;
			else if (game->map.width < idx)
				game->map.width = idx;
			break ;
		}
		if (line[idx + 1] == '\0')
		{
			if (game->map.width == 0)
				game->map.width = idx;
			else if (game->map.width < idx)
				game->map.width = idx;
			break ;
		}
		idx++;
	}
}

static void	save_line(t_game *game, char *line, int height_idx)
{
	int	idx;

	idx = 0;
	game->map.map_array[height_idx] = \
	(char *)malloc(sizeof(char) * (game->map.width + 1));
	ft_bzero(game->map.map_array[height_idx], game->map.width + 1);
	while (line[idx] != '\0')
	{
		if (line[idx] == '\n')
		{
			game->map.map_array[height_idx][idx] = '\0';
			break ;
		}
		game->map.map_array[height_idx][idx] = line[idx];
		idx++;
	}
}

void	get_width_and_height(t_game *game, int map_fd)
{
	char	*line;
	int		height;

	height = 0;
	line = get_next_line(map_fd);
	while (line != NULL)
	{
		height = get_height(line, &height, game);
		get_max_width(game, line);
		free(line);
		line = get_next_line(map_fd);
	}
	game->map.height = height;
}

void	save_map(t_game *game, int map_fd)
{
	char	*line;
	int		height_idx;

	height_idx = 0;
	game->map.map_array = \
	(char **)malloc(sizeof(char *) * (game->map.height + 1));
	line = get_next_line(map_fd);
	while (line != NULL)
	{
		if (height_idx == game->map.height)
		{
			free(line);
			break ;
		}
		save_line(game, line, height_idx);
		height_idx += 1;
		free(line);
		line = get_next_line(map_fd);
	}
	game->map.map_array[height_idx] = NULL;
}
