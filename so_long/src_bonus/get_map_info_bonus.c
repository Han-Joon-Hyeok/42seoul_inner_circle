/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:08:24 by joonhan           #+#    #+#             */
/*   Updated: 2022/09/01 17:40:46 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

static void	get_total_collect_count(t_game *game)
{
	size_t	count;
	size_t	idx;

	count = 0;
	idx = 0;
	while (idx < game->map_size)
	{
		if (game->map[idx] == 'C')
			count++;
		idx++;
	}
	game->total_collect_count = count;
	game->curr_collect_count = 0;
}

static void	get_player_idx(t_game *game)
{
	char	*current_player_idx;

	current_player_idx = ft_strchr(game->map, 'P');
	game->player_idx = current_player_idx - game->map;
}

static void	get_enemy_idx(t_game *game)
{
	char			*current_enemy_addr;
	t_enemy_node	*new_enemy;

	current_enemy_addr = ft_strchr(game->map, 'F');
	while (current_enemy_addr)
	{
		new_enemy = malloc(sizeof(t_enemy_node));
		if (new_enemy == NULL)
			return ;
		new_enemy->idx = current_enemy_addr - game->map;
		new_enemy->next = NULL;
		if (game->enemy_component->count == 0)
		{
			game->enemy_component->head = new_enemy;
			game->enemy_component->tail = new_enemy;
		}
		else
		{
			game->enemy_component->tail->next = new_enemy;
			game->enemy_component->tail = new_enemy;
		}
		game->enemy_component->count += 1;
		current_enemy_addr = ft_strchr(current_enemy_addr + 1, 'F');
	}
}

void	get_map_info(t_game *game)
{
	get_player_idx(game);
	get_total_collect_count(game);
	get_enemy_idx(game);
}
