/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:56:13 by joonhan           #+#    #+#             */
/*   Updated: 2022/03/29 10:44:29 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const	char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i += 1;
	return (i);
}

char	*ft_strdup(const char *src)
{
	size_t	i;
	size_t	src_len;
	char	*temp;
	char	*ptr;

	i = 0;
	src_len = ft_strlen(src);
	temp = (char *)src;
	ptr = (char *)malloc((src_len * sizeof(char)) + 1);
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

static int	get_size(int n)
{
	int	i;

	i = 1;
	while (n / 10 != 0)
	{
		i += 1;
		n /= 10;
	}
	return (i);
}

void	ft_bzero(void *dest, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	temp = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		*(temp + i) = 0;
		i += 1;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	void	*ptr;

	total = count * size;
	ptr = (void *)malloc(total);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		sign;
	int		size;

	if (n == 0)
		return (ft_strdup("0"));	
	sign = 1;
	if (n < 0)
		sign = -1;
	size = get_size(n);
	if (n < 0)
		size += 1;
	ptr = (char *)ft_calloc(size + 1, sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (n != 0 && size > 0)
	{
		*(ptr + size - 1) = ((n % 10) * sign) + '0';
		n /= 10;
		size -= 1;
	}
	if (sign < 0)
		*(ptr + size - 1) = '-';
	return (ptr);
}

int	main(void)
{
	int	src[] = {0, 1, -1, 10, -10, 1234, -1234, 2147483647, -2147483648};
	int	size = sizeof(src) / sizeof(int);

	for (int i = 0; i < size; i++)
	{
		printf("src: %d, ft_itoa: %s\n", *(src + i), ft_itoa(*(src + i)));
	}

	return (0);
}

