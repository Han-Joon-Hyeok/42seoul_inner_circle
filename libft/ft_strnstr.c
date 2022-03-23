/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:09:42 by joonhan           #+#    #+#             */
/*   Updated: 2022/03/23 17:56:56 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stddef.h>

static size_t	ft_strlen(char *src)
{
	size_t	i;

	i = 0;
	while (*(src + i) != '\0')
		i += 1;
	return (i);
}

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t	i;
	size_t	start;
	size_t	count;
	size_t	small_len;
	char	*find;

	if (len == 0)
		return (NULL);
	small_len = ft_strlen((char *)small);
	if (small_len == 0)
		return ((char *)big);
	i = 0;
	start = 0;
	count = 0;
	find = NULL;
	while (i < len)
	{
		if ((char *)(big + i) == (char *)(small + i))
		{
			start = i;
		}
		i += 1;
	}
	if (count == small_len)
		find = (char *)big;
	return (find);
}

int	main(void)
{
	const char	*largestring = "Foo Bar Baz";
	const char	*smallstring = "";
	char	*ptr;
	size_t		size[8] = {0, 1, 6, 7, 12, 999, 1491212, 123123123};
	size_t		reps = sizeof(size) / sizeof(size_t);

	printf("large: %s, small: %s\n\n", largestring, smallstring);
	for (size_t i = 0; i < reps; i++)
	{
		ptr = strnstr(largestring, smallstring, *(size + i));
		printf("size: %zu, ptr: %p, str: %s\n", *(size + i), ptr, ptr);
	}
	return (0);
}
