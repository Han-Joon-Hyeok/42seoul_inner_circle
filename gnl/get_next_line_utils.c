/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:47:18 by joonhan           #+#    #+#             */
/*   Updated: 2022/06/08 23:39:40 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char const *str)
{
	size_t	len;

	len = 0;
	if (str == NULL)
		return (0);
	while (str[len] != '\0')
		len += 1;
	return (len);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_temp;
	unsigned char	*src_temp;

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

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*ptr;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s1, s1_len);
	ft_memcpy(ptr + s1_len, s2, s2_len);
	*(ptr + s1_len + s2_len) = '\0';
	return (ptr);
}

char	*ft_strdup(const char *src)
{
	size_t	i;
	size_t	src_len;
	char	*ptr;

	i = 0;
	src_len = ft_strlen(src);
	ptr = (char *)malloc((src_len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (i < src_len && *(src + i) != '\0')
	{
		*(ptr + i) = *(src + i);
		i += 1;
	}
	*(ptr + i) = '\0';
	return (ptr);
}
