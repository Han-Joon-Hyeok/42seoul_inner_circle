/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:35:57 by joonhan           #+#    #+#             */
/*   Updated: 2022/05/30 00:26:01 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*split_newline(t_node *p_node, int i)
{
	char	*prev;
	char	*next;

	prev = (char *)malloc(sizeof(char) * (i + 2));
	next = (char *)malloc(sizeof(char) * (BUFFER_SIZE - i));
	if (prev == NULL || next == NULL)
		return (NULL);
	prev = ft_memcpy(prev, p_node->buf, i + 1);
	prev[i + 1] = '\0';
	p_node->newline = ft_strjoin(&p_node->backup, prev);
	if (p_node->newline == NULL)
		return (NULL);
	free(prev);
	next = ft_memcpy(next, &p_node->buf[i + 1], BUFFER_SIZE - i - 1);
	next[BUFFER_SIZE - i - 1] = '\0';
	p_node->backup = next;
	return (p_node->newline);
}

char	*check_newline_in_buf(t_node *p_node, int len)
{
	int		i;
	char	*temp;

	i = 0;
	if (len == 0)
	{
		free(p_node->newline);
		p_node->newline = ft_strdup(p_node->backup);
		return (p_node->newline);
	}
	while (p_node->buf[i] != '\0' && i < len)
	{
		if (p_node->buf[i] == '\n')
			return (split_newline(p_node, i));
		i += 1;
	}
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (temp == NULL)
		return (NULL);
	ft_memcpy(temp, p_node->buf, len);
	temp[len] = '\0';
	if (p_node->backup == NULL)
		p_node->backup = ft_strdup(temp);
	else
		p_node->backup = ft_strjoin(&p_node->backup, temp);
	free(temp);
	return (NULL);
}

void	free_fd(t_node **p_head, int fd)
{
	t_node	*prev;
	t_node	*curr;
	t_node	*next;

	prev = (NULL);
	curr = (*p_head)->next;
	while (curr != NULL)
	{
		next = curr->next;
		if (curr->fd == fd)
		{
			if (curr->newline != NULL && curr->backup != NULL)
			{
				free(curr->newline);
				free(curr->backup);
			}
			free(curr);
			if (prev != NULL)
				prev->next = NULL;
			if ((*p_head)->next == NULL)
			{
				free(*p_head);
				*p_head = NULL;
			}
			return ;
		}
		prev = curr;
		curr = next;
	}
}

t_node	*create_new_node(t_node	*p_list, int fd)
{
	t_node	*new_node;
	t_node	*prev;
	t_node	*curr;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->fd = fd;
	prev = NULL;
	curr = p_list->next;
	while (curr != NULL)
	{
		prev = curr;
		curr = curr->next;
	}
	if (prev == NULL)
	{
		p_list->next = new_node;
		return (p_list->next);
	}
	else
	{
		curr = new_node;
		prev->next = curr;
		return (curr);
	}
}

t_node	*find_fd(t_node **p_list, int fd)
{
	t_node	*curr;

	if (*p_list == NULL)
	{
		*p_list = (t_node *)malloc(sizeof(t_node));
		if (*p_list == NULL)
			return (NULL);
		(*p_list)->next = NULL;
	}
	curr = (*p_list)->next;
	while (curr != NULL)
	{
		if (curr->fd == fd)
			return (curr);
		curr = curr->next;
	}
	return (create_new_node(*p_list, fd));
}

char	*get_next_line(int fd)
{
	int				len;
	t_node			*p_node;
	static t_node	*p_head;
	char			*newline;

	if (fd < 0)
		return (NULL);
	if (p_head == NULL)
		p_head = find_fd(p_head, fd);
	p_node = find_fd(p_head, fd);
	len = read(fd, p_node->buf, BUFFER_SIZE);
	if (BUFFER_SIZE <= 0 || p_head == NULL || p_node == NULL || len <= 0)
	{
		free_fd(&p_head, fd);
		return (NULL);
	}
	while (len >= 0)
	{
		newline = check_newline_in_buf(p_node, len);
		if (newline != NULL)
			return (newline);
		len = read(fd, p_node->buf, BUFFER_SIZE);
	}
	return (NULL);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*buf;

// 	fd = open("empty", O_RDONLY);
// 	buf = get_next_line(1000);
// 	buf = get_next_line(-1);
// 	close(fd);

// 	fd = open("nl", O_RDONLY);
// 	buf = get_next_line(fd);
// 	buf = get_next_line(fd);
// 	close(fd);
// 	// system("leaks a.out");
// 	return (0);
// }
