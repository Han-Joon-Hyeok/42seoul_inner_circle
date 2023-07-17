/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkpa <jeongkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:35:57 by joonhan           #+#    #+#             */
/*   Updated: 2023/01/20 14:46:03 by jeongkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	str_free(char *str)
{
	free(str);
	str = NULL;
}

static char	*my_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	size;

	if (!s)
		return (NULL);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	size = ft_strlen(s);
	if (size <= start)
	{
		str[0] = '\0';
		return (str);
	}
	i = 0;
	while (s[start + i] != '\0' && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*read_line(int fd, char *buf, char *backup)
{
	int		read_size;
	char	*temp;

	read_size = read(fd, buf, BUFFER_SIZE);
	while (read_size)
	{
		if (read_size == -1)
			return (NULL);
		buf[read_size] = '\0';
		if (!backup)
			backup = ft_strdup("");
		temp = backup;
		backup = ft_strjoin(backup, buf);
		str_free(temp);
		if (!backup)
			return (NULL);
		if (ft_strchr(backup, '\n'))
			break ;
		read_size = read(fd, buf, BUFFER_SIZE);
	}
	return (backup);
}

static char	*get_line(char *line)
{
	int		i;
	char	*backup;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	backup = my_substr(line, i + 1, ft_strlen(line) - 1);
	if (!backup)
		return (NULL);
	if (backup[0] == '\0')
	{
		str_free(backup);
		return (NULL);
	}
	line[i + 1] = '\0';
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buf;
	char		*line;

	if ((fd < 0) || (BUFFER_SIZE < 1))
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = read_line(fd, buf, backup);
	str_free(buf);
	if (!line)
	{
		str_free(backup);
		return (NULL);
	}
	backup = get_line(line);
	return (line);
}
