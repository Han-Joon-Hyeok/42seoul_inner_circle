/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:11:58 by joonhan           #+#    #+#             */
/*   Updated: 2022/03/21 17:56:10 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
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

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*copy;

	if (len == 0)
		return (dest);
	copy = malloc(sizeof(unsigned char) * len);
	if (copy == NULL)
		return (NULL);
	ft_memcpy(copy, src, len);
	i = 0;
	while (i < len)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)copy)[i];
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
	int		size = 10;

	ft_memmove(dest, src, sizeof(char) * size);
	for (int i = 0; i < 3; i++)
		printf("ft_memmove: %c\n", *(dest + i));
	memmove(dest2, src2, sizeof(char) * size);
	for (int j = 0; j < 3; j++)
		printf("memmove: %c\n", *(dest2 + j));
	return (0);
}
