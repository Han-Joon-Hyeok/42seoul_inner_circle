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
}	t_game;

#endif