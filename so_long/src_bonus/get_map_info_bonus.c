/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:08:24 by joonhan           #+#    #+#             */
/*   Updated: 2022/09/02 15:32:14 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

static void	get_player_idx(t_game *game)
{
	char	*current_player_idx;

	current_player_idx = ft_strchr(game->map, 'P');
	game->player_idx = current_player_idx - game->map;
}

static void	get_total_collect(t_game *game)
{
	size_t			idx;

	idx = 0;
	while (idx < game->map_size)
	{
		if (game->map[idx] == 'C')
			create_collect_node(game, idx);
		idx++;
	}
}

void	get_map_info(t_game *game)
{
	get_player_idx(game);
	get_total_collect(game);
	create_enemy(game);
}
