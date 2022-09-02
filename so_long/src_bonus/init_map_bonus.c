/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:14:52 by joonhan           #+#    #+#             */
/*   Updated: 2022/09/02 16:35:18 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

static void	draw_object(t_game *game, char object, size_t count, size_t height)
{
	if (object == '1')
		ft_put_image_to_16(game, game->wall, count, height);
	else if (object == 'P')
	{
		game->character_pos = &game->map[((game->map_width * height) + count) \
								- (size_t)game->map];
		ft_put_image_to_16(game, game->chr, count, height);
	}
	else if (object == 'C')
		ft_put_image_to_16(game, game->collectible, count, height);
	else if (object == 'E')
		ft_put_image_to_16(game, game->door, count, height);
	else if (object == 'F')
		ft_put_image_to_16(game, game->enemy, count, height);
}	

void	init_map(t_game *game)
{
	size_t	idx;
	size_t	height;
	size_t	count;

	idx = 0;
	height = 0;
	while (idx < game->map_size)
	{
		count = 0;
		while (count < game->map_width)
		{
			ft_put_image_to_16(game, game->land, count, height);
			draw_object(game, game->map[idx], count, height);
			idx += 1;
			count += 1;
		}
		height += 1;
	}
}
