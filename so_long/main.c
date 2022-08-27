/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:33:31 by joonhan           #+#    #+#             */
/*   Updated: 2022/08/27 15:01:10 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_idx(t_game *game)
{
	char	*current_player_idx;

	current_player_idx = ft_strchr(game->map, 'P');
	game->player_idx = current_player_idx - game->map;
}

void	init_offset(t_game *game)
{
	game->offset[KEY_W] = -((ssize_t)game->map_width);
	game->offset[KEY_A] = -1;
	game->offset[KEY_S] = ((ssize_t)game->map_width);
	game->offset[KEY_D] = 1;
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		print_error("❌ ERROR: Enter ./so_long [map_file.ber]", NULL);
	save_map(argv[1], &game);
	is_valid_map(&game);
	init_window_size(&game);
	init_mlx(&game);
	init_pos(&game);
	init_images(&game);
	init_offset(&game);
	draw_map(&game);
	get_player_idx(&game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &exit_hook, &game);
	mlx_hook(game.win, X_EVENT_KEY_RELEASE, 0, &main_loop_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
