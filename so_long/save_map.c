/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 19:10:05 by joonhan           #+#    #+#             */
/*   Updated: 2022/08/28 19:11:14 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_strjoin_without_newline(t_game *game, char *line, size_t width)
{
	char	*temp;
	char	*prev;

	prev = ft_strdup(game->map);
	if (line[width - 1] == '\n')
	{
		temp = malloc(sizeof(char) * (width));
		ft_strlcpy(temp, line, width);
		if (game->map == NULL)
			game->map = temp;
		else
		{
			free(game->map);
			game->map = ft_strjoin(prev, temp);
			free(temp);
		}
	}
	else
	{
		temp = ft_strjoin(prev, line);
		free(game->map);
		game->map = temp;
	}
	if (prev != NULL)
		free(prev);
}

static void	save_in_oneline(t_game *game, char *line)
{
	size_t	width;

	width = ft_strlen(line);
	if (width < 3)
		print_error("❌ ERROR: Map width should be more than 3.", game);
	if (game->map_width == 0)
		game->map_width = width - 1;
	ft_strjoin_without_newline(game, line, width);
}

void	save_map(char *map_file, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(map_file, O_RDONLY);
	game->map_width = 0;
	game->map_height = 0;
	game->map = NULL;
	game->fd = fd;
	if (fd < 0)
		print_error("❌ ERROR: Opening map file failed.", game);
	line = get_next_line(fd);
	while (line != NULL)
	{
		save_in_oneline(game, line);
		free(line);
		line = get_next_line(fd);
		game->map_height += 1;
	}
	print_msg("✅ SUCCESS: Saving map completed.");
}
