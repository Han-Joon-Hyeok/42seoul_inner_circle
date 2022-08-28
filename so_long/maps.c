/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:20:41 by joonhan           #+#    #+#             */
/*   Updated: 2022/08/28 15:06:34 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

static void	check_wall(t_game *game)
{
	size_t	idx;
	size_t	count;

	idx = 0;
	while (idx < game->map_size)
	{
		count = 0;
		while (count < game->map_width)
		{
			if (idx / game->map_width == 0 || \
				idx / game->map_width == game->map_height - 1)
			{
				if (game->map[idx] != '1')
					print_error("❌ ERROR: Map isn't surrounded by wall.", game);
			}
			else if (count == 0 || count == game->map_width - 1)
			{
				if (game->map[idx] != '1')
					print_error("❌ ERROR: Map isn't surrounded by wall.", game);
			}
			idx += 1;
			count += 1;
		}
	}
}

static void	check_map_size(t_game *game)
{
	size_t	map_size;
	char	*player_pos;

	map_size = ft_strlen(game->map);
	player_pos = ft_strchr(game->map, 'P');
	if (map_size < 15 || (game->map_height < 3 || game->map_width < 3))
		print_error("❌ ERROR: Map size should be more than 15.", game);
	if (map_size != game->map_height * game->map_width)
		print_error("❌ ERROR: Map should be in a rectangle shape.", game);
	if (!ft_strchr(game->map, 'C') || !ft_strchr(game->map, 'E') || \
		player_pos == NULL)
		print_error("❌ ERROR: Check the number of C, P, E", game);
	if (ft_strchr(player_pos + 1, 'P'))
		print_error("❌ ERROR: More than one player.", game);
	game->map_size = map_size;
}

void	is_valid_map(t_game *game)
{
	check_map_size(game);
	check_wall(game);
	print_msg("✅ SUCCESS: Map is complied with requirements.");
}
