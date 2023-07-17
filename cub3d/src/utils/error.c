/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:19:49 by joonhan           #+#    #+#             */
/*   Updated: 2023/02/03 13:35:48 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include "cub3D.h"

void	print_error(char *msg, char *arg)
{
	ft_putstr_fd("Error\n❌ ", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	if (arg != NULL)
	{
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(arg, STDERR_FILENO);
	}
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	throw_error(char *msg, char *arg, t_game *game)
{
	print_error(msg, arg);
	if (game->map_fd != ERROR)
		close(game->map_fd);
	if (game->map.map_array != NULL)
		free_all(game->map.map_array);
	if (game->mlx != NULL && game->win != NULL)
		mlx_destroy_window(game->mlx, game->win);
	free_args(2, game->floor, game->ceiling);
	free_args(4, game->wall.no, game->wall.so, game->wall.ea, game->wall.we);
	free_args(5, game->texture[0], game->texture[1], game->texture[2], \
			game->texture[3], game->texture);
	exit(EXIT_FAILURE);
}
