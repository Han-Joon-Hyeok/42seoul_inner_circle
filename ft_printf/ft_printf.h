/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:39:36 by joonhan           #+#    #+#             */
/*   Updated: 2022/09/17 10:16:00 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int	ft_printf_va_c(char c);
int	ft_printf_va_d(int n);
int	ft_printf_va_p(void *p);
int	ft_printf_va_s(char *s);
int	ft_printf_va_u(unsigned int n);
int	ft_printf_va_x(unsigned int n, char c);
int	ft_printf(const char *str, ...);

#endif
