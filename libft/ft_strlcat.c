/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:32:07 by joonhan           #+#    #+#             */
/*   Updated: 2022/03/22 16:56:03 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stddef.h>

static size_t	ft_strlen(const char *src)
{
	size_t	i;

	i = 0;
	while (*(src + i) != '\0')
		i += 1;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	dest_len;
	size_t	dest_idx;
	size_t	src_len;
	size_t	src_idx;

	dest_len = ft_strlen(dest);
	dest_idx = dest_len;
	src_len = ft_strlen(src);
	src_idx = 0;
	if (destsize == 0 || destsize < dest_len + 1)
		return (destsize + src_len);
	while (*(src + src_idx) != '\0')
	{
		if ((dest_idx + 1) == destsize)
			break ;
		*(dest + dest_idx) = *(src + src_idx);
		dest_idx += 1;
		src_idx += 1;
	}
	*(dest + dest_idx) = '\0';
	return (dest_len + src_len);
}

int	main(void)
{
	char	src[4] = "abc";
	char	dest[4] = "12";
	char	src2[4] = "abc";
	char	dest2[4] = "12";
	int		size[5] = {0, 1, 2, 3, 4};
	for (int i = 0; i < 5; i++)
	{
		int	result = strlcat(dest, src, size[i]);
		printf("dest: %s, src: %s, strlcat: %d\n", dest, src, result);
		int	result2 = ft_strlcat(dest2, src2, size[i]);
		printf("dest2: %s, src2: %s, ft_strlcat: %d\n\n", dest2, src2, result2);
	}
	return (0);
}
