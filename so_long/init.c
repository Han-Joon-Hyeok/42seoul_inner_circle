/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:33:01 by joonhan           #+#    #+#             */
/*   Updated: 2022/08/27 13:57:42 by joonhan          ###   ########.fr       */
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
			mlx_put_image_to_window(game->mlx, game->win, game->land, \
					count * IMAGE_WIDTH, height * IMAGE_HEIGHT);
			if (game->map[idx] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall, \
						count * IMAGE_WIDTH, height * IMAGE_HEIGHT);
			else if (game->map[idx] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->chr, \
						count * IMAGE_WIDTH, height * IMAGE_HEIGHT);
			else if (game->map[idx] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, \
				game->collectible, count * IMAGE_WIDTH, height * IMAGE_HEIGHT);
			else if (game->map[idx] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->door, \
						count * IMAGE_WIDTH, height * IMAGE_HEIGHT);
			idx += 1;
			count += 1;
		}
		height += 1;
	}
}

void	init_pos(t_game *game)
{
	t_pos	*pos;

	pos = malloc(sizeof(t_pos));
	pos->x = 0;
	pos->y = 0;
	pos->moves = 0;
	game->pos = pos;
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
	game->fire = mlx_xpm_file_to_image(game->mlx, \
					"./images/fire.xpm", &img_width, &img_height);
}
