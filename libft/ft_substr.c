/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:42:34 by joonhan           #+#    #+#             */
/*   Updated: 2022/03/30 15:15:23 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			cnt;
	size_t			src_len;
	char			*ptr;

	if (!s)
		return (NULL);
	ptr = (char *)malloc(sizeof(char) * (src_len + 1));
	if (ptr == NULL)
		return (NULL);
	src_len = ft_strlen(s);
	if (start >= src_len)
	{
		ptr = ft_strdup("");
		return (ptr);
	}
	i = start;
	cnt = 0;
	while (i < (unsigned int)src_len && cnt < len)
		*(ptr + cnt++) = *(s + i++);
	*(ptr + cnt) = '\0';
	return (ptr);
}
