/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:46:52 by joonhan           #+#    #+#             */
/*   Updated: 2022/09/01 17:45:30 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <string.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_ESC	53

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17

# define WINDOW_WIDTH		500
# define WINDOW_HEIGHT		500

# define IMAGE_WIDTH		16
# define IMAGE_HEIGHT		16

typedef struct s_enemy_node
{
	size_t				idx;
	struct s_enemy_node	*next;
}	t_enemy_node;

typedef struct s_enemy
{
	size_t			*count;
	t_enemy_node	*head;
	t_enemy_node	*tail;
}	t_enemy;

typedef struct s_game
{
	size_t		moves;
	ssize_t		offset[14];
	void		*mlx;
	void		*win;
	void		*land;
	void		*wall;
	void		*chr;
	void		*collectible;
	void		*door;
	void		*score;
	void		*enemy;
	char		*map;
	int			enemy_move;
	size_t		map_width;
	size_t		map_height;
	size_t		map_size;
	size_t		window_width;
	size_t		window_height;
	size_t		player_idx;
	size_t		total_collect_count;
	size_t		curr_collect_count;
	t_enemy		*enemy_component;
	int			fd;
}	t_game;

void	print_msg(char *msg);
void	print_error(char *msg, void *game);
void	ft_put_image_to_16(t_game *game, void *obj, \
								size_t count, size_t height);

void	save_map(char *map_file, t_game *game);
void	is_valid_map(t_game *game);
void	get_map_info(t_game *game);

void	init_window_size(t_game *game);
void	init_moves(t_game *game);
void	init_mlx(t_game *game);
void	init_images(t_game *game);
void	init_offset(t_game *game);

void	init_enemy(t_game *game);

void	draw_map(t_game *game);
void	draw_moves(t_game *game);
int		main_loop_hook(int key_code, t_game *game);
int		exit_hook(t_game *game);

#endif