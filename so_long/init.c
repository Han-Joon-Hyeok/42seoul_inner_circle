/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:33:01 by joonhan           #+#    #+#             */
/*   Updated: 2022/08/28 21:15:05 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window_size(t_game *game)
{
	game->window_width = game->map_width * IMAGE_WIDTH;
	game->window_height = game->map_height * IMAGE_HEIGHT;
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

void	init_offset(t_game *game)
{
	game->offset[KEY_W] = -((ssize_t)game->map_width);
	game->offset[KEY_A] = -1;
	game->offset[KEY_S] = ((ssize_t)game->map_width);
	game->offset[KEY_D] = 1;
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
