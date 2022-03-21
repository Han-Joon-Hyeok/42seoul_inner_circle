/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:50:59 by joonhan           #+#    #+#             */
/*   Updated: 2022/03/21 13:14:39 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stddef.h>
#include <stdio.h>

void	*ft_memset(void *ptr, int c, size_t len)
{
	size_t	i;
	unsigned char	*temp;

	i = 0;
	temp = (unsigned char *)ptr;
	while (i < len)
	{
		temp[i] = (unsigned char)c;
		i += 1;
	}
	return (temp);
}

int	main(void)
{
	int	str[20];
	int	str2[20];

	memset(str, -2, sizeof(str));
	ft_memset(str2, -2, sizeof(str2));
	
	for (int i = 0; i < 20; i++)
	{
		printf("str: %d\n", *(str + i));
		printf("str2: %d\n", *(str2 + i));
	}
	return (0);
}
