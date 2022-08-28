/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@studnet.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:23:28 by joonhan           #+#    #+#             */
/*   Updated: 2022/08/28 21:36:52 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_msg(char *msg)
{
	printf("%s\n", msg);
}

void	print_error(char *msg, void *game)
{
	perror(msg);
	strerror(errno);
	if (game != NULL)
	{
		close(((t_game *)game)->fd);
		free(((t_game *)game)->map);
	}
	exit(1);
}
