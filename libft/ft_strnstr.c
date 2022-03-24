/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:09:42 by joonhan           #+#    #+#             */
/*   Updated: 2022/03/24 11:44:16 by joonhan          ###   ########.fr       */
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
	size_t	cnt;
	size_t	small_len;

	small_len = ft_strlen((char *)small);
	if (small_len == 0)
		return ((char *)(big));
	i = 0;
	cnt = 0;
	while (i < len)
	{
		while (*(big + i + cnt) == *(small + cnt) && *(big + i + cnt) != '\0')
		{
			if (i + cnt == len)
				break ;
			cnt += 1;
		}	
		if (cnt == small_len)
			break ;
		i += 1;
		cnt = 0;
	}
	if (cnt != small_len)
		return (NULL);
	return ((char *)(big + i));
}

int	main(void)
{
	const char	*largestring = "Foo Bar Baz";
	const char	*smallstring = "Fo";
	char	*ptr;
	char	*ft_ptr;
	size_t		size[12] = {0, 1, 2, 3, 4, 5, 6, 7, 12, 999, 1491212, 123123123};
	size_t		reps = sizeof(size) / sizeof(size_t);

	printf("🛠 large: %s, small: %s\n\n", largestring, smallstring);
	for (size_t i = 0; i < reps; i++)
	{
		ptr = strnstr(largestring, smallstring, *(size + i));	
		ft_ptr = ft_strnstr(largestring, smallstring, *(size + i));
		printf("✅ strnstr\n");
		printf("size: %zu, ptr: %p, str: %s\n", *(size + i), ptr, ptr);
		printf("✅ ft_strnstr\n");
		printf("size: %zu, ptr: %p, str: %s\n\n", *(size + i), ft_ptr, ft_ptr);
	}
	return (0);
}
