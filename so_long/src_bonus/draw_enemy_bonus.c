/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 17:17:20 by joonhan           #+#    #+#             */
/*   Updated: 2022/09/02 17:30:52 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

static void	move_enemy(t_game *game, t_enemy_node *curr, int direction)
{
	if (game->fps % 100 != 0)
		return ;
	if (curr->prev == NULL || curr->idx != curr->prev->idx)
		game->map[curr->idx] = '0';
	game->map[curr->idx + direction] = 'F';
	curr->idx += direction;
	curr->next_dir = -direction;
}

static void	game_over_by_enemy(t_game *game)
{
	print_msg("👻 You lose the game. Try again!");
	exit_hook(game);
}

void	draw_enemy(t_game *game)
{
	t_enemy_node	*curr;

	curr = game->enemy_lst->head;
	while (curr != NULL)
	{
		if (curr->idx == game->player_idx)
			game_over_by_enemy(game);
		if (curr->next_dir == -1)
		{
			if (game->map[curr->idx + curr->next_dir] == '1')
				move_enemy(game, curr, 1);
			else
				move_enemy(game, curr, -1);
		}
		else if (curr->next_dir == 1)
		{
			if (game->map[curr->idx + curr->next_dir] == '1')
				move_enemy(game, curr, -1);
			else
				move_enemy(game, curr, 1);
		}
		curr = curr->next;
	}
}
