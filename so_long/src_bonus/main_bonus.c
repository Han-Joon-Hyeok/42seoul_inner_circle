/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:33:31 by joonhan           #+#    #+#             */
/*   Updated: 2022/09/02 17:18:05 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

static void	init_setting(t_game *game)
{
	init_window_size(game);
	init_mlx(game);
	init_images(game);
	init_offset(game);
	init_collect_lst(game);
	init_enemy(game);
	game->moves = 0;
	game->fps = 0;
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		print_error("❌ ERROR: Enter ./so_long [map_file.ber]", NULL);
	save_map(argv[1], &game);
	is_valid_map(&game);
	init_setting(&game);
	get_map_info(&game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &exit_hook, &game);
	mlx_hook(game.win, X_EVENT_KEY_RELEASE, 0, &key_release_hook, &game);
	mlx_loop_hook(game.mlx, &main_loop_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
