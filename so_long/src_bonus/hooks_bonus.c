/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:50:02 by joonhan           #+#    #+#             */
/*   Updated: 2022/09/02 13:06:28 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

int	exit_hook(t_game *game)
{
	mlx_destroy_image(game->mlx, game->chr);
	mlx_destroy_image(game->mlx, game->collectible);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->land);
	mlx_destroy_image(game->mlx, game->door);
	mlx_destroy_window(game->mlx, game->win);
	free(game->map);
	free_all_enemy(game);
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

static void	process_move(int key_code, t_game *game)
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
		print_msg("🎁 Thanks for playing!");
		exit_hook(game);
	}
	else if (!is_object(key_code, game, 'F'))
	{
		print_msg("👻 You lose the game. Try again!");
		exit_hook(game);
	}
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

void	move_enemy(t_game *game, t_enemy_node *curr, int direction)
{
	game->map[curr->idx] = '0';
	game->map[curr->idx + direction] = 'F';
	curr->idx += direction;
	curr->next_dir = -direction;
}

void	draw_enemy(t_game *game)
{
	t_enemy_node	*curr;

	if (game->fps % 100 == 0)
	{
		curr = game->enemy_component->head;
		while (curr != NULL)
		{
			if (curr->next_dir == -1 && \
				game->map[curr->idx + curr->next_dir] != '1')
				move_enemy(game, curr, -1);
			else if (curr->next_dir == 1 && \
				game->map[curr->idx + curr->next_dir] != '1')
				move_enemy(game, curr, 1);
			curr = curr->next;
		}
	}
}

void	count_fps(t_game *game)
{
	game->fps += 1;
	if (game->fps >= 100)
		game->fps = 0;
}

int	main_loop_hook(t_game *game)
{
	draw_map(game);
	draw_enemy(game);
	draw_moves(game);
	count_fps(game);
	return (0);
}
