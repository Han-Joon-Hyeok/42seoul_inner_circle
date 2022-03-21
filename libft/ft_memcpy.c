/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:57:24 by joonhan           #+#    #+#             */
/*   Updated: 2022/03/21 15:41:07 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdio.h>

void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	size_t				i;
	unsigned char		*dest_temp;
	const unsigned char *src_temp;

	if (n == 0 || dest == src)
		return (dest);
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

int	main(void)
{
	char	src[4] = "gun";
	char	dest[4];
	char	src2[4] = "gun";
	char	dest2[4];
	size_t	size = 4;

	memcpy(dest, src, size);
	ft_memcpy(dest2, src2, size);
	for (int i = 0; i < size; i++)
	{
		printf("memcpy: %c \n", *(dest + i));
	}
	for (int j = 0; j < size; j++)
	{
		printf("ft_memcpy: %c \n", *(dest2 + j));
	}
	return (0);
}
