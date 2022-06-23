/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:26:20 by joonhan           #+#    #+#             */
/*   Updated: 2022/06/22 16:26:40 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_args(char format, size_t *idx, size_t *ret, va_list ap)
{
	if (format == 'c')
		ft_printf_va_c((char)va_arg(ap, int), ret);
	else if (format == 's')
		ft_printf_va_s((char *)va_arg(ap, int *), ret);
	else if (format == 'p')
		ft_printf_va_p((void *)va_arg(ap, void *), ret);
	else if (format == 'd' || format == 'i')
		ft_printf_va_d((int)va_arg(ap, int), ret);
	else if (format == 'u')
		ft_printf_va_u((unsigned int)va_arg(ap, unsigned int), ret);
	else if (format == 'x')
		ft_printf_va_x((unsigned int)va_arg(ap, unsigned int), 'x', ret);
	else if (format == 'X')
		ft_printf_va_x((unsigned int)va_arg(ap, unsigned int), 'X', ret);
	else if (format == '%')
	{
		write(1, "%", 1);
		*ret += 1;
	}
	*idx += 2;
}

int	ft_printf(const char *str, ...)
{
	size_t	idx;
	size_t	str_len;
	size_t	ret_len;
	va_list	ap;

	idx = 0;
	str_len = ft_strlen(str);
	ret_len = 0;
	va_start(ap, str);
	while (idx < str_len && str[idx] != '\0')
	{
		if ((str[idx] == '%') && ft_strchr("cspdiuxX%", str[idx + 1]))
			ft_printf_args(str[idx + 1], &idx, &ret_len, ap);
		else
		{
			write(1, &str[idx++], 1);
			ret_len += 1;
		}
	}
	va_end(ap);
	return ((int)ret_len);
}
