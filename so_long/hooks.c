/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:50:02 by joonhan           #+#    #+#             */
/*   Updated: 2022/08/28 15:44:49 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_hook(t_game *game)
{
	mlx_destroy_image(game->mlx, game->chr);
	mlx_destroy_image(game->mlx, game->collectible);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->land);
	mlx_destroy_image(game->mlx, game->door);
	mlx_destroy_window(game->mlx, game->win);
	free(game->map);
	close(game->fd);
	print_msg("👋 Exit the game. So long!");
	exit(0);
}

static int	is_object(int key_code, t_game *game, char object)
{
	if (key_code == KEY_W && \
		game->map[game->player_idx - game->map_width] == object)
		return (FALSE);
	else if (key_code == KEY_A && \
		game->map[game->player_idx - 1] == object)
		return (FALSE);
	else if (key_code == KEY_S && \
		game->map[game->player_idx + game->map_width] == object)
		return (FALSE);
	else if (key_code == KEY_D && \
		game->map[game->player_idx + 1] == object)
		return (FALSE);
	return (TRUE);
}

static void	key_release_hook(int key_code, t_game *game)
{
	if (!is_object(key_code, game, '1'))
		return ;
	if (!is_object(key_code, game, 'C'))
		game->curr_collect_count += 1;
	if (!is_object(key_code, game, 'E') && \
		(game->curr_collect_count < game->total_collect_count))
		return ;
	else if (!is_object(key_code, game, 'E') && \
		(game->curr_collect_count == game->total_collect_count))
	{
		print_msg("👍 Good job");
		exit_hook(game);
	}
	game->map[game->player_idx] = '0';
	game->player_idx += game->offset[key_code];
	game->map[game->player_idx] = 'P';
	game->moves += 1;
	printf("moves: %zd\n", game->moves);
	draw_map(game);
}

int	main_loop_hook(int key_code, t_game *game)
{
	if (key_code == KEY_W || key_code == KEY_A || \
		key_code == KEY_S || key_code == KEY_D)
		key_release_hook(key_code, game);
	else if (key_code == KEY_ESC)
		exit_hook(game);
	return (0);
}
