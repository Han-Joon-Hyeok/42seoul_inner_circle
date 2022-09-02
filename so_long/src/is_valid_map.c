/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:20:41 by joonhan           #+#    #+#             */
/*   Updated: 2022/09/03 00:22:24 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
					print_error("Error\n❌ Map isn't surrounded by wall.", game);
			}
			else if (count == 0 || count == game->map_width - 1)
			{
				if (game->map[idx] != '1')
					print_error("Error\n❌ Map isn't surrounded by wall.", game);
			}
			idx += 1;
			count += 1;
		}
	}
}

static void	check_map_size(t_game *game)
{
	size_t	map_size;

	map_size = ft_strlen(game->map);
	if (map_size < 15 || (game->map_height < 3 || game->map_width < 3))
		print_error("Error\n❌ Map size should be more than 15.", game);
	if (map_size != game->map_height * game->map_width)
		print_error("Error\n❌ Map should be in a rectangle shape.", game);
	game->map_size = map_size;
}

static void	check_requirements(t_game *game)
{
	char	*player_pos;

	player_pos = ft_strchr(game->map, 'P');
	if (!ft_strchr(game->map, 'C') || !ft_strchr(game->map, 'E') || \
		player_pos == NULL)
		print_error("Error\n❌ Check the number of C, P, E", game);
	if (ft_strchr(player_pos + 1, 'P'))
		print_error("Error\n❌ More than one player.", game);
}

void	is_valid_map(t_game *game)
{
	check_map_size(game);
	check_wall(game);
	check_requirements(game);
	print_msg("✅ SUCCESS: Map is complied with requirements.");
}
