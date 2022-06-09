/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:35:57 by joonhan           #+#    #+#             */
/*   Updated: 2022/06/08 23:56:06 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*free_fd(t_node **p_head, int fd)
{
	t_node	*prev;

	prev = NULL;
	while ((*p_head) != NULL)
	{
		if ((*p_head)->fd == fd)
		{
			if ((*p_head)->backup != NULL)
				free((*p_head)->backup);
			free(*p_head);
			if (prev != NULL)
				prev->next = NULL;
			else
				*p_head = NULL;
			break ;
		}
		prev = *p_head;
		*p_head = (*p_head)->next;
	}
	return (NULL);
}

t_node	*find_fd(t_node **p_head, int fd)
{
	t_node	*new;
	t_node	*curr;
	t_node	*prev;

	prev = NULL;
	curr = *p_head;
	while (curr != NULL)
	{
		if (curr->fd == fd)
			return (curr);
		prev = curr;
		curr = curr->next;
	}
	new = (t_node *)malloc(sizeof(t_node));
	if (new == NULL)
		return (NULL);
	new->backup = NULL;
	new->fd = fd;
	new->next = NULL;
	if (*p_head == NULL)
		*p_head = new;
	else
		prev->next = new;
	return (new);
}

char	*split_newline(t_node *p_node, int i)
{
	char	*next;
	char	*newline;
	size_t	backup_len;

	newline = (char *)malloc(sizeof(char) * (i + 2));
	if (newline == NULL)
		return (NULL);
	newline = ft_memcpy(newline, p_node->backup, i + 1);
	newline[i + 1] = '\0';
	backup_len = ft_strlen(p_node->backup);
	if (backup_len - i > 1)
	{
		next = (char *)malloc(sizeof(char) * (backup_len - i));
		if (next == NULL)
			return (NULL);
		next = ft_memcpy(next, &p_node->backup[i + 1], backup_len - i - 1);
		next[backup_len - i - 1] = '\0';
		if (p_node->backup != NULL)
			free(p_node->backup);
		p_node->backup = next;
	}
	else
	{
		if (p_node->backup != NULL)
			free(p_node->backup);
		p_node->backup = NULL;
	}
	return (newline);
}

void	save_in_backup(t_node **p_head, t_node *p_node, ssize_t len)
{
	char	*buf;
	char	*prev_backup;

	if (len == 0)
		return ;
	buf = (char *)malloc(sizeof(char) * (len + 1));
	if (buf == NULL)
		free_fd(p_head, p_node->fd);
	buf = ft_memcpy(buf, p_node->buf, len);
	buf[len] = '\0';
	if (p_node->backup == NULL)
		p_node->backup = buf;
	else
	{
		prev_backup = ft_strdup(p_node->backup);
		free(p_node->backup);
		p_node->backup = ft_strjoin(prev_backup, buf);
		free(prev_backup);
		free(buf);
	}
}

int	check_newline_in_backup(t_node **p_head, t_node *p_node, ssize_t len)
{
	int	i;
	int	found;

	save_in_backup(p_head, p_node, len);
	i = 0;
	found = FALSE;
	while (p_node->backup != NULL && p_node->backup[i] != '\0')
	{
		if (p_node->backup[i] == '\n')
		{
			found = TRUE;
			break ;
		}
		i += 1;
	}
	if (found == FALSE)
		return (FALSE);
	return (i);
}

char	*clear_backup(t_node **p_head, t_node *p_node, int fd)
{
	char	*newline;

	if (p_node->backup == NULL)
		return (free_fd(p_head, fd));
	newline = ft_strdup(p_node->backup);
	free_fd(p_head, fd);
	return (newline);
}

char	*get_next_line(int fd)
{
	ssize_t			len;
	t_node			*p_node;
	static t_node	*p_head;
	int				found_newline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	p_node = find_fd(&p_head, fd);
	if (p_head == NULL || p_node == NULL)
		return (free_fd(&p_head, fd));
	len = 0;
	while (len >= 0)
	{
		len = read(fd, p_node->buf, BUFFER_SIZE);
		if (len < 0)
			return (free_fd(&p_head, fd));
		found_newline = check_newline_in_backup(&p_head, p_node, len);
		if (found_newline != FALSE)
			return (split_newline(p_node, found_newline));
		if (len != BUFFER_SIZE)
			return (clear_backup(&p_head, p_node, fd));
	}
	return (NULL);
}
