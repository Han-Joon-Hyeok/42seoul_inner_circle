/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:38:51 by joonhan           #+#    #+#             */
/*   Updated: 2022/03/22 15:10:48 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <string.h>

static size_t	ft_strlen(char *src)
{
	size_t	i;

	i = 0;
	while (*(src + i) != '\0')
		i++;
	return (i);
}

size_t ft_strlcpy(char * restrict dest, const char * restrict src, size_t destsize)
{
	size_t	i;
	size_t	src_len;
	
	i = 0;
	src_len = ft_strlen((char *)src);
	while ((i + 1) < destsize && *(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i += 1;	
	}
	if (i < destsize)
		*(dest + i) = '\0';
	return (src_len);	
}

int	main(void)
{
	char	src[4] = "abc";
	char	dest[4] = "123";
	size_t	result;	

	char	*src2 = NULL;
	char	dest2[4] = "123";
	size_t	result2;
	size_t	size = 2;

	result = ft_strlcpy(dest, src, size);
	result2 = strlcpy(dest2, src2, size);
	
	return (0);
}
