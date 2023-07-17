/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:18:12 by joonhan           #+#    #+#             */
/*   Updated: 2023/02/03 13:18:13 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "utils.h"

static t_bool	is_map_blocked(t_game *game)
{
	int	height_idx;
	int	width_idx;

	height_idx = 0;
	while (height_idx < game->map.height)
	{
		width_idx = 0;
		while (width_idx < game->map.width)
		{
			if (game->map.map_array[height_idx][width_idx] == '0' || \
				game->map.map_array[height_idx][width_idx] == game->player)
				if (check_wall(height_idx, width_idx, game) == FALSE)
					return (FALSE);
			width_idx += 1;
		}
		height_idx += 1;
	}
	return (TRUE);
}

static void	validate_player(char *file, t_game *game)
{
	int	map_fd;

	map_fd = open_file(file, game->line_idx);
	if (is_one_player(map_fd, game) == FALSE)
		throw_error("There are two players", NULL, game);
	if (game->player == '\0')
		throw_error("There is no player", NULL, game);
}

void	check_map_validation(t_game *game, char *file)
{
	int	map_fd;

	map_fd = game->map_fd;
	if (is_valid_line(map_fd) == FALSE)
		throw_error("Invalid character", NULL, game);
	validate_player(file, game);
	map_fd = open_file(file, game->line_idx);
	get_width_and_height(game, map_fd);
	close(map_fd);
	map_fd = open_file(file, game->line_idx);
	save_map(game, map_fd);
	close(map_fd);
	if (is_map_blocked(game) == FALSE)
		throw_error("The map did not block", NULL, game);
}
