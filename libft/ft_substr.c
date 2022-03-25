/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:42:34 by joonhan           #+#    #+#             */
/*   Updated: 2022/03/25 17:47:14 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

static size_t	ft_strlen(const char *src)
{
	size_t	i;

	i = 0;
	while (*(src + i) != '\0')
		i += 1;
	return (i);
}

static char	*ft_strdup(const char *src)
{
	size_t	i;
	size_t	src_len;
	char	*temp;
	char	*ptr;

	i = 0;
	src_len = ft_strlen(src);
	temp = (char *)src;
	ptr = (char *)malloc(sizeof(char) * (src_len + 1));
	if (ptr == NULL)
		return (NULL);
	while (*(src + i) != '\0')
	{
		*(ptr + i) = *(src + i);
		i += 1;
	}
	*(ptr + i) = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			cnt;
	size_t			src_len;
	char			*ptr;

	if (!s)
		return (NULL);
	ptr = (char *)malloc(sizeof(char) * (src_len + 1));
	if (ptr == NULL)
		return (NULL);
	src_len = ft_strlen(s);
	if (start >= src_len)
	{
		ptr = ft_strdup("");
		return (ptr);
	}
	i = start;
	cnt = 0;
	while (i < (unsigned int)src_len && cnt < len)
		*(ptr + cnt++) = *(s + i++);
	*(ptr + cnt) = '\0';
	return (ptr);
}

int	main(void)
{
	char			*src[] = {"Hello World", "World", "2Sr7bMuBCUm PkSm7 lyi18C5tNKP7p9J4 MD5rSqNGPp7kynV VpuScEC9 IYL0s LsBMbtR7OEGp1q 5BrnQbN6hpq 2c7QY Arw8W24KJjpSO0yqR RdnsJo1m 29R1UCva65ypZ qjQ2LdZsPVC4NIm OVly1ZPwbgSBXnf stHwez1QCB eLW", ""};
	int				reps = sizeof(src) / sizeof(char *);
	char			*substr;
	unsigned int	start = 7;
	size_t			len = 5;

	for (int i = 0; i < reps; i++)
	{
		substr = ft_substr(*(src + i), start, len);
		printf("src    :%s, start: %d, len: %zu\n", *(src + i), start, len);
		printf("substr :%s\n\n", substr);
	}
		return (0);
}

