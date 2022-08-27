/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:50:02 by joonhan           #+#    #+#             */
/*   Updated: 2022/08/27 15:02:37 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_hook(t_game *game)
{
	mlx_destroy_image(game->mlx, game->chr);
	mlx_destroy_image(game->mlx, game->collectible);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->land);
	mlx_destroy_image(game->mlx, game->fire);
	mlx_destroy_image(game->mlx, game->door);
	mlx_destroy_window(game->mlx, game->win);
	free(game->map);
	free(game->pos);
	print_msg("👋 Exit the game. So long!");
	// system("leaks so_long");
	exit(0);
}

static int	is_inside_wall(int key_code, t_game *game)
{
	if (key_code == KEY_W && game->map[game->player_idx - game->map_width] == '1')
		return (FALSE);
	else if (key_code == KEY_A && game->map[game->player_idx - 1] == '1')
		return (FALSE);
	else if (key_code == KEY_S && game->map[game->player_idx + game->map_width] == '1')
		return (FALSE);
	else if (key_code == KEY_D && game->map[game->player_idx + 1] == '1')
		return (FALSE);
	return (TRUE);
}

static void	key_release_hook(int key_code, t_game *game)
{
	if (!is_inside_wall(key_code, game))
		return ;
	game->map[game->player_idx] = '0';
	game->player_idx += game->offset[key_code];
	if (key_code == KEY_W)
		game->pos->y -= 1;
	else if (key_code == KEY_A)
		game->pos->x -= 1;
	else if (key_code == KEY_S)
		game->pos->y += 1;
	else if (key_code == KEY_D)
		game->pos->x += 1;
	game->map[game->player_idx] = 'P';
	game->pos->moves += 1;
	printf("x: %d, y: %d, moves: %zd\n", game->pos->x, game->pos->y, game->pos->moves);
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