/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:23:28 by joonhan           #+#    #+#             */
/*   Updated: 2022/08/27 11:51:10 by joonhan          ###   ########.fr       */
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
	// free 추가하기
	if (game != NULL)
		free(((t_game *)game)->map);
	exit(1);
}

void	ft_strjoin_without_newline(t_game *game, char *line, size_t width)
{
	char	*temp;
	char	*save;
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
			save = ft_strjoin(prev, temp);
			free(game->map);
			free(temp);
			game->map = save;
		}
	}
	else
	{
		save = ft_strjoin(prev, line);
		free(game->map);
		game->map = save;
	}
	if (prev != NULL)
		free(prev);
}
