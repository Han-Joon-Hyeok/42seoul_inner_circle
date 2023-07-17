/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:19:51 by joonhan           #+#    #+#             */
/*   Updated: 2023/02/03 13:19:52 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	free_and_return_false(void *arg)
{
	if (arg != NULL)
		free(arg);
	return (FALSE);
}

void	free_args(int count, ...)
{
	va_list	ap;
	void	*ptr;

	if (count <= 0)
		return ;
	va_start(ap, count);
	while (count != 0)
	{
		ptr = (void *)va_arg(ap, void *);
		if (ptr != NULL)
			free(ptr);
		count -= 1;
	}
	va_end(ap);
}
