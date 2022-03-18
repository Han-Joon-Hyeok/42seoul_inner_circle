/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:50:59 by joonhan           #+#    #+#             */
/*   Updated: 2022/03/18 17:25:21 by joonhan          ###   ########.fr       */
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
	char	str[20];
	char	str2[20];

	char	*strPtr;
	char	*str2Ptr;

	strPtr = memset(str, 'a', sizeof(str));
	str2Ptr = ft_memset(str2, 'b', sizeof(str2));

	printf("%s\n", strPtr);
	printf("%s\n", str2Ptr);

	return (0);
}
