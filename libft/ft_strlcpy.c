/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:38:51 by joonhan           #+#    #+#             */
/*   Updated: 2022/03/30 15:15:51 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char	*dest, const char	*src, size_t destsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	while ((i + 1) < destsize && *(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i += 1;
	}
	if (i < destsize)
		*(dest + i) = '\0';
	return (src_len);
}
