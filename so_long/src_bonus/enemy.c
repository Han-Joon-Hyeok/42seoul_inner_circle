/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:06:01 by joonhan           #+#    #+#             */
/*   Updated: 2022/09/01 17:45:52 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

void	init_enemy(t_game *game)
{
	t_enemy	*enemy_component;

	enemy_component = malloc(sizeof(t_enemy));
	if (enemy_component == NULL)
		return ;
	enemy_component->count = 0;
	enemy_component->head = NULL;
	enemy_component->tail = NULL;
	game->enemy_component = enemy_component;
}
