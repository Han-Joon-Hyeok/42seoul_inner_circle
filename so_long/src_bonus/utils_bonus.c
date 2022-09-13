/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:23:28 by joonhan           #+#    #+#             */
/*   Updated: 2022/09/02 17:33:26 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

void	print_msg(char *msg)
{
	printf("%s\n", msg);
}

void	print_error(char *msg, void *game)
{
	perror(msg);
	if (game != NULL)
	{
		close(((t_game *)game)->fd);
		free(((t_game *)game)->map);
	}
	exit(1);
}

void	ft_put_image_to_16(t_game *game, void *obj, \
								size_t count, size_t height)
{
	mlx_put_image_to_window(game->mlx, game->win, obj, \
			count * IMAGE_WIDTH, height * IMAGE_HEIGHT);
}

void	count_fps(t_game *game)
{
	game->fps += 1;
	if (game->fps >= 100)
		game->fps = 0;
}

void	game_over_by_enemy(t_game *game)
{
	print_msg("👻 You lose the game. Try again!");
	exit_hook(game);
}
