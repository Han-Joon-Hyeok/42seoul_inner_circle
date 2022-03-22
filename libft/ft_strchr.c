/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:26:30 by joonhan           #+#    #+#             */
/*   Updated: 2022/03/22 18:32:28 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

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
	}

	printf("\n\n✅ src2: %s\n\n", src2);
	for (int i = 0; i < 6; i++)
	{
		int c = *(search + i);
		printf("c: %c, strchr: %p\n", c, strchr(src2, c));
	}
	return (0);
}
