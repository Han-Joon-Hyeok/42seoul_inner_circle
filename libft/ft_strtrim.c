/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:41:51 by joonhan           #+#    #+#             */
/*   Updated: 2022/03/28 17:13:49 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	front;
	size_t	back;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	front = 0;
	back = ft_strlen(s1);
	while (*(s1 + front) && ft_strchr(set, *(s1 + front)) != NULL)
		front += 1;
	while (*(s1 + back - 1) && ft_strchr(set, *(s1 + back - 1)) != NULL)
	{
		if (back - 1 == 0)
			break ;
		back -= 1;
	}
	if (front > back)
		return (ft_strdup(""));
	ptr = (char *)malloc(sizeof(char) * (back - front + 1));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s1 + front, back - front + 1);
	return (ptr);
}

// int	main(void)
// {
// 	char	*src[] = {"bbbbaabbbb", "i am good man", "am good ma", "  ABC  ", "bbbb"};
// 	char	*set[] = {"a", "good", "ma", " ", "b"};
// 	int		size = sizeof(src) / sizeof(char *);

// 	for (int i = 0; i < size; i++)
// 	{
// 		printf("src: '%s', set: '%s'\n", *(src + i), *(set + i));
// 		printf("ft_strtrim: '%s'\n\n", ft_strtrim(*(src + i), *(set + i)));
// 	}
// 	return (0);
// }
