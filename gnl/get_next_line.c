/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:35:57 by joonhan           #+#    #+#             */
/*   Updated: 2022/06/07 19:46:57 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*free_fd(t_node **p_head, int fd)
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
			break ;
		}
		prev = curr;
		curr = curr->next;
	}
	return (NULL);
}

char	*split_newline(t_node *p_node, int i)
{
	char	*next;
	char	*newline;
	int		backup_len;

	newline = (char *)malloc(sizeof(char) * (i + 2));
	if (newline == NULL)
		return (NULL);
	ft_memcpy(newline, p_node->backup, i + 1);
	newline[i + 1] = '\0';
	backup_len = ft_strlen(p_node->backup);
	if (backup_len - i > 1)
	{
		next = (char *)malloc(sizeof(char) * (backup_len - i));
		if (next == NULL)
			return (NULL);
		ft_memcpy(next, &p_node->backup[i + 1], backup_len - i - 1);
		next[backup_len - i - 1] = '\0';
		free(p_node->backup);
		p_node->backup = next;
	}
	else
	{
		free(p_node->backup);
		p_node->backup = NULL;
	}
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
	if (prev != NULL)
		prev->next = new_node;
	else
		*p_head = new_node;
	return (new_node);
}

int	save_in_backup(t_node *p_node, int len)
{
	char	*buf;
	char	*prev_backup;

	if (len < 0)
		return (-1);
	buf = (char *)malloc(sizeof(char) * (len + 1));
	if (buf == NULL)
		return (-1);
	ft_memcpy(buf, p_node->buf, len);
	buf[len] = '\0';
	if (p_node->backup != NULL)
	{
		prev_backup = ft_strdup(p_node->backup);
		free(p_node->backup);
		p_node->backup = ft_strjoin(prev_backup, buf);
		free(prev_backup);
	}
	else
		p_node->backup = ft_strdup(buf);
	free(buf);
	return (len);
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
	if (p_head == NULL || p_node == NULL)
		return (free_fd(&p_head, fd));
	len = save_in_backup(p_node, read(fd, p_node->buf, BUFFER_SIZE));
	if (len <= 0)
		return (free_fd(&p_head, fd));
	while (len >= 0)
	{
		if (len == 0)
		{
			newline = ft_strdup(p_node->backup);
			free_fd(&p_head, fd);
			return (newline);
		}
		newline = check_newline_in_backup(p_node, len);
		if (newline != NULL)
			return (newline);
		len = read(fd, p_node->buf, BUFFER_SIZE);
	}
	return (NULL);
}
