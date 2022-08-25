/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:33:31 by joonhan           #+#    #+#             */
/*   Updated: 2022/08/25 20:55:23 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int key_code, t_pos *pos)
{
	if (key_code == KEY_W)
		pos->y -= 1;
	else if (key_code == KEY_A)
		pos->x -= 1;
	else if (key_code == KEY_S)
		pos->y += 1;
	else if (key_code == KEY_D)
		pos->x += 1;
	else if (key_code == KEY_ESC)
	{
		printf("✅ Exit the game. Bye! 👋 \n");
		exit(0);
	}
	if (key_code == KEY_W || key_code == KEY_A || \
		key_code == KEY_S || key_code == KEY_D)
	{
		pos->moves += 1;
		printf("x: %d, y: %d, moves: %zd\n", pos->x, pos->y, pos->moves);
	}
	return (0);
}

// void	draw_map(t_mlx *mlx, t_game *game, t_pos *pos)
// {
	
// }

int	main(int argc, char *argv[])
{
	t_mlx	mlx;
	t_pos	pos;
	t_game	game;

	if (argc == 2)
	{
		is_valid_map(argv[1], &game);
		init_mlx(&mlx);
		init_pos(&pos);
		init_images(&mlx, &game);
		// draw_map(&mlx, &game, &pos);
		mlx_hook(mlx.win_ptr, X_EVENT_KEY_RELEASE, 0, &key_press, &pos);
		mlx_loop(mlx.mlx_ptr);
	}
	else
	{
		print_error("❌ ERROR: Invalid Number of Arguments.");
	}
	return (0);
}
