/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:26:30 by joonhan           #+#    #+#             */
/*   Updated: 2022/03/23 11:19:00 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stddef.h>

static size_t	ft_strlen(const char *src)
{
	size_t	i;

	i = 0;
	while (*(src + i) != '\0')
		i += 1;
	return (i);
}

char	*ft_strchr(const char *src, int c)
{
	char	temp;
	char	*find;
	size_t	i;
	size_t	src_len;

	temp = (char) c;
	find = NULL;
	i = 0;
	src_len = ft_strlen(src);
	while (i <= src_len)
	{
		if (*(src + i) == temp)
		{
			find = (char *)(src + i);
			break ;
		}
		i += 1;
	}
	return (find);
}

int	main(void)
{
	char src[6] = "abcde";
	char src2[6] = "b\0ade";
	char search[6] = {'a', 'b', 'c', 'd', '\0'};

	printf("✅ src: %s\n\n", src);
	for (int i = 0; i < 6; i++)
	{
		int c = *(search + i);
		printf("c: %c, strchr: %p\n", c, strchr(src, c));
		printf("c: %c, ft_strchr: %p\n\n", c, ft_strchr(src, c));
	}

	printf("\n\n✅ src2: %s\n\n", src2);
	for (int i = 0; i < 6; i++)
	{
		int c = *(search + i);
		printf("c: %c, strchr: %p\n", c, strchr(src2, c));
		printf("c: %c, ft_strchr: %p\n\n", c, ft_strchr(src2, c));
	}
	return (0);
}
