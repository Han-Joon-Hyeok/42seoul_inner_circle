/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 09:31:43 by joonhan           #+#    #+#             */
/*   Updated: 2022/03/28 09:55:59 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

static size_t	ft_strlen(char const *src)
{
	size_t	i;

	i = 0;
	while (*(src + i) != '\0')
		i += 1;
	return (i);
}

static void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*ptr;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s1, s1_len);
	ft_memcpy(ptr + s1_len, s2, s2_len);
	*(ptr + s1_len + s2_len + 1) = '\0';
	return (ptr);
}

int	main(void)
{
	char	*prefix[] = {"Hello", "", "1234"};
	char	*suffix[] = {"Wolrd", "", "5678"};
	int		size = sizeof(prefix) / sizeof(char *);

	for (int i = 0; i < size; i++)
	{
		printf("prefix: %s, suffix: %s\n", *(prefix + i), *(suffix + i));
		printf("ft_strjoin: %s\n\n", ft_strjoin(*(prefix + i), *(suffix + i)));
	}

	return (0);
}
