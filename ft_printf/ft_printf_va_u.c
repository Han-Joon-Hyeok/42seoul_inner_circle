/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_va_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:27:28 by joonhan           #+#    #+#             */
/*   Updated: 2022/06/22 15:29:25 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_printf_recursive_va_u(unsigned int n, size_t *ret_len)
{
	char	c;

	if (n == 0)
		return ;
	ft_printf_recursive_va_u(n / 10, ret_len);
	c = (n % 10) + '0';
	write(1, &c, 1);
	*ret_len += 1;
}

void	ft_printf_va_u(unsigned int n, size_t *ret_len)
{
	if (n == 0)
	{
		write(1, "0", 1);
		*ret_len += 1;
		return ;
	}
	ft_printf_recursive_va_u(n, ret_len);
}
