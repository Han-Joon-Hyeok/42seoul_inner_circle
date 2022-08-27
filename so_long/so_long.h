/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:46:52 by joonhan           #+#    #+#             */
/*   Updated: 2022/08/27 15:00:09 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# include "./mlx/mlx.h"
# include "./libft/libft.h"
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

typedef struct s_pos
{
	int		x;
	int		y;
	size_t	moves;
}	t_pos;

typedef struct s_game
{
	t_pos		*pos;
	ssize_t		offset[14];
	void		*mlx;
	void		*win;
	void		*land;
	void		*wall;
	void		*chr;
	void		*collectible;
	void		*door;
	void		*fire;
	char		*map;
	size_t		map_width;
	size_t		map_height;
	size_t		map_size;
	size_t		window_width;
	size_t		window_height;
	size_t		player_idx;
}	t_game;

void	print_msg(char *msg);
void	print_error(char *msg, void *game);
void	ft_strjoin_without_newline(t_game *game, char *line, size_t width);
void	save_map(char *map_file, t_game *game);
void	is_valid_map(t_game *game);
void	init_window_size(t_game *game);
void	init_pos(t_game *game);
void	init_mlx(t_game *game);
void	init_images(t_game *game);
void	draw_map(t_game *game);
int		main_loop_hook(int key_code, t_game *game);
int		exit_hook(t_game *game);

#endif