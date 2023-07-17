/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_wall_dist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:18:17 by joonhan           #+#    #+#             */
/*   Updated: 2023/02/03 13:18:18 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "execute.h"
#include "vector.h"

static t_bool	is_out_of_map(t_calc *calc, t_game *game)
{
	if (calc->map.y < 0)
		return (TRUE);
	if (calc->map.y > game->map.height - 1)
		return (TRUE);
	if (calc->map.x < 0)
		return (TRUE);
	if (calc->map.x > game->map.width)
		return (TRUE);
	return (FALSE);
}

static t_bool	is_wall_hit(t_calc *calc, t_game *game)
{
	t_bool	is_hit_wall;

	is_hit_wall = FALSE;
	while (is_hit_wall == FALSE)
	{
		if (calc->side_dist.x < calc->side_dist.y)
		{
			calc->side_dist.x += calc->delta_dist.x;
			calc->map.x += calc->step.x;
			calc->side = HORIZONTAL;
		}
		else
		{
			calc->side_dist.y += calc->delta_dist.y;
			calc->map.y += calc->step.y;
			calc->side = VERTICAL;
		}
		if (is_out_of_map(calc, game) == TRUE)
			return (FALSE);
		if (game->map.map_array[calc->map.y][calc->map.x] == '1')
			is_hit_wall = TRUE;
	}
	return (TRUE);
}

double	set_wall_dist(t_calc *calc, t_game *game, t_vec pos)
{
	if (is_wall_hit(calc, game) == FALSE)
		return (0);
	else if (calc->side == HORIZONTAL)
		return ((calc->map.x - pos.x + (1 - calc->step.x) / 2) / \
				calc->ray_dir.x);
	else
		return ((calc->map.y - pos.y + (1 - calc->step.y) / 2) / \
				calc->ray_dir.y);
}
