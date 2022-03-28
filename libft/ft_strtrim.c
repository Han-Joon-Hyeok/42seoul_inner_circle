/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:41:51 by joonhan           #+#    #+#             */
/*   Updated: 2022/03/28 11:07:18 by joonhan          ###   ########.fr       */
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

static void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	size_t				i;
	unsigned char		*dest_temp;
	const unsigned char	*src_temp;

	if (n == 0 || dest == src)
		return (dest);
	if (src == NULL || dest == NULL)
		return (NULL);
	i = 0;
	dest_temp = (unsigned char *)dest;
	src_temp = (unsigned char *)src;
	while (i < n)
	{
		*(dest_temp + i) = *(src_temp + i);
		i += 1;
	}
	return (dest);
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
	size_t	len;
	size_t	front;
	size_t	back;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	front = 0;
	back = ft_strlen(s1);
	while (ft_strchr(set, *(s1 + front)) != NULL)
		front += 1;
	while (ft_strchr(set, *(s1 + back)) != NULL)
		back -= 1;
	len = back - front + 1;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s1 + front, len);
	*(ptr + len + 1) = '\0';
	return (ptr);
}

int	main(void)
{
	char	*src[] = {"bbbbaabbbb", "i am good man", "am good ma", "  ABC  "};
	char	*set[] = {"a", "good", "ma", " "};
	int		size = sizeof(src) / sizeof(char *);

	for (int i = 0; i < size; i++)
	{
		printf("src: '%s', set: '%s'\n", *(src + i), *(set + i));
		printf("ft_strtrim: '%s'\n\n", ft_strtrim(*(src + i), *(set + i)));
	}
	return (0);
}
