/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:38:51 by joonhan           #+#    #+#             */
/*   Updated: 2022/03/28 17:10:24 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcpy(char * restrict dest, const char * restrict src, size_t destsize)
{
	size_t	i;
	size_t	src_len;
	
	i = 0;
	src_len = ft_strlen(src);
	while ((i + 1) < destsize && *(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i += 1;	
	}
	if (i < destsize)
		*(dest + i) = '\0';
	return (src_len);	
}

// int	main(void)
// {
// 	char	src[4] = "abc";
// 	char	dest[4] = "123";
// 	size_t	result;	

// 	char	*src2 = NULL;
// 	char	dest2[4] = "123";
// 	size_t	result2;
// 	size_t	size = 2;

// 	result = ft_strlcpy(dest, src, size);
// 	result2 = strlcpy(dest2, src2, size);
	
// 	return (0);
// }
