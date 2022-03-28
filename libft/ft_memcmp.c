/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:41:32 by joonhan           #+#    #+#             */
/*   Updated: 2022/03/28 17:04:58 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		result;
	size_t	i;
	unsigned char	*(s1_temp);
	unsigned char	*(s2_temp);

	if (n == 0)
		return (0);
	i = 0;
	result = 0;
	s1_temp = (unsigned char *)s1;
	s2_temp = (unsigned char *)s2;
	while (i < n)
	{
		if (*(s1_temp + i) != *(s2_temp + i))
		{
			result = ((int)*(s1_temp + i) - *(s2_temp + i));
			break ;
		}
		i += 1;
	}
	return (result);
}

// int	main(void)
// {
// 	char	src[5] = "ABCD";
// 	char	src2[5] = "ABCD";
// 	int		size[7] = {0, 1, 2, 3, 4, -9999, 9999};
// 	int		reps = sizeof(size) / sizeof(int);

// 	for (int i = 0 ; i < reps; i++)
// 	{
// 		printf("src: %s, src2: %s, size: %d, memcmp: %d\n", src, src2, *(size+ i), memcmp(src, src2, *(size + i)));
// 		printf("src: %s, src2: %s, size: %d, ft_memcmp: %d\n\n", src, src2, *(size+ i), ft_memcmp(src, src2, *(size + i)));
// 	}
// 	return (0);
// }
