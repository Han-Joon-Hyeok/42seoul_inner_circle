/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:19:16 by joonhan           #+#    #+#             */
/*   Updated: 2023/02/03 13:19:17 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub3D.h"

# define INVALID_ARGUMENT		"[Usage]: ./cub3D [map_file.cub]"
# define INVALID_FILE_EXTENSION	"File format should be [*.cub]"
# define INVALID_IMG_EXTENSION	"File format should be [*.xpm]"
# define NOT_OPENABLE_FILE		"File does not exist or cannot be opened"
# define NOT_ENOUGH_MAP_INFO	"Map information is not enough"
# define DUPLICATED_MAP_INFO	"Map information need to be only one"
# define INVALID_IDENTIFIER		"Identifier should be [NO/SO/WE/EA] or [F/C]"
# define INVALID_WALL_IMAGE		"Wall image should be [file.xpm]"
# define INVALID_MAP_INFO		"The count of map information should be 6"
# define INVALID_RGB_FORMAT		"RGB should be '[R],[G],[B]' format"
# define INVALID_RGB_VALUE		"RGB should be between 0 and 255"

// error.c
void	print_error(char *msg, char *arg);
void	throw_error(char *msg, char *arg, t_game *game);

// free.c
t_bool	free_and_return_false(void *arg);
void	free_args(int count, ...);

#endif
