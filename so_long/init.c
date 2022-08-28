/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:33:01 by joonhan           #+#    #+#             */
/*   Updated: 2022/08/28 15:16:06 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window_size(t_game *game)
{
	game->window_width = game->map_width * IMAGE_WIDTH;
	game->window_height = game->map_height * IMAGE_HEIGHT;
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

void	init_moves(t_game *game)
{
	game->moves = 0;
}

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, \
						game->window_width, game->window_height, "so_long");
}

void	init_images(t_game *game)
{
	int	img_width;
	int	img_height;

	game->collectible = mlx_xpm_file_to_image(game->mlx, \
					"./images/collectible.xpm", &img_width, &img_height);
	game->land = mlx_xpm_file_to_image(game->mlx, \
					"./images/land.xpm", &img_width, &img_height);
	game->wall = mlx_xpm_file_to_image(game->mlx, \
					"./images/wall.xpm", &img_width, &img_height);
	game->chr = mlx_xpm_file_to_image(game->mlx, \
					"./images/cat_1.xpm", &img_width, &img_height);
	game->door = mlx_xpm_file_to_image(game->mlx, \
					"./images/door.xpm", &img_width, &img_height);
}
