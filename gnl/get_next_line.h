/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:36:55 by joonhan           #+#    #+#             */
/*   Updated: 2022/06/13 13:08:29 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
    int				fd;
    char            *backup;
    char			buf[BUFFER_SIZE];
	struct s_node	*next;
}	t_node;

char	*get_next_line(int fd);
size_t	ft_strlen(char const *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(char *s1, char *s2);

#endif

#ifndef _COMMON_GNL_DEF_
# define _COMMON_GNL_DEF_

# define TRUE   1
# define FALSE  -1

#endif