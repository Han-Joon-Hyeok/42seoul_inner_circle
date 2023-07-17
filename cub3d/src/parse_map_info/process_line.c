/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:18:03 by joonhan           #+#    #+#             */
/*   Updated: 2023/02/03 13:18:04 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "utils.h"

static char	*strjoin_values(char *key, char *line, t_info_type type, \
							t_game *game)
{
	char	*start;
	char	*buffer;
	char	**argv;

	start = ft_strnstr(line, key, ft_strlen(line));
	if (type == FLOOR_OR_CEILING)
		start += 1;
	else
		start += 2;
	buffer = ft_strtrim(start, " ");
	if (type == FLOOR_OR_CEILING)
	{
		argv = ft_split(buffer, ',');
		if (get_count_of_kv_pair(argv) != 3)
			throw_error(INVALID_RGB_FORMAT, line, game);
	}
	else
	{
		argv = ft_split(buffer, ' ');
		if (get_count_of_kv_pair(argv) != 1)
			throw_error(INVALID_WALL_IMAGE, line, game);
	}
	free_all(argv);
	return (buffer);
}

static void	filter_info_type(t_info *line_info, char **kv_pair, t_game *game)
{
	if (ft_strcmp(kv_pair[KEY], "F") == 0 || \
		ft_strcmp(kv_pair[KEY], "C") == 0)
		line_info->type = FLOOR_OR_CEILING;
	else if (ft_strcmp(kv_pair[KEY], "NO") == 0)
		line_info->type = NO;
	else if (ft_strcmp(kv_pair[KEY], "SO") == 0)
		line_info->type = SO;
	else if (ft_strcmp(kv_pair[KEY], "WE") == 0)
		line_info->type = WE;
	else if (ft_strcmp(kv_pair[KEY], "EA") == 0)
		line_info->type = EA;
	else
		throw_error(INVALID_IDENTIFIER, kv_pair[KEY], game);
}

static t_info	*get_line_info(char *line, t_game *game)
{
	t_info	*line_info;
	char	*trimmed_line;
	char	**kv_pair;

	trimmed_line = ft_strtrim(line, " \n");
	kv_pair = ft_split(trimmed_line, ' ');
	line_info = malloc(sizeof(t_info));
	filter_info_type(line_info, kv_pair, game);
	line_info->key = ft_strdup(kv_pair[KEY]);
	if (get_count_of_kv_pair(kv_pair) != 2)
		line_info->value = strjoin_values(kv_pair[KEY], \
										trimmed_line, line_info->type, game);
	else
		line_info->value = ft_strdup(kv_pair[VALUE]);
	free(trimmed_line);
	free_all(kv_pair);
	return (line_info);
}

static void	save_wall_info(t_info *line_info, t_game *game)
{
	char	*trimmed_line;

	trimmed_line = ft_strtrim(line_info->value, " \n");
	if (ft_strcmp(trimmed_line + (ft_strlen(trimmed_line) - 4), ".xpm") != 0)
		throw_error(INVALID_IMG_EXTENSION, trimmed_line, game);
	if (is_file_openable(trimmed_line) == FALSE)
		throw_error(NOT_OPENABLE_FILE, trimmed_line, game);
	if (line_info->type == SO && game->wall.so == NULL)
		game->wall.so = trimmed_line;
	else if (line_info->type == WE && game->wall.we == NULL)
		game->wall.we = trimmed_line;
	else if (line_info->type == NO && game->wall.no == NULL)
		game->wall.no = trimmed_line;
	else if (line_info->type == EA && game->wall.ea == NULL)
		game->wall.ea = trimmed_line;
	else
		throw_error(DUPLICATED_MAP_INFO, trimmed_line, game);
}

int	process_line(char *line, t_game *game)
{
	t_info	*line_info;

	line_info = get_line_info(line, game);
	if (line_info != NULL)
	{
		if (line_info->type == FLOOR_OR_CEILING)
			save_floor_ceiling_info(line_info, game);
		else
			save_wall_info(line_info, game);
		free_args(3, line_info->key, line_info->value, line_info);
	}
	return (1);
}
