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

char	*split_newline(t_node *p_node, int i)
{
	char	*prev;
	char	*next;
	char	*newline;

	prev = (char *)malloc(sizeof(char) * (i + 2));
	if (prev == NULL)
		return (NULL);
	ft_strlcpy(prev, p_node->buf, i + 2);
	newline = ft_strjoin(p_node->backup, prev);
	if (p_node->backup != NULL)
		free(p_node->backup);
	free(prev);
	if (newline == NULL)
		return (NULL);
	next = (char *)malloc(sizeof(char) * (BUFFER_SIZE - i));
	if (next == NULL)
	{
		free(newline);
		return (NULL);
	}
	ft_strlcpy(next, &p_node->buf[i + 1], BUFFER_SIZE - i);
	p_node->backup = next;
	return (newline);
}

char	*check_newline_in_buf(t_node *p_node, int len)
{
	int		i;
	char	*temp;

	i = 0;
	if (len == 0)
		return (split_newline(p_node, i));
	while (i < len)
	{
		if (p_node->buf[i] == '\n')
			return (split_newline(p_node, i));
		i += 1;
	}
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (temp == NULL)
		return (NULL);
	ft_strlcpy(temp, p_node->buf, len + 1);
	if (p_node->backup != NULL)
		free(p_node->backup);
	p_node->backup = ft_strjoin(p_node->backup, temp);
	free(temp);
	return (NULL);
}

void	free_fd(t_node **p_head, int fd)
{
	t_node	*prev;
	t_node	*curr;

	prev = NULL;
	curr = *p_head;
	while (curr != NULL)
	{
		if (curr->fd == fd)
		{
			if (curr->backup != NULL)
				free(curr->backup);
			curr->backup = NULL;
			curr->next = NULL;
			free(curr);
			if (prev != NULL)
				prev->next = NULL;
			else
				*p_head = NULL;
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}

t_node	*find_fd(t_node **p_head, int fd)
{
	t_node	*prev;
	t_node	*curr;
	t_node	*new_node;

	prev = NULL;
	curr = *p_head;
	while (curr != NULL)
	{
		if (curr->fd == fd)
			return (curr);
		prev = curr;
		curr = curr->next;
	}
	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->fd = fd;
	new_node->backup = NULL;
	new_node->next = NULL;
	if (prev != NULL)
		prev->next = new_node;
	else
		*p_head = new_node;
	return (new_node);
}

char	*get_next_line(int fd)
{
	int				len;
	t_node			*p_node;
	static t_node	*p_head;
	char			*newline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	p_node = find_fd(&p_head, fd);
	len = read(fd, p_node->buf, BUFFER_SIZE);
	if (p_head == NULL || p_node == NULL || len <= 0)
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
