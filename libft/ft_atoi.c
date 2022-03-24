/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:06:00 by joonhan           #+#    #+#             */
/*   Updated: 2022/03/24 14:42:00 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

static int	ft_check_sign(const char *str)
{
	if (*(str) == '-')
		return (-1);
	return (1);
}

static int	ft_get_digits(const char *str, int sign)
{
	int	i;

	i = 0;
	if (sign == -1)
		i += 1;
	while (*(str + i) != '\0')
	{
		if (*(str + i) < '0' || *(str + i) > '9')
			break ;
		i += 1;
	}
	if (sign == -1)
		return (i - 1);
	return (i);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	digits;
	int	i;
	int	result;
	int	multiple;

	sign = ft_check_sign(str);
	digits = ft_get_digits(str, sign);
	i = digits;
	if (sign == 1)
		i = digits - 1;
	result = 0;
	multiple = 1;
	while (i >= 0 && *(str + i) != '-')
	{
		result += (*(str + i) - '0') * multiple;
		multiple *= 10;
		i -= 1;
	}
	return (result * sign);
}

int	main(void)
{
	char	src[19][12] = {"-2147483647", "-1000","-12a3b", "-1a2b3", "-100", "-10", "-1", "0", "1", "2", "10", "2147483647", "2147483648", "1a2b3", "12a3b", "123ab", " d_$@#-1123", "abcd", "123-456"};
	size_t	size = sizeof(src) / sizeof(char) / 12;

	for (size_t i = 0; i < size; i++)
	{
		printf("src: %s, atoi: %d\n", *(src + i), atoi(*(src + i)));
		printf("src: %s, ft_atoi: %d\n\n", *(src + i), ft_atoi(*(src + i)));
	}
	return (0);
}
