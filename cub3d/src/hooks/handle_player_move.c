/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:18:14 by joonhan           #+#    #+#             */
/*   Updated: 2023/02/03 13:18:15 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "vector.h"

static void	key_w_move(t_game *game, t_pos pos, t_vec new_dir)
{
	if (game->map.map_array[pos.y][(int)(game->pos.x + new_dir.x)] != '1')
		game->pos.x += new_dir.x;
	if (game->map.map_array[(int)(game->pos.y + new_dir.y)][pos.x] != '1')
		game->pos.y += new_dir.y;
}

static void	key_s_move(t_game *game, t_pos pos, t_vec new_dir)
{
	if (game->map.map_array[pos.y][(int)(game->pos.x - new_dir.x)] != '1')
		game->pos.x -= new_dir.x;
	if (game->map.map_array[(int)(game->pos.y - new_dir.y)][pos.x] != '1')
		game->pos.y -= new_dir.y;
}

static void	key_d_move(t_game *game, t_pos pos, t_vec new_dir)
{
	if (game->map.map_array[pos.y][(int)(game->pos.x - new_dir.y)] != '1')
		game->pos.x -= new_dir.y;
	if (game->map.map_array[(int)(game->pos.y + new_dir.x)][pos.x] != '1')
		game->pos.y += new_dir.x;
}

static void	key_a_move(t_game *game, t_pos pos, t_vec new_dir)
{
	if (game->map.map_array[pos.y][(int)(game->pos.x + new_dir.y)] != '1')
		game->pos.x += new_dir.y;
	if (game->map.map_array[(int)(game->pos.y - new_dir.x)][pos.x] != '1')
		game->pos.y -= new_dir.x;
}

void	handle_player_move(int key, t_game *game)
{
	t_pos	pos;
	t_vec	new_dir;

	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
	{
		pos = double_to_int(game->pos);
		new_dir = vec_mul(game->dir, game->move_speed);
		if (key == KEY_W)
			key_w_move(game, pos, new_dir);
		else if (key == KEY_S)
			key_s_move(game, pos, new_dir);
		else if (key == KEY_A)
			key_a_move(game, pos, new_dir);
		else if (key == KEY_D)
			key_d_move(game, pos, new_dir);
	}
}
