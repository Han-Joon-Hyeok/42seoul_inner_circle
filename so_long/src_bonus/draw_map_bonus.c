/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:14:52 by joonhan           #+#    #+#             */
/*   Updated: 2022/09/01 17:44:28 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

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
			else if (game->map[idx] == 'F')
				ft_put_image_to_16(game, game->enemy, count, height);
			idx += 1;
			count += 1;
		}
		height += 1;
	}
}
