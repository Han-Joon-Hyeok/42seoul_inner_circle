/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:55:03 by joonhan           #+#    #+#             */
/*   Updated: 2022/03/28 16:57:17 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	void	*ptr;

	total = count * size;
	ptr = (void *)malloc(total);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}

// int	main(void)
// {
// 	int	*ptr;
// 	int	*ft_ptr;
// 	size_t	size = 2;
// 	size_t	size_of = sizeof(double);

// 	ptr = calloc(size, size_of);
// 	ft_ptr = ft_calloc(size, size_of);
// 	for (int i = 0; i < size; i++)
// 	{
// 		printf("i: %d, ptr   : %d, address: %p\n", i, *(ptr + i), (ptr + i));
// 		printf("i: %d, ft_ptr: %d, address: %p\n\n", i, *(ft_ptr + i), (ft_ptr + i));
// 	}
// 	return (0);
// }
