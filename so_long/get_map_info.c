/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:08:24 by joonhan           #+#    #+#             */
/*   Updated: 2022/08/28 21:38:42 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	get_map_info(t_game *game)
{
	get_player_idx(game);
	get_total_collect_count(game);
}
