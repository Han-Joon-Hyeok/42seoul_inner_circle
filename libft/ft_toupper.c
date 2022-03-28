/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:31:39 by joonhan           #+#    #+#             */
/*   Updated: 2022/03/28 17:15:25 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

int	ft_toupper(int c)
{
	if (ft_islower(c))
		return (c - 32);
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
// 		printf("char: %c, toupper: %d\n", *(arr + i), toupper(*(arr + i)));
// 		printf("char: %c, ft_toupper: %d\n\n", *(arr + i), ft_toupper(*(arr + i)));
// 	}
// 	return (0);
// }
