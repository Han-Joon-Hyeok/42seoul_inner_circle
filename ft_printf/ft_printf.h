/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:39:36 by joonhan           #+#    #+#             */
/*   Updated: 2022/06/22 15:32:02 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

void	ft_printf_va_c(char c, size_t *ret_len);
void	ft_printf_va_d(int n, size_t *ret_len);
void	ft_printf_va_p(void *p, size_t *ret_len);
void	ft_printf_va_s(char *s, size_t *ret_len);
void	ft_printf_va_u(unsigned int n, size_t *ret_len);
void	ft_printf_va_x(unsigned int n, char c, size_t *ret_len);
int		ft_printf(const char *str, ...);

#endif
