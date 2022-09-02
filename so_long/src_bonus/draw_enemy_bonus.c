/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 17:17:20 by joonhan           #+#    #+#             */
/*   Updated: 2022/09/02 22:21:25 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

static int	is_movable(t_game *game, t_enemy_node *curr)
{
	if (game->map[curr->idx + curr->next_dir] == '1')
		return (FALSE);
	if (game->map[curr->idx + curr->next_dir] == 'E')
		return (FALSE);
	if (game->map[curr->idx + curr->next_dir] == 'F')
		return (FALSE);
	return (TRUE);
}

static void	move_enemy(t_game *game, t_enemy_node *curr, int direction)
{
	if (game->fps % 100 != 0)
		return ;
	if (curr->prev == NULL || curr->idx != curr->prev->idx)
		game->map[curr->idx] = '0';
	game->map[curr->idx + direction] = 'F';
	curr->idx += direction;
	curr->next_dir = -curr->next_dir;
}

void	draw_enemy(t_game *game)
{
	t_enemy_node	*curr;

	curr = game->enemy_lst->head;
	while (curr != NULL)
	{
		if (curr->idx == game->player_idx)
			game_over_by_enemy(game);
		if (curr->next_dir == LEFT)
		{
			if (is_movable(game, curr) == FALSE)
				move_enemy(game, curr, RIGHT);
			else
				move_enemy(game, curr, LEFT);
		}
		else if (curr->next_dir == RIGHT)
		{
			if (is_movable(game, curr) == FALSE)
				move_enemy(game, curr, LEFT);
			else
				move_enemy(game, curr, RIGHT);
		}
		curr = curr->next;
	}
}
