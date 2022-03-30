/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:57:24 by joonhan           #+#    #+#             */
/*   Updated: 2022/03/30 15:38:27 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
