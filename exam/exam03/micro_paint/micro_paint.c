#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define	ARGUMENT_ERROR			"Error: argument"
#define	OPERATION_FILE_ERROR	"Error: Operation file corrupted"

typedef enum e_bool{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_canvas{
	int		width;
	int		height;
	char	background;
}	t_canvas;

typedef struct s_line{
	char	r;
	double	x;
	double	y;
	double	width;
	double	height;
	char	c;
	struct s_line *next;
}	t_line;

size_t	ft_strlen(char *str)
{
	size_t	len;

	if (str == NULL)
		return (0);
	len = 0;
	while (str[len] != '\0')
		len += 1;
	return (len);
}

void	ft_putstr_fd(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

int	throw_error(char *str)
{
	ft_putstr_fd(str, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	return (EXIT_FAILURE);
}

t_bool	is_valid_first_line(FILE *pFile, t_canvas *canvas_info)
{
	int		count;

	count = fscanf(pFile, "%d %d %c\n", &canvas_info->width, &canvas_info->height, &canvas_info->background);
	if (count != 3)
		return (FALSE);
	if (canvas_info->width <= 0 || canvas_info->width > 300)
		return (FALSE);
	if (canvas_info->height <= 0 || canvas_info->height > 300)
		return (FALSE);
	return (TRUE);
}

void	lst_add_back(t_line **lst, t_line *new_node)
{
	t_line	*curr_node;

	if (*lst == NULL)
		*lst = new_node;
	else
	{
		curr_node = *lst;
		while (curr_node->next != NULL)
		{
			curr_node = curr_node->next;
		}
		curr_node->next = new_node;
	}
}

t_line	*lstnew(t_line line)
{
	t_line	*new_node;

	new_node = malloc(sizeof(t_line));
	new_node->r = line.r;
	new_node->height = line.height;
	new_node->width = line.width;
	new_node->x = line.x;
	new_node->y = line.y;
	new_node->c = line.c;
	return (new_node);
}

void	free_list(t_line *lines)
{
	t_line	*curr_node;
	t_line	*next_node;

	curr_node = lines;
	while (curr_node != NULL)
	{
		next_node = curr_node->next;
		free(curr_node);
		curr_node = next_node;
	}
}

t_bool	is_valid_lines(FILE *pFile, t_line **lines)
{
	int		count;
	t_line	line;

	while (pFile != NULL)
	{
		count = fscanf(pFile, "%c %lf %lf %lf %lf %c\n", &line.r, &line.x, &line.y, &line.width, &line.height, &line.c);
		if (count == -1)
			break ;
		if (count != 6)
			return (FALSE);
		if (line.width <= 0 || line.height <= 0)
			return (FALSE);
		if (line.r != 'r' && line.r != 'R')
			return (FALSE);
		lst_add_back(lines, lstnew(line));
	}
	return (TRUE);
}

t_bool	is_valid_file(char *file, t_canvas *canvas_info, t_line **lines)
{
	t_bool	result;
	FILE	*pFile;

	result = TRUE;
	pFile = fopen(file, "r");
	if (pFile == NULL)
		return (FALSE);
	if (is_valid_first_line(pFile, canvas_info) == FALSE)
		result = FALSE;
	if (is_valid_lines(pFile, lines) == FALSE)
	{
		free_list(*lines);
		result = FALSE;
	}
	fclose(pFile);
	return (result);
}

t_bool	is_in_rectangle(double pos_x, double pos_y, t_line *line)
{
	if (pos_x - line->x < (double)1 || (line->x + line->width) - pos_x < (double) 1 || \
		pos_y - line->y < (double)1 || (line->y + line->height) - pos_y < (double) 1)
		return (TRUE);
	return (FALSE);
}

void	draw_lines(char **canvas, t_canvas canvas_info, t_line *lines)
{
	t_line	*line;

	line = lines;
	while (line != NULL)
	{
		for (int pos_y = 0; pos_y < canvas_info.height; pos_y += 1)
		{
			for (int pos_x = 0; pos_x < canvas_info.width; pos_x += 1)
			{
				if (pos_x >= line->x && pos_x <= line->x + line->width && \
					pos_y >= line->y && pos_y <= line->y + line->height)
				{
					if (line->r == 'R' || (line->r == 'r' && is_in_rectangle(pos_x, pos_y, line)) == TRUE)
					{
						(*canvas)[pos_y * canvas_info.width + pos_x] = line->c;
					}
				}

			}
		}
		line = line->next;
	}
}

char	*draw_background(t_canvas canvas_info)
{
	int		area;
	char	*canvas;

	area = canvas_info.width * canvas_info.height;
	canvas = malloc(sizeof(char) * (area));
	memset(canvas, canvas_info.background, area);
	return (canvas);
}

void	print_canvas(char *canvas, t_canvas canvas_info)
{
	for (int pos_y = 0; pos_y < canvas_info.height; pos_y += 1)
	{
		write(STDOUT_FILENO, &canvas[pos_y * canvas_info.width], canvas_info.width);
		write(STDOUT_FILENO, "\n", 1);
	}
}

int	main(int argc, char **argv)
{
	char		*canvas;
	t_canvas	canvas_info;
	t_line		*lines;

	if (argc != 2)
		return (throw_error(ARGUMENT_ERROR));
	lines = NULL;
	if (is_valid_file(argv[1], &canvas_info, &lines) == FALSE)
		return (throw_error(OPERATION_FILE_ERROR));
	canvas = draw_background(canvas_info);
	draw_lines(&canvas, canvas_info, lines);
	print_canvas(canvas, canvas_info);
	free_list(lines);
	free(canvas);
	return (EXIT_SUCCESS);
}
