/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:33:18 by joonhan           #+#    #+#             */
/*   Updated: 2022/03/07 20:36:30 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_strlen(const	char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i += 1;
	return (i);
}

int	main(void)
{
	char	str[] = "Hello World";

	printf("str: %s\n", str);
	printf("strlen: %lu\n", strlen(str));
	printf("ft_strlen: %d\n", ft_strlen(str));
	return (0);
}
