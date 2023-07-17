/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:17:54 by joonhan           #+#    #+#             */
/*   Updated: 2023/02/03 13:17:55 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "utils.h"
#include "parsing.h"
#include "hooks.h"
#include "execute.h"
#include "vector.h"

void	main_loop(t_game *game)
{
	calc(game);
	draw(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	init_game(&game, argv[1]);
	if (argc != 2)
		throw_error(INVALID_ARGUMENT, NULL, &game);
	if (is_valid_file_extension(argv[1]) == FALSE)
		throw_error(INVALID_FILE_EXTENSION, argv[1], &game);
	if (is_file_openable(argv[1]) == FALSE)
		throw_error(NOT_OPENABLE_FILE, argv[1], &game);
	check_map_info_validation(&game);
	check_map_validation(&game, argv[1]);
	init_mlx_setting(&game);
	init_camera_angle(&game);
	init_texture(&game);
	main_loop(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &exit_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
