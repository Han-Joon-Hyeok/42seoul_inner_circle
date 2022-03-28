/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:54:24 by joonhan           #+#    #+#             */
/*   Updated: 2022/03/28 17:14:55 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

int	ft_tolower(int c)
{
	if (ft_isupper(c))
		return (c + 32);
	else
		return (c);
}

// int	main(void)
// {
// 	int	arr[11] = {-256, -127, -1, 0, 1, 65, 97, 127, 128, 256, 512};
// 	int	size = 11;

// 	printf("✅ Start\n\n");
// 	for (int i = 0; i < size; i++)
// 	{
// 		printf("char: %c, tolower: %d\n", *(arr + i), tolower(*(arr + i)));
// 		printf("char: %c, ft_tolower: %d\n\n", *(arr + i), ft_tolower(*(arr + i)));
// 	}
// 	return (0);
// }
