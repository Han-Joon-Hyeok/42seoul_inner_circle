/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:06:00 by joonhan           #+#    #+#             */
/*   Updated: 2022/03/28 16:54:44 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\r' || c == '\v'
		|| c == '\f' || c == '\t')
		return (1);
	return (0);
}

static int	is_sign_symbol(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

static int	check_sign(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

static int	is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	sign_cnt;
	int	result;

	i = 0;
	sign = 1;
	sign_cnt = 0;
	result = 0;
	while (is_whitespace(*(str + i)))
		i += 1;
	while (is_sign_symbol(*(str + i)))
	{
		if (check_sign(*(str + i)) == -1)
			sign = -1;
		i += 1;
		sign_cnt += 1;
	}
	if (sign_cnt >= 2)
		return (0);
	while (*(str + i) != '\0' && is_numeric(*(str + i)))
		result = (result * 10) + (*(str + i++) - '0');
	return (result * sign);
}

// int	main(void)
// {
// 	char	src[23][12] = {"-2147483647", "-1000","-12a3b", "-1a2b3", "-100", "-10", "-1", "0", "1", "2", "10", "2147483647", "2147483648", "1a2b3", "12a3b", "123ab", " d_$@#-1123", "\t+ 456", " --+--+456", "\r+-4a56", "\f-45b6", "\v+456", "\r \t \f-456"};
// 	size_t	size = sizeof(src) / sizeof(char) / 12;

// 	for (size_t i = 0; i < size; i++)
// 	{
// 		printf("src    : %s\n", *(src + i));
// 		printf("atoi   : %d\n", atoi(*(src + i)));
// 		printf("ft_atoi: %d\n\n", ft_atoi(*(src + i)));
// 	}
// 	return (0);
// }
