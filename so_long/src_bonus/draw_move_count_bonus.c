/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_moves_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:14:52 by joonhan           #+#    #+#             */
/*   Updated: 2022/09/02 15:15:44 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

void	draw_move_count(t_game *game)
{
	char	*moves;

	moves = ft_itoa((int)game->moves);
	ft_put_image_to_16(game, game->score, 0, 0);
	mlx_string_put(game->mlx, game->win, 2, 10, 0x000000, moves);
	free(moves);
}
