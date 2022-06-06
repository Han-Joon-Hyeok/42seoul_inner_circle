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
			curr = NULL;
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

char	*split_newline(t_node *p_node, int i)
{
	int		backup_len;
	char	*next;
	char	*newline;

	backup_len = ft_strlen(p_node->backup);
	next = (char *)malloc(sizeof(char) * (backup_len - i));
	if (next == NULL)
		return (NULL);
	ft_memcpy(next, &p_node->backup[i + 1], backup_len - i - 1);
	next[backup_len - i - 1] = '\0';
	newline = (char *)malloc(sizeof(char) * (i + 2));
	if (newline == NULL)
	{
		free(next);
		return (NULL);
	}
	ft_memcpy(newline, p_node->backup, i + 1);
	newline[i + 1] = '\0';
	free(p_node->backup);
	p_node->backup = next;
	return (newline);
}

char	*check_newline_in_backup(t_node *p_node, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (p_node->backup[i] == '\n')
			return (split_newline(p_node, i));
		i += 1;
	}
	return (NULL);
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
	new_node->is_end = FALSE;
	if (prev != NULL)
		prev->next = new_node;
	else
		*p_head = new_node;
	return (new_node);
}

void	save_in_backup(t_node *p_node, int len)
{
	char	*temp;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (len + 1));
	if (buf == NULL)
		return ;
	ft_memcpy(buf, p_node->buf, len);
	buf[len] = '\0';
	if (p_node->backup != NULL)
	{
		temp = ft_strdup(p_node->backup);
		free(p_node->backup);
		p_node->backup = ft_strjoin(temp, buf);
		free(temp);
	}
	else
		p_node->backup = ft_strdup(buf);
	free(buf);
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
	if (p_head == NULL || p_node == NULL || p_node->is_end == TRUE)
	{
		free_fd(&p_head, fd);
		return (NULL);
	}
	len = read(fd, p_node->buf, BUFFER_SIZE);
	if (len == 0)
	{
		p_node->is_end = TRUE;
		return (ft_strdup(p_node->backup));
	}
	while (len >= 0)
	{
		save_in_backup(p_node, len);
		newline = check_newline_in_backup(p_node, len);
		if (newline != NULL)
			return (newline);
		len = read(fd, p_node->buf, BUFFER_SIZE);
	}
	return (NULL);
}
