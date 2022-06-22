/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_va_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:27:28 by joonhan           #+#    #+#             */
/*   Updated: 2022/06/22 15:57:52 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_recursive_hex(size_t addr, size_t *ret_len)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (addr == 0)
		return ;
	print_recursive_hex(addr / 16, ret_len);
	write(1, &hex[addr % 16], 1);
	*ret_len += 1;
}

void	ft_printf_va_p(void *p, size_t *ret_len)
{
	size_t	addr;

	addr = *(size_t *)&p;
	ft_putstr_fd("0x", 1, ret_len);
	if (p == NULL)
		ft_putstr_fd("0", 1, ret_len);
	else
		print_recursive_hex(addr, ret_len);
}
