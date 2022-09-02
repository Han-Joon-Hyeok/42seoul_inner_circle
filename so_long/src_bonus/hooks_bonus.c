/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:50:02 by joonhan           #+#    #+#             */
/*   Updated: 2022/09/03 00:31:02 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

int	exit_hook(t_game *game)
{
	mlx_destroy_image(game->mlx, game->sprites[0]);
	mlx_destroy_image(game->mlx, game->sprites[1]);
	mlx_destroy_image(game->mlx, game->sprites[2]);
	mlx_destroy_image(game->mlx, game->sprites[3]);
	mlx_destroy_image(game->mlx, game->collectible);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->land);
	mlx_destroy_image(game->mlx, game->door);
	mlx_destroy_window(game->mlx, game->win);
	free(game->map);
	free_all_enemy(game);
	free(game->collect_lst);
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

static int	is_collect(int key_code, t_game *game)
{
	t_collect_node	*curr;

	curr = game->collect_lst->head;
	while (curr != NULL)
	{
		if (game->player_idx + game->offset[key_code] == curr->idx)
			return (TRUE);
		curr = curr->next;
	}
	return (FALSE);
}

static void	process_move(int key_code, t_game *game)
{
	if (!is_object(key_code, game, '1'))
		return ;
	if (!is_object(key_code, game, 'C') || is_collect(key_code, game))
		free_collect(game, game->player_idx + game->offset[key_code]);
	if (!is_object(key_code, game, 'E') && \
		(game->collect_lst->count > 0))
		return ;
	else if (!is_object(key_code, game, 'E') && \
		(game->collect_lst->count == 0))
	{
		print_msg("🎁 Thanks for playing!");
		exit_hook(game);
	}
	else if (!is_object(key_code, game, 'F'))
		game_over_by_enemy(game);
	game->map[game->player_idx] = '0';
	game->player_idx += game->offset[key_code];
	game->map[game->player_idx] = 'P';
	game->moves += 1;
	printf("moves: %zd\n", game->moves);
}

int	key_release_hook(int key_code, t_game *game)
{
	if (key_code == KEY_W || key_code == KEY_A || \
		key_code == KEY_S || key_code == KEY_D)
		process_move(key_code, game);
	else if (key_code == KEY_ESC)
		exit_hook(game);
	return (0);
}
