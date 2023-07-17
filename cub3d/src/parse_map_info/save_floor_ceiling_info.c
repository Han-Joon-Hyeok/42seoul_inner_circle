/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_floor_ceiling_info.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:18:01 by joonhan           #+#    #+#             */
/*   Updated: 2023/02/03 13:18:02 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include "parsing.h"

static t_bool	is_valid_separator_count(char *line)
{
	int		idx;
	int		count;
	char	*trimmed_line;

	idx = 0;
	count = 0;
	trimmed_line = ft_strtrim(line, " \n");
	while (trimmed_line[idx] != '\0')
	{
		if (trimmed_line[idx] == ',')
			count += 1;
		idx += 1;
	}
	free(trimmed_line);
	if (count == 2)
		return (TRUE);
	return (FALSE);
}

static void	check_space_in_value(char *value, t_game *game)
{
	char	**value_split;

	value_split = ft_split(value, ' ');
	if (get_count_of_kv_pair(value_split) != 1)
		throw_error(INVALID_RGB_FORMAT, value, game);
	free_all(value_split);
}

static t_bool	is_valid_rgb_value(char **values, t_game *game)
{
	int		idx;
	int		value_idx;
	int		result;
	char	*value;

	idx = 0;
	while (values[idx] != NULL)
	{
		value = ft_strtrim(values[idx], " ");
		check_space_in_value(value, game);
		value_idx = 0;
		while (value[value_idx] != '\0')
		{
			if (ft_isdigit(value[value_idx]) == FALSE)
				return (free_and_return_false(value));
			value_idx += 1;
		}
		result = ft_atoi(values[idx]);
		if (result < 0 || result > 255)
			return (free_and_return_false(value));
		idx += 1;
		free(value);
	}
	return (TRUE);
}

static unsigned char	save_rgb_value(char *line)
{
	int		result;
	char	*trimmed_line;

	trimmed_line = ft_strtrim(line, " ");
	result = ft_atoi(trimmed_line);
	free(trimmed_line);
	return ((unsigned char)result);
}

void	save_floor_ceiling_info(t_info *line_info, t_game *game)
{
	t_rgb	*rgb;
	char	**values;

	if (is_valid_separator_count(line_info->value) == FALSE)
		throw_error(INVALID_RGB_FORMAT, line_info->value, game);
	values = ft_split(line_info->value, ',');
	if (get_count_of_kv_pair(values) != 3)
		throw_error(INVALID_RGB_FORMAT, line_info->value, game);
	if (is_valid_rgb_value(values, game) == FALSE)
		throw_error(INVALID_RGB_VALUE, line_info->value, game);
	if (ft_strcmp(line_info->key, "F") == 0 && game->floor != NULL)
		throw_error(DUPLICATED_MAP_INFO, line_info->key, game);
	if (ft_strcmp(line_info->key, "C") == 0 && game->ceiling != NULL)
		throw_error(DUPLICATED_MAP_INFO, line_info->key, game);
	rgb = malloc(sizeof(t_rgb));
	rgb->r = save_rgb_value(values[0]);
	rgb->g = save_rgb_value(values[1]);
	rgb->b = save_rgb_value(values[2]);
	rgb->color = (rgb->r << 16) | (rgb->g << 8) | rgb->b;
	if (ft_strcmp(line_info->key, "F") == 0)
		game->floor = rgb;
	else if (ft_strcmp(line_info->key, "C") == 0)
		game->ceiling = rgb;
	free_all(values);
}
