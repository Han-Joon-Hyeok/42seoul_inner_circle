/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:41:51 by joonhan           #+#    #+#             */
/*   Updated: 2022/03/28 11:40:12 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

static size_t	ft_strlen(const char *src)
{
	size_t	i;

	i = 0;
	while (*(src + i) != '\0')
		i += 1;
	return (i);
}

static char	*ft_strdup(const char *src)
{
	size_t	i;
	size_t	src_len;
	char	*temp;
	char	*ptr;

	i = 0;
	src_len = ft_strlen(src);
	temp = (char *)src;
	ptr = (char *)malloc((src_len * sizeof(char)) + 1);
	if (ptr == NULL)
		return (NULL);
	while (*(src + i) != '\0')
	{
		*(ptr + i) = *(src + i);
		i += 1;
	}
	*(ptr + i) = '\0';
	return (ptr);
}

static void	ft_strlcpy(char * restrict dest, const char * restrict src, size_t destsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	while ((i + 1) < destsize && *(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i += 1;
	}
	if (i < destsize)
		*(dest + i) = '\0';
}

static char	*ft_strchr(const char *src, int c)
{
	char	temp;
	char	*find;
	size_t	i;
	size_t	src_len;

	temp = (char) c;
	find = NULL;
	i = 0;
	src_len = ft_strlen(src);
	while (i <= src_len)
	{
		if (*(src + i) == temp)
		{
			find = (char *)(src + i);
			break ;
		}
		i += 1;
	}
	return (find);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	front;
	size_t	back;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	front = 0;
	back = ft_strlen(s1);
	while (*(s1 + front) && ft_strchr(set, *(s1 + front)) != NULL)
		front += 1;
	while (*(s1 + back - 1) && ft_strchr(set, *(s1 + back - 1)) != NULL)
	{
		if (back - 1 == 0)
			break ;
		back -= 1;
	}
	if (front > back)
		return (ft_strdup(""));
	ptr = (char *)malloc(sizeof(char) * (back - front + 1));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s1 + front, back - front + 1);
	return (ptr);
}

int	main(void)
{
	char	*src[] = {"bbbbaabbbb", "i am good man", "am good ma", "  ABC  ", "bbbb"};
	char	*set[] = {"a", "good", "ma", " ", "b"};
	int		size = sizeof(src) / sizeof(char *);

	for (int i = 0; i < size; i++)
	{
		printf("src: '%s', set: '%s'\n", *(src + i), *(set + i));
		printf("ft_strtrim: '%s'\n\n", ft_strtrim(*(src + i), *(set + i)));
	}
	return (0);
}
