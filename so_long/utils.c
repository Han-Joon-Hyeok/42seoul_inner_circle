/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:23:28 by joonhan           #+#    #+#             */
/*   Updated: 2022/08/28 15:16:32 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_msg(char *msg)
{
	printf("%s\n", msg);
}

void	print_error(char *msg, void *game)
{
	printf("%s\n", msg);
	if (game != NULL)
	{
		close(((t_game *)game)->fd);
		free(((t_game *)game)->map);
	}
	exit(1);
}

void	ft_put_image_to_16(t_game *game, void *obj, size_t count, size_t height)
{
	mlx_put_image_to_window(game->mlx, game->win, obj, \
			count * IMAGE_WIDTH, height * IMAGE_HEIGHT);
}

void	ft_strjoin_without_newline(t_game *game, char *line, size_t width)
{
	char	*temp;
	char	*prev;

	prev = ft_strdup(game->map);
	if (line[width - 1] == '\n')
	{
		temp = malloc(sizeof(char) * (width));
		ft_strlcpy(temp, line, width);
		if (game->map == NULL)
			game->map = temp;
		else
		{
			free(game->map);
			game->map = ft_strjoin(prev, temp);
			free(temp);
		}
	}
	else
	{
		temp = ft_strjoin(prev, line);
		free(game->map);
		game->map = temp;
	}
	if (prev != NULL)
		free(prev);
}
