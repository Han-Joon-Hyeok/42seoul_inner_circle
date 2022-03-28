/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:11:58 by joonhan           #+#    #+#             */
/*   Updated: 2022/03/28 17:07:28 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*dest_temp;
	const unsigned char	*src_temp;

	if (len == 0)
		return (dest);
	dest_temp = (unsigned char *)dest;
	src_temp = (unsigned char *)src;
	if (dest > src)
	{
		dest_temp += len - 1;
		src_temp += len - 1;
		while (len-- > 0)
			*(dest_temp--) = *(src_temp--);
	}
	else
	{
		while (len-- > 0)
			*(dest_temp++) = *(src_temp++);
	}
	return (dest);
}

// int	main(void)
// {
// 	char	src[4] = "abc";
// 	char	dest[4];
// 	char	src2[4] = "abc";
// 	char	dest2[4];
// 	int		size = 2;

// 	ft_memmove(src + 1, src, sizeof(char) * size);
// 	for (int i = 0; i < 3; i++)
// 		printf("ft_memmove: %c\n", *(src + i));
	
// 	memmove(src2 + 1, src2, sizeof(char) * size);
// 	for (int j = 0; j < 3; j++)
// 		printf("memmove: %c\n", *(src2 + j));
// 	return (0);
// }
