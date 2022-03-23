/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:17:05 by joonhan           #+#    #+#             */
/*   Updated: 2022/03/23 14:36:30 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stddef.h>

void	*ft_memchr(const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*find;
	unsigned char	*src_temp;
	unsigned char	temp;

	if (n == 0)
		return (NULL);
	i = 0;
	find = NULL;
	src_temp = (unsigned char *)src;
	temp = (unsigned char)c;
	while (i < n)
	{
		if (*(src_temp + i) == temp)
		{
			find = (src_temp + i);
			break ;
		}
		i += 1;
	}
	return (find);
}

int	main(void)
{
	char	src[6] = "abcde";
	char	search[6] = "abcdf";
	int		size = 3;

	printf("✅ src: %s, size: %d\n\n", src, size);
	for (int i = 0; i < 6; i++)
	{
		printf("i: %d, search: %c, memchr: %p\n", i, *(search + i), memchr(src, *(search + i), size));
		printf("i: %d, search: %c, ft_memchr: %p\n\n", i, *(search + i), ft_memchr(src, *(search + i), size));
	}
	return (0);
}
