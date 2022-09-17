/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:59:36 by joonhan           #+#    #+#             */
/*   Updated: 2022/09/17 11:48:39 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *s);

#endif
