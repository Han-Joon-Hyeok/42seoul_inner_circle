/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:18:17 by joonhan           #+#    #+#             */
/*   Updated: 2023/02/03 13:18:18 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "execute.h"

void	draw_background(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			game->buf[y][x] = game->floor->color;
			game->buf[WINDOW_HEIGHT - y - 1][x] = game->ceiling->color;
			x += 1;
		}
		y += 1;
	}
}

void	draw_wall(t_game *game, t_calc calc, int x)
{
	int				y;
	int				color;
	double			tex_pos;
	const double	step = 1.0 * TEX_HEIGHT / calc.line_height;

	y = calc.draw_start;
	tex_pos = \
		(calc.draw_start - WINDOW_HEIGHT / 2 + calc.line_height / 2) * step;
	while (y < calc.draw_end)
	{
		calc.tex.y = (int)tex_pos & (TEX_HEIGHT - 1);
		tex_pos += step;
		color = \
			game->texture[calc.tex_num][TEX_HEIGHT * calc.tex.y + calc.tex.x];
		game->buf[y][x] = color;
		y += 1;
	}
}

void	draw_floor_and_ceiling(t_game *game, t_calc calc, int x)
{
	int	y;

	if (calc.draw_end < 0)
		calc.draw_end = WINDOW_HEIGHT;
	y = calc.draw_end + 1;
	while (y < WINDOW_HEIGHT)
	{
		game->buf[y][x] = game->floor->color;
		game->buf[WINDOW_HEIGHT - y][x] = game->ceiling->color;
		y += 1;
	}
}

void	draw(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			game->img.data[y * WINDOW_WIDTH + x] = game->buf[y][x];
			x += 1;
		}
		y += 1;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}
