/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:39:35 by joonhan           #+#    #+#             */
/*   Updated: 2022/03/28 17:13:03 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	char	temp;
	char	*find;
	size_t	src_len;
	size_t	i;

	temp = (char) c;
	find = NULL;
	src_len = ft_strlen(src);
	i = 0;
	while (i <= src_len)
	{
		if (*(src + i) == temp)
			find = (char *)src + i;
		i += 1;
	}
	return (find);
}

// int	main(void)
// {
// 	char	src[5] = "abca";
// 	char	src2[5] = "b\0acb";
// 	char	search[5] = {'a', 'b', 'c', 'd'};
// 	size_t	size = 5;

// 	printf("✅ src: %s\n\n", src);
// 	for (int i = 0; i < size; i++)
// 	{
// 		int c = *(search + i);
// 		printf("c: %c, strchr: %p\n", c, strrchr(src, c));
// 		printf("c: %c, ft_strrchr: %p\n\n", c, ft_strrchr(src, c));
// 	}
	
// 	printf("\n\n✅ src2: %s\n\n", src2);
// 	for (int i = 0; i < size; i++)
// 	{
// 		int c = *(search + i);
// 		printf("c: %c, strchr: %p\n", c, strrchr(src2, c));
// 		printf("c: %c, ft_strrchr: %p\n\n", c, ft_strrchr(src2, c));
// 	}	
// 	return (0);
// }
