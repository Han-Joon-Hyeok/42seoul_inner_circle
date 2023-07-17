/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:18:18 by joonhan           #+#    #+#             */
/*   Updated: 2023/02/03 13:18:19 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "utils.h"
#include "vector.h"
#include "execute.h"
#include <math.h>

t_vec	set_side_dist(t_calc *calc, t_vec pos)
{
	t_vec	side_dist;

	if (calc->ray_dir.x < 0)
	{
		calc->step.x = -1;
		side_dist.x = (pos.x - calc->map.x) * calc->delta_dist.x;
	}
	else
	{
		calc->step.x = 1;
		side_dist.x = (calc->map.x + 1.0 - pos.x) * calc->delta_dist.x;
	}
	if (calc->ray_dir.y < 0)
	{
		calc->step.y = -1;
		side_dist.y = (pos.y - calc->map.y) * calc->delta_dist.y;
	}
	else
	{
		calc->step.y = 1;
		side_dist.y = (calc->map.y + 1.0 - pos.y) * calc->delta_dist.y;
	}
	return (side_dist);
}

int	set_texture(t_calc calc)
{
	if (calc.side == 0)
	{
		if (calc.ray_dir.x > 0)
			return (WALL_EA);
		else
			return (WALL_WE);
	}
	else
	{
		if (calc.ray_dir.y > 0)
			return (WALL_SO);
		else
			return (WALL_NO);
	}
}

void	set_drawing_line(t_calc *calc)
{
	calc->line_height = (int)(WINDOW_HEIGHT / calc->perp_wall_dist);
	calc->draw_start = -(calc->line_height) / 2 + WINDOW_HEIGHT / 2;
	if (calc->draw_start < 0)
		calc->draw_start = 0;
	calc->draw_end = calc->line_height / 2 + WINDOW_HEIGHT / 2;
	if (calc->draw_end >= WINDOW_HEIGHT)
		calc->draw_end = WINDOW_HEIGHT - 1;
}

int	set_tex_x(t_calc calc, t_vec pos)
{
	int		tex_x;
	double	wall_x;

	if (calc.side == HORIZONTAL)
		wall_x = pos.y + calc.perp_wall_dist * calc.ray_dir.y;
	else
		wall_x = pos.x + calc.perp_wall_dist * calc.ray_dir.x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)TEX_WIDTH);
	if (calc.side == HORIZONTAL && calc.ray_dir.x > 0)
		tex_x = TEX_WIDTH - tex_x - 1;
	if (calc.side == VERTICAL && calc.ray_dir.y < 0)
		tex_x = TEX_WIDTH - tex_x - 1;
	return (tex_x);
}

void	calc(t_game *game)
{
	int		x;
	t_calc	calc;

	x = 0;
	draw_background(game);
	while (x < WINDOW_WIDTH)
	{
		calc.camera_x = 2 * x / (double)WINDOW_WIDTH - 1;
		calc.ray_dir = vec_add(game->dir, vec_mul(game->plane, calc.camera_x));
		calc.map = double_to_int(game->pos);
		calc.delta_dist = vec_new(fabs(1 / calc.ray_dir.x), \
									fabs(1 / calc.ray_dir.y));
		calc.side_dist = set_side_dist(&calc, game->pos);
		calc.perp_wall_dist = set_wall_dist(&calc, game, game->pos);
		set_drawing_line(&calc);
		calc.tex_num = set_texture(calc);
		calc.tex.x = set_tex_x(calc, game->pos);
		draw_wall(game, calc, x);
		draw_floor_and_ceiling(game, calc, x);
		x += 1;
	}
}
