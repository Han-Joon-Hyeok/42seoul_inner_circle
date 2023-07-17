/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:19:05 by joonhan           #+#    #+#             */
/*   Updated: 2023/02/03 13:19:06 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "cub3D.h"
# include "vector.h"

enum	{
	HORIZONTAL,
	VERTICAL,
};

typedef struct s_calc {
	int		side;
	int		tex_num;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	camera_x;
	double	perp_wall_dist;
	t_pos	map;
	t_pos	step;
	t_pos	tex;
	t_vec	ray_dir;
	t_vec	delta_dist;
	t_vec	side_dist;
}	t_calc;

// calc.c
void	calc(t_game *game);

// draw.c
void	draw_background(t_game *game);
void	draw_wall(t_game *game, t_calc calc, int x);
void	draw_floor_and_ceiling(t_game *game, t_calc calc, int x);
void	draw(t_game *game);

// set_wall_dist.c
double	set_wall_dist(t_calc *calc, t_game *game, t_vec pos);

#endif
