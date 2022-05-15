/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:36:55 by joonhan           #+#    #+#             */
/*   Updated: 2022/05/15 20:59:19 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_find
{
    int index;
    int found;
}   t_find;
typedef struct s_node
{
    int				fd;
    char			*backup;
	struct s_node	*next;
}	t_node;

typedef struct s_list
{
    t_node	*header;
}   t_list;

char	*get_next_line(int fd);
size_t	ft_strlen(const	char *s);
char	*ft_strdup(const char *src);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);

#endif

#ifndef _COMMON_GNL_DEF_
# define _COMMON_GNL_DEF_

# define TRUE   1
# define FALSE  0

#endif