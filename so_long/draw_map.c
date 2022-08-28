/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:14:52 by joonhan           #+#    #+#             */
/*   Updated: 2022/08/28 21:37:25 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_put_image_to_16(t_game *game, void *obj, \
								size_t count, size_t height)
{
	mlx_put_image_to_window(game->mlx, game->win, obj, \
			count * IMAGE_WIDTH, height * IMAGE_HEIGHT);
}

void	draw_map(t_game *game)
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
			if (game->map[idx] == '1')
				ft_put_image_to_16(game, game->wall, count, height);
			else if (game->map[idx] == 'P')
				ft_put_image_to_16(game, game->chr, count, height);
			else if (game->map[idx] == 'C')
				ft_put_image_to_16(game, game->collectible, count, height);
			else if (game->map[idx] == 'E')
				ft_put_image_to_16(game, game->door, count, height);
			idx += 1;
			count += 1;
		}
		height += 1;
	}
}
