/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:33:01 by joonhan           #+#    #+#             */
/*   Updated: 2022/08/25 17:33:20 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_pos(t_pos *pos)
{
	pos->x = 0;
	pos->y = 0;
	pos->moves = 0;
}

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, \
									WINDOW_WIDTH, WINDOW_HEIGHT, "so_long");
}

void	init_images(t_mlx *mlx, t_game *game)
{
	int	img_width;
	int	img_height;

	game->collectible = mlx_xpm_file_to_image(mlx->mlx_ptr, \
					"./images/collectible.xpm", &img_width, &img_height);
	game->land = mlx_xpm_file_to_image(mlx->mlx_ptr, \
					"./images/land.xpm", &img_width, &img_height);
	game->wall = mlx_xpm_file_to_image(mlx->mlx_ptr, \
					"./images/wall.xpm", &img_width, &img_height);
	game->character = mlx_xpm_file_to_image(mlx->mlx_ptr, \
					"./images/cat_1.xpm", &img_width, &img_height);
	game->door = mlx_xpm_file_to_image(mlx->mlx_ptr, \
					"./images/door.xpm", &img_width, &img_height);
	game->fire = mlx_xpm_file_to_image(mlx->mlx_ptr, \
					"./images/fire.xpm", &img_width, &img_height);
}
