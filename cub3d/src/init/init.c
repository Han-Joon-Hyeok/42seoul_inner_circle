/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:18:12 by joonhan           #+#    #+#             */
/*   Updated: 2023/02/03 13:18:13 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <fcntl.h>

void	init_game(t_game *game, char *file)
{
	game->wall.no = NULL;
	game->wall.so = NULL;
	game->wall.ea = NULL;
	game->wall.we = NULL;
	game->ceiling = NULL;
	game->floor = NULL;
	game->map_fd = ERROR;
	game->line_idx = 0;
	game->player = '\0';
	game->map.height = 0;
	game->map.width = 0;
	game->map.n_cnt = 0;
	game->map.map_array = NULL;
	game->map.is_n_continue = FALSE;
	game->move_speed = 0.05 + 1e-2;
	game->rot_speed = 0.20;
	game->map_fd = open(file, O_RDONLY, 0644);
	ft_bzero(game->buf, WINDOW_WIDTH * WINDOW_HEIGHT);
	game->texture = (int **)malloc(sizeof(int *) * 4);
	game->texture[0] = ft_calloc(TEX_HEIGHT * TEX_WIDTH, sizeof(int));
	game->texture[1] = ft_calloc(TEX_HEIGHT * TEX_WIDTH, sizeof(int));
	game->texture[2] = ft_calloc(TEX_HEIGHT * TEX_WIDTH, sizeof(int));
	game->texture[3] = ft_calloc(TEX_HEIGHT * TEX_WIDTH, sizeof(int));
}

void	init_camera_angle(t_game *game)
{
	if (game->player == 'W')
	{
		game->dir = vec_new(-1, 0);
		game->plane = vec_new(0, -0.66);
	}
	else if (game->player == 'E')
	{
		game->dir = vec_new(1, 0);
		game->plane = vec_new(0, 0.66);
	}
	else if (game->player == 'N')
	{
		game->dir = vec_new(0, -1);
		game->plane = vec_new(0.66, 0);
	}
	else if (game->player == 'S')
	{
		game->dir = vec_new(0, 1);
		game->plane = vec_new(-0.66, 0);
	}
}

static void	load_image(t_game *game, int *texture, char *path, t_img *img)
{
	int	x_t;
	int	x_d;
	int	y;

	y = 0;
	img->img = mlx_xpm_file_to_image(game->mlx, path, \
							&img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, \
						&img->bpp, &img->size_l, &img->endian);
	while (y < img->img_height)
	{
		x_t = 0;
		x_d = img->img_height -1;
		while (x_t < img->img_width)
		{
			texture[img->img_width * y + x_t] = \
				img->data[img->img_width * y + x_d];
			x_t += 1;
			x_d -= 1;
		}
		y += 1;
	}
	mlx_destroy_image(game->mlx, img->img);
}

// 텍스쳐를 경로에서 로드하는 함수
void	init_texture(t_game *game)
{
	t_img	img;

	load_image(game, game->texture[WALL_EA], game->wall.ea, &img);
	load_image(game, game->texture[WALL_WE], game->wall.we, &img);
	load_image(game, game->texture[WALL_SO], game->wall.so, &img);
	load_image(game, game->texture[WALL_NO], game->wall.no, &img);
}

void	init_mlx_setting(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
	game->img.img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	game->img.data = (int *)mlx_get_data_addr(game->img.img, &game->img.bpp, \
										&game->img.size_l, &game->img.endian);
}
