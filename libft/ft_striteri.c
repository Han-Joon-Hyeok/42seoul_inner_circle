/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:20:32 by joonhan           #+#    #+#             */
/*   Updated: 2022/03/29 13:34:22 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	size_t			size;

	i = 0;
	size = ft_strlen(s);
	while (*(s + i) != '\0')
	{
		f(i, (s + i));
		i += 1;
	}
}
