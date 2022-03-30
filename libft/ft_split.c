/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:18:29 by joonhan           #+#    #+#             */
/*   Updated: 2022/03/30 15:14:10 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static char	*dup_word(const char *src, char d)
{
	size_t	i;
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

static char	**split_by_char(char const *s, char d, char **arr, size_t cnt)
{
	size_t	arr_idx;
	size_t	s_idx;

	arr_idx = 0;
	s_idx = 0;
	while (*(s + s_idx) != '\0' && arr_idx < cnt)
	{
		if (*(s + s_idx) != d)
		{
			*(arr + arr_idx) = dup_word((s + s_idx), d);
			if (*(arr + arr_idx++) == NULL)
				return (free_all(arr));
			while (*(s + s_idx) != '\0' && *(s + s_idx) != d)
				s_idx += 1;
		}
		else
			s_idx += 1;
	}
	return (arr);
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
	arr = split_by_char(s, d, arr, word_cnt);
	return (arr);
}
