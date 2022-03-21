/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:23:46 by joonhan           #+#    #+#             */
/*   Updated: 2022/03/21 13:50:16 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

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

int	main(void)
{
	char	str[10];
	char	str2[10];

	ft_bzero(str, 10);
	bzero(str2, 10);
	for (int i = 0; i < 5; i++)
	{
		printf("ft_bzero: %d \n", *(str + i));
		printf("bzero: %d \n", *(str2 + i));
	}

	return (0);
}
