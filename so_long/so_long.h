/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:46:52 by joonhan           #+#    #+#             */
/*   Updated: 2022/08/25 17:49:41 by joonhan          ###   ########.fr       */
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

# define WINDOW_WIDTH		128
# define WINDOW_HEIGHT		128

typedef struct s_pos
{
	int		x;
	int		y;
	size_t	moves;
}	t_pos;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

typedef struct s_game
{
	void	*land;
	void	*wall;
	void	*character;
	void	*collectible;
	void	*door;
	void	*fire;
	char	*map;
	size_t	width;
	size_t	height;
	size_t	map_size;
}	t_game;

void	print_error(char *msg);
void	is_valid_map(char *map_file, t_game *game);
void	init_pos(t_pos *pos);
void	init_mlx(t_mlx *mlx);
void	init_images(t_mlx *mlx, t_game *game);

#endif