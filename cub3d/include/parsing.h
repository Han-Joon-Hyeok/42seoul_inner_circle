/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:19:14 by joonhan           #+#    #+#             */
/*   Updated: 2023/02/03 13:19:15 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "libft.h"
# include "cub3D.h"

enum {
	KEY,
	VALUE
};

// map_info_utils.c
t_bool	is_valid_file_extension(char *str);
t_bool	is_file_openable(char *file);
int		get_count_of_kv_pair(char **kv_pair);

// check_map_info_validation.c
void	check_map_info_validation(t_game *game);

// process_line.c
int		process_line(char *line, t_game *game);

// save_floor_ceiling_info.c
void	save_floor_ceiling_info(t_info *line_info, t_game *game);

// check_map_validation.c
void	check_map_validation(t_game *game, char *file);

// is_valid_line.c
t_bool	is_valid_line(int map_fd);

// is_one_player.c
t_bool	is_one_player(int map_fd, t_game *game);

// save_map.c
void	get_width_and_height(t_game *game, int map_fd);
void	save_map(t_game *game, int map_fd);

// check_wall.c
t_bool	check_wall(int height_idx, int width_idx, t_game *game);

//parse_utils.c
int		open_file(char *file, int line_idx);

#endif
