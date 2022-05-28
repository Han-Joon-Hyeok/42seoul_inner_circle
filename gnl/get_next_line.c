/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:35:57 by joonhan           #+#    #+#             */
/*   Updated: 2022/05/16 20:03:39 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*split_newline(t_node *p_node, int i)
{
	char	*prev;
	char	*next;
	char	*newline;

	prev = (char *)malloc(sizeof(char) * (i + 1));
	next = (char *)malloc(sizeof(char) * (BUFFER_SIZE - i + 1));
	if (prev == NULL || next == NULL)
		return (NULL);
	prev = ft_memcpy(prev, p_node->buf, i + 1);
	prev[i] = '\0';
	newline = ft_strjoin(p_node->backup, prev);
	free(prev);
	next = ft_memcpy(next, &p_node->buf[i + 1], BUFFER_SIZE - i);
	p_node->backup = next;
	return (newline);
}

char	*check_newline_in_buf(t_node *p_node)
{
	int	i;
	int	found;

	i = 0;
	found = FALSE;
	while (p_node->buf[i] != '\0')
	{
		if (p_node->buf[i] == '\n')
		{
			found = TRUE;
			break ;
		}
		i += 1;
	}
	if (found)
		return (split_newline(p_node, i));
	p_node->backup = ft_strjoin(p_node->backup, p_node->buf);
	if (p_node->backup == NULL)
		return (NULL);
	return (NULL);
}

void	free_all(t_node *p_head)
{
	t_node	*curr;
	t_node	*next;

	curr = p_head;
	while (curr != NULL)
	{
		next = curr->next;
		free(curr->backup);
		free(curr);
		curr = next;
	}
}

t_node	*find_fd(t_node *p_head, int fd)
{
	t_node	*find;

	find = p_head;
	while (find->next != NULL)
	{
		if (find->fd == fd)
			break ;
		find = find->next;
	}
	if (find->fd == fd)
		return (find);
	if (find->next == NULL)
		find->next = (t_node *)malloc(sizeof(t_node));
	if (find->next != NULL)
	{
		find->next->next = NULL;
		find->next->fd = fd;
	}
	return (find->next);
}

char	*get_next_line(int fd)
{
	int				len;
	t_node			*p_node;
	static t_node	*p_head;
	char			*newline;
	
	if (p_head == NULL)
		p_head = (t_node *)malloc(sizeof(t_node));
	p_node = find_fd(p_head, fd);
	len = read(fd, p_node->buf, BUFFER_SIZE);
	if (BUFFER_SIZE <= 0 || fd < 0 || p_head == NULL || p_node == NULL || len <= 0)
	{
		free_all(p_head);
		return (NULL);
	}
	while (len > 0) {
		newline = check_newline_in_buf(p_node);
		if (newline != NULL)
			return (newline);
		len = read(fd, p_node->buf, BUFFER_SIZE);
	}
	return (NULL);
}

int	main(void)
{
	int		fd;
	char	*buf;

	fd = open("hello", O_RDONLY);
	if (fd == -1)
		return (-1);
	while (TRUE)
	{
		buf = get_next_line(fd);
		if (buf == NULL)
			break ;
		printf("%s", buf);
		free(buf);
	}
	close(fd);
	// system("leaks a.out");
	return (0);
}
