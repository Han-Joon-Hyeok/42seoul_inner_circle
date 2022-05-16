/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:35:57 by joonhan           #+#    #+#             */
/*   Updated: 2022/05/16 17:48:05 by joonhan          ###   ########.fr       */
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

t_node	*lstget_node(t_list *p_list, int fd)
{
	t_node	*current_node;

	current_node = p_list->header;
	while (current_node != NULL)
	{
		if (current_node->fd == fd)
			break ;
		current_node = current_node->next;
	}
	return (current_node);
}

char	*split_by_newline(t_find result, t_list *p_list, int fd, char *buf)
{
	char	*temp;
	char	*newline;
	t_node	*current_node;

	current_node = lstget_node(p_list, fd);
	temp = malloc(sizeof(char) * (result.index + 1));
	ft_memcpy(temp, buf, result.index);
	temp[result.index] = '\0';
	newline = ft_strjoin(current_node->backup, temp);
	free(temp);
	free(current_node->backup);
	current_node->backup = ft_strdup(buf + result.index + 1);
	return (newline);
}

void	save_backup(t_find result, t_list *p_list, int fd, char *buf)
{
	char	*temp;
	char	*backup;
	t_node	*current_node;

	current_node = lstget_node(p_list, fd);
	if (current_node == NULL)
		current_node = lstadd_back(&p_list, fd, buf);
	else
	{
		temp = malloc(sizeof(char) * result.index);
		ft_memcpy(temp, buf, result.index);
		backup = ft_strdup(current_node->backup);
		free(current_node->backup);
		current_node->backup = ft_strjoin(backup, temp);
		free(backup);
		free(temp);
	}
}

char	*get_next_line(int fd)
{
	int				len;
	char			buf[BUFFER_SIZE + 1];
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
		if (result.found == TRUE)
			return (split_by_newline(result, p_list, fd, buf));
		save_backup(result, p_list, fd, buf);
		len = read(fd, buf, BUFFER_SIZE);
	}
	free_all(&p_list);
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
	system("leaks a.out");
	return (0);
}
