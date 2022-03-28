/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:17:05 by joonhan           #+#    #+#             */
/*   Updated: 2022/03/28 17:03:29 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

// int	main(void)
// {
// 	char	src[6] = "abcde";
// 	char	search[6] = "abcdf";
// 	int		size = 3;

// 	printf("✅ src: %s, size: %d\n\n", src, size);
// 	for (int i = 0; i < 6; i++)
// 	{
// 		printf("i: %d, search: %c, memchr: %p\n", i, *(search + i), memchr(src, *(search + i), size));
// 		printf("i: %d, search: %c, ft_memchr: %p\n\n", i, *(search + i), ft_memchr(src, *(search + i), size));
// 	}
// 	return (0);
// }
