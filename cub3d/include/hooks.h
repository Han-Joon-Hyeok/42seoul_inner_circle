/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:19:06 by joonhan           #+#    #+#             */
/*   Updated: 2023/02/03 13:19:07 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

// hooks.c
int		exit_hook(t_game *game);
int		key_press(int key, t_game *game);

// handle_camera_rotation.c
void	handle_camera_rotation(int key, t_game *game);

// handle_player_move.c
void	handle_player_move(int key, t_game *game);

#endif
