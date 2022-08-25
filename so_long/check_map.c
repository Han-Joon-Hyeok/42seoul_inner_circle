/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:20:41 by joonhan           #+#    #+#             */
/*   Updated: 2022/08/25 20:56:18 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_strjoin_without_newline(t_game *game, char *line, size_t width)
{
	char	*temp;
	char	*save;

	if (line[width - 1] == '\n')
	{
		temp = malloc(sizeof(char) * (width));
		ft_strlcpy(temp, line, width);
		if (game->map == NULL)
			game->map = temp;
		else
		{
			save = ft_strjoin(ft_strdup(game->map), temp);
			free(game->map);
			free(temp);
			game->map = save;
		}
	}
	else
	{
		save = ft_strjoin(ft_strdup(game->map), line);
		free(game->map);
		game->map = save;
	}
}

static void	save_in_oneline(t_game *game, char *line)
{
	size_t	width;

	width = ft_strlen(line);
	if (width < 3)
		print_error("❌ ERROR: Map width should be more than 3.");
	if (game->width == 0)
		game->width = width - 1;
	ft_strjoin_without_newline(game, line, width);
}

static void	check_map_size(t_game *game)
{
	size_t	idx;
	size_t	height;
	size_t	map_size;

	idx = 0;
	height = 0;
	map_size = ft_strlen(game->map);
	if (map_size < 15 || (game->height < 3 && game->width < 3))
		print_error("❌ ERROR: Map size should be more than 15.");
	if (map_size / game->height != game->width)
		print_error("❌ ERROR: Map should be in a rectangle shape.");
	if (!ft_strchr(game->map, 'C') || !ft_strchr(game->map, 'E') || \
		!ft_strchr(game->map, 'P'))
		print_error("❌ ERROR: Map should contain \
					at least one collectible, exit and player.");
	while (height < game->height)
	{
		if (height == 0 || height == game->height - 1)
		{
			while (idx % game->width < game->width)
			{
				if (game->map[idx] != '1')
				{
					free(game->map);
					print_error("❌ ERROR: Map should be surrounded by walls.");
				}
				idx += 1;
			}
		}
		else
		{
			while (idx % game->width < game->width)
			{
				if (idx % game->width == 0 || idx % game->width == game->width - 1)
				{
					if (game->map[idx] != '1')
					{
						free(game->map);
						print_error("❌ ERROR: Map should be surrounded by walls.");
					}
				}
				idx += 1;
			}
		}
		height += 1;
	}
	game->map_size = map_size;
}

void	is_valid_map(char *map_file, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(map_file, O_RDONLY);
	game->width = 0;
	game->height = 0;
	game->map = NULL;
	if (fd < 0)
		print_error("❌ ERROR: Opening map file failed.");
	line = get_next_line(fd);
	while (line != NULL)
	{
		save_in_oneline(game, line);
		free(line);
		line = get_next_line(fd);
		game->height += 1;
	}
	check_map_size(game);
}
