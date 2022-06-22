/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:59:36 by joonhan           #+#    #+#             */
/*   Updated: 2022/06/22 16:27:23 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

void		ft_putnbr_fd(int n, int fd, size_t *ret_len);
void		ft_putstr_fd(char *s, int fd, size_t *ret_len);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *s);

#endif
