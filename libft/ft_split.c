/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:18:29 by joonhan           #+#    #+#             */
/*   Updated: 2022/03/28 16:04:33 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

static void	ft_bzero(void *dest, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	i = 0;
	temp = (unsigned char *)dest;
	while (i < n)
	{
		*(temp + i) = 0;
		i += 1;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	void	*ptr;

	total = count * size;
	ptr = (void *)malloc(total);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}

static size_t	ft_strlen(const char *src)
{
	size_t	i;

	i = 0;
	while (*(src + i) != '\0')
		i += 1;
	return (i);
}



static size_t	get_word_cnt(const char *src, char d)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (*(src + i) != '\0')
	{
		if (*(src + i) != d)
		{
			cnt += 1;
			while (*(src + i) != '\0' && *(src + i) != d)
				i += 1;
		}
		else
			i += 1;
	}
	return (cnt);

}
static void ft_strlcpy(char * restrict dest, const char * restrict src, size_t destsize)
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

static char	*dup_word(const char *src, char d)
{
	size_t	i;
	size_t	src_len;
	char	*temp;
	char	*ptr;

	i = 0;
	while (*(src + i) != '\0' && *(src + i) != d)
		i += 1;
	ptr = (char *)ft_calloc(i + 1, sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, src, i + 1);
	return (ptr);
}

static char	**free_all(char **s)
{
	size_t	i;

	i = 0;
	while (*(s + i) != NULL)
	{
		free(*(s + i));
		i += 1;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char d)
{
	char	**arr;
	size_t	word_cnt;
	size_t	arr_idx;
	size_t	s_idx;

	if (!s)
		return (NULL);
	word_cnt = get_word_cnt(s, d);
	arr = (char **)ft_calloc(word_cnt + 1, sizeof(char *));
	if (arr == NULL)
		return (NULL);
	arr_idx = 0;
	s_idx = 0;
	while (*(s + s_idx) != '\0' && arr_idx < word_cnt)
	{
		if (*(s + s_idx) != d)
		{
			*(arr + arr_idx) = dup_word(s + s_idx, d);
			if (*(arr + arr_idx) == NULL)
				return (free_all(arr));
			while (*(s + s_idx) != '\0' && *(s + s_idx) != d)
				s_idx += 1;
		}
		else
			s_idx += 1;
	}
	return (arr);
}

int	main(void)
{
	char	**arr;
	char	*src[] = {" Hello World", "Hello World", "Hello Wolrd "};
	char	deli[] = {' ', 'H', 'e', 'l', 'l', 'o'};
	int		src_reps = sizeof(src) / sizeof(char *);
	int		deli_reps = sizeof(deli) / sizeof(char);
	int		i = 0;

	for (int i = 0; i < src_reps; i++)
	{
		printf("✅ src: '%s'\n", *(src + i));
		for (int j = 0; j < deli_reps; j++)
		{
			printf("delimiter: '%c'\n", *(deli + j));
			arr = ft_split(*(src + i), *(deli + j));
		}
		printf("\n");
	}
	
	return (0);
}
