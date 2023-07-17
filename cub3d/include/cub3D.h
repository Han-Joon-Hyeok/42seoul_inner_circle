/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:19:03 by joonhan           #+#    #+#             */
/*   Updated: 2023/02/03 13:19:04 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "libft.h"
# include "vector.h"

# define WINDOW_WIDTH	640
# define WINDOW_HEIGHT	640

# define TEX_WIDTH	64
# define TEX_HEIGHT	64

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17

enum {
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_ESC = 53,
	KEY_LEFT = 123,
	KEY_RIGHT = 124
};

enum {
	WALL_EA,
	WALL_WE,
	WALL_SO,
	WALL_NO
};

typedef enum e_info_type {
	NO,
	SO,
	WE,
	EA,
	FLOOR_OR_CEILING
}	t_info_type;

typedef struct s_rgb {
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	int				color;
}	t_rgb;

typedef struct s_wall {
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
}	t_wall;

typedef struct s_info {
	t_info_type	type;
	char		*key;
	char		*value;
}	t_info;

typedef struct s_map {
	char		**map_array;
	int			width;
	int			height;
	int			n_cnt;
	t_bool		is_n_continue;
}	t_map;

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}	t_img;

typedef struct s_game {
	int		map_fd;
	int		line_idx;
	t_wall	wall;
	t_rgb	*floor;
	t_rgb	*ceiling;
	t_map	map;
	char	player;
	void	*mlx;
	void	*win;
	t_vec	pos;
	t_vec	dir;
	t_vec	plane;
	double	move_speed;
	double	rot_speed;
	t_img	img;
	int		buf[WINDOW_HEIGHT][WINDOW_WIDTH];
	int		**texture;
	int		re_buf;
}	t_game;

void	main_loop(t_game *game);

#endif
