/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:36:55 by joonhan           #+#    #+#             */
/*   Updated: 2022/05/16 20:02:58 by joonhan          ###   ########.fr       */
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
    char			*buf[BUFFER_SIZE + 1];
	struct s_node	*next;
}	t_node;

char	*get_next_line(int fd);

#endif

#ifndef _COMMON_GNL_DEF_
# define _COMMON_GNL_DEF_

# define TRUE   1
# define FALSE  0

#endif