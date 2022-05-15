/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:35:57 by joonhan           #+#    #+#             */
/*   Updated: 2022/05/15 21:57:54 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	free_all(t_list **p_list)
{
	t_node	*current_node;
	t_node	*next_node;

	if (*p_list == NULL)
		return ;
	current_node = (*p_list)->header;
	while (current_node != NULL)
	{
		next_node = current_node->next;
		free(current_node->backup);
		current_node = next_node;
	}
	free(*p_list);
}

t_node	*lstadd_back(t_list **p_list, int fd, char *buf)
{
	t_node	*new_node;
	t_node	*current_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->fd = fd;
	new_node->backup = ft_strdup(buf);
	new_node->next = NULL;
	current_node = (*p_list)->header;
	if (current_node == NULL)
		(*p_list)->header = new_node;
	else
	{
		while (current_node->next != NULL)
			current_node = current_node->next;
		current_node->next = new_node;
	}
	return (new_node);
}

t_list	*create_new_list(void)
{
	t_list	*p_list;

	p_list = malloc(sizeof(t_list));
	if (p_list == NULL)
		return (NULL);
	p_list->header = NULL;
	return (p_list);
}

t_find	check_new_line(char *buf)
{
	int		i;
	int		found;
	t_find	result;

	i = 0;
	found = FALSE;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
		{
			found = TRUE;
			break;
		}
		i += 1;
	}
	result.index = i;
	result.found = found;
	return (result);
}

char	*split_by_new_line(t_node *p_node, t_find result, char *buf)
{
	char	*temp;
	char	*new_line;

	if (found == TRUE)
	{
		temp = malloc(sizeof(char) * i);
		ft_memcpy(temp, buf, i);
		new_line = ft_strjoin(p_node->backup, temp);
		free(temp);
		free(p_node->backup);
		p_node->backup = ft_strdup(buf + i + 1);
		return (new_line);
	}
	else
	{
		new_line = ft_strdup(p_node->backup);
		free(p_node->backup);
		p_node->backup = ft_strjoin(new_line, buf);
		free(new_line);
		return (p_node->backup);
	}
}

char	*save_backup(t_list *p_list, int fd, char *buf)
{
	t_node	*current_node;

	current_node = p_list->header;
	while (current_node != NULL)
	{
		if (current_node->fd == fd)
			break ;
		current_node = current_node->next;
	}
	if (current_node == NULL)
		current_node = lstadd_back(&p_list, fd, buf);
	else
		current_node->backup = split_by_new_line(current_node, buf);
	if (current_node == NULL)
		return (NULL);
	return (current_node->backup);
}

char	*get_next_line(int fd)
{
	int				len;
	char			buf[BUFFER_SIZE + 1];
	char			*backup;
	t_find			result;
	static t_list	*p_list;

	if (fd < 0)
		return (NULL);
	if (p_list == NULL)
		p_list = create_new_list();
	len = read(fd, buf, BUFFER_SIZE);
	while (len > 0)
	{
		buf[BUFFER_SIZE] = '\0';
		result = check_new_line(buf);
		backup = save_backup(p_list, fd, buf);
		if (backup == NULL)
			return (NULL);
		len = read(fd, buf, BUFFER_SIZE);
	}
	if (len <= 0)
	{
		free_all(&p_list);
		return (NULL);
	}
	return (backup);
}

int	main(void)
{
	int	fd;
	int	result;
	char	*buf;

	fd = open("hello", O_RDONLY);
	if (fd == -1)
		return (-1);
	result = 1;
	while (result != 0)
	{
		buf = get_next_line(fd);
		if (buf == NULL)
			result = 0;
		printf("%s", buf);
	}
	close(fd);
	// system("leaks a.out");
	return (0);
}
