#include "so_long.h"

void	init_pos(t_pos *pos)
{
	pos->x = 0;
	pos->y = 0;
	pos->moves = 0;
}

int	key_press(int key_code, t_pos *pos)
{
	if (key_code == KEY_W)
		pos->y -= 1;
	else if (key_code == KEY_A)
		pos->x -= 1;
	else if (key_code == KEY_S)
		pos->y -= 1;
	else if (key_code == KEY_D)
		pos->x += 1;
	else if (key_code == KEY_ESC)
	{
		printf("✅ Exit the game. Bye👋!\n");
		exit(0);
	}
	if (key_code == KEY_W || key_code == KEY_A || key_code == KEY_S || key_code == KEY_D)
	{
		pos->moves += 1;
		printf("x: %d, y: %d, moves: %zd\n", pos->x, pos->y, pos->moves);
	}
	return (0);
}

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "so_long");
}

void	init_images(t_mlx *mlx, t_game *game)
{
	int	img_width;
	int	img_height;

	game->collectible = mlx_xpm_file_to_image(mlx->mlx_ptr, "./images/collectible.xpm", &img_width, &img_height);
	game->land = mlx_xpm_file_to_image(mlx->mlx_ptr, "./images/land.xpm", &img_width, &img_height);
	game->wall = mlx_xpm_file_to_image(mlx->mlx_ptr, "./images/wall.xpm", &img_width, &img_height);
	game->character = mlx_xpm_file_to_image(mlx->mlx_ptr, "./images/cat_1.xpm", &img_width, &img_height);
	game->door = mlx_xpm_file_to_image(mlx->mlx_ptr, "./images/door.xpm", &img_width, &img_height);
	game->fire = mlx_xpm_file_to_image(mlx->mlx_ptr, "./images/fire.xpm", &img_width, &img_height);
}

void	print_error(char *msg)
{
	printf("%s\n", msg);
	exit(1);
}

void	is_valid_map(char *map_file)
{
	/*
	1. 한 줄씩 읽는다.
	2. 각 줄마다 너비를 구한다.
	3. 에러 체크
		- 이전 줄의 너비와 다르면 에러 발생.
	4. 1줄로 이어붙인다.
	5. 첫 번째 줄이 모두 벽인지 확인한다.
	6. 2 ~ N-1 번째 줄 에러 체크
		- 0번째, 마지막이 벽인지 체크
	7. 마지막 줄이 모두 벽인지 확인한다.
	8. 출구, 전리품, 시작 위치가 존재하는 지 확인한다.
	9. 높이가 3 이상인지 확인한다.
	*/
	int		fd;
	char	*line;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		print_error("❌ ERROR: Opening map file failed.");
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
}

int	main(int argc, char *argv[])
{
	t_mlx	mlx;
	t_pos	pos;
	t_game	game;

	if (argc == 2)
	{
		is_valid_map(argv[1]);
		init_mlx(&mlx);
		init_pos(&pos);
		init_images(&mlx, &game);
		mlx_hook(mlx.win_ptr, X_EVENT_KEY_RELEASE, 0, &key_press, &pos);
		mlx_loop(mlx.mlx_ptr);
	}
	else
	{
		print_error("❌ ERROR: Invalid Number of Arguments. You should pass only one map file.");
	}
	return (0);
}