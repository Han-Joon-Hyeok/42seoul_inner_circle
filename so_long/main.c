/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:33:31 by joonhan           #+#    #+#             */
/*   Updated: 2022/08/28 21:13:52 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_setting(t_game *game)
{
	init_window_size(game);
	init_mlx(game);
	init_moves(game);
	init_images(game);
	init_offset(game);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		print_error("❌ ERROR: Enter ./so_long [map_file.ber]", NULL);
	save_map(argv[1], &game);
	is_valid_map(&game);
	get_map_info(&game);
	init_setting(&game);
	draw_map(&game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &exit_hook, &game);
	mlx_hook(game.win, X_EVENT_KEY_RELEASE, 0, &main_loop_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
