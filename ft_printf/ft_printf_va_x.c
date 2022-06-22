/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_va_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:27:28 by joonhan           #+#    #+#             */
/*   Updated: 2022/06/22 15:29:16 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_printf_recursive_va_x(unsigned int n, char c, size_t *ret_len)
{
	char	*hex;

	if (c == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n == 0)
		return ;
	ft_printf_recursive_va_x(n / 16, c, ret_len);
	write(1, &hex[n % 16], 1);
	*ret_len += 1;
}

void	ft_printf_va_x(unsigned int n, char c, size_t *ret_len)
{
	if (n == 0)
	{
		write(1, "0", 1);
		*ret_len += 1;
		return ;
	}
	ft_printf_recursive_va_x(n, c, ret_len);
}
