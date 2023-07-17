/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:19:08 by joonhan           #+#    #+#             */
/*   Updated: 2023/02/03 13:19:09 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "cub3D.h"

// init.c
void	init_game(t_game *game, char *file);
void	init_camera_angle(t_game *game);
void	init_texture(t_game *game);
void	init_mlx_setting(t_game *game);

#endif
