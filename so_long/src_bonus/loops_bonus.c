/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:50:02 by joonhan           #+#    #+#             */
/*   Updated: 2022/09/03 00:29:29 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

int	main_loop(t_game *game)
{
	draw_map(game);
	draw_collect(game);
	draw_enemy(game);
	draw_move_count(game);
	count_fps(game);
	return (0);
}
