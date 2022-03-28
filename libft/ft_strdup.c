/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:41:10 by joonhan           #+#    #+#             */
/*   Updated: 2022/03/28 17:08:51 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	i;
	size_t	src_len;
	char	*temp;
	char	*ptr;

	i = 0;
	src_len = ft_strlen(src);
	temp = (char *)src;
	ptr = (char *)malloc((src_len * sizeof(char)) + 1);
	if (ptr == NULL)
		return (NULL);
	while (*(src + i) != '\0')
	{
		*(ptr + i) = *(src + i);
		i += 1;
	}
	*(ptr + i) = '\0';
	return (ptr);
}

// int	main(void)
// {
// 	char	*src = " H l e -20 2!21 \t";
// 	char	*dest;
// 	char	*ft_dest;

// 	dest = strdup(src);
// 	ft_dest = ft_strdup(src);
// 	printf("dest   : %s\n", dest);
// 	printf("ft_dest: %s\n", ft_dest);
// 	return (0);
// }
