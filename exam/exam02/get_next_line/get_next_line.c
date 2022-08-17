#include "get_next_line.h"

static t_lst	*init_lst(void)
{
	t_lst	*lst;

	lst = malloc(sizeof(t_lst));
	lst->len = 0;
	lst->head = NULL;
	lst->tail = NULL;
	lst->exist_newline = 0;
	return (lst);
}

static void	save_in_backup(t_lst *lst, char c)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->c = c;
	node->next = NULL;
	if (lst->head == NULL)
	{
		lst->head = node;
		lst->tail = node;
	}
	else
	{
		lst->tail->next = node;
		lst->tail = node;
	}
	if (c == '\n')
	{
		lst->exist_newline = 1;
	}
	lst->len += 1;
}

static char	*print_newline(t_lst *lst)
{
	int		idx;
	char	*newline;
	t_node	*curr;
	t_node	*next;

	idx = 0;
	newline = malloc(sizeof(char) * (lst->len + 1));
	curr = lst->head;
	while (curr != NULL)
	{
		next = curr->next;
		newline[idx] = curr->c;
		free(curr);
		curr = next;
		idx += 1;
		lst->len -= 1;
	}
	newline[idx] = '\0';
	return (newline);
}

char	*get_next_line(int fd)
{
	t_lst	*lst;
	char	buf[1];
	char	*newline;
	ssize_t	read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	lst = init_lst();
	read_bytes = read(fd, buf, 1);
	while (read_bytes > 0)
	{
		save_in_backup(lst, buf[0]);
		if (lst->exist_newline)
		{
			newline = print_newline(lst);
			free(lst);
			return (newline);
		}
		read_bytes = read(fd, buf, 1);
	}
	if (read_bytes == 0)
	{
		if (lst->len > 0)
		{
			newline = print_newline(lst);
		}
		else
		{
			newline = NULL;
		}
		free(lst);
		return (newline);
	}
	else
	{
		return (NULL);
	}
}