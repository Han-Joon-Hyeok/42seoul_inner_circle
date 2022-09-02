/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:06:01 by joonhan           #+#    #+#             */
/*   Updated: 2022/09/02 17:17:14 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

void	init_enemy(t_game *game)
{
	t_enemy	*enemy_lst;

	enemy_lst = malloc(sizeof(t_enemy));
	if (enemy_lst == NULL)
		return ;
	enemy_lst->count = 0;
	enemy_lst->head = NULL;
	enemy_lst->tail = NULL;
	game->enemy_lst = enemy_lst;
}

void	free_all_enemy(t_game *game)
{
	t_enemy_node	*curr;
	t_enemy_node	*next;

	curr = game->enemy_lst->head;
	while (curr != NULL)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	free(game->enemy_lst);
}

static void	create_enemy_node(t_game *game, char *curr_addr)
{
	t_enemy_node	*new_enemy;

	new_enemy = malloc(sizeof(t_enemy_node));
	if (new_enemy == NULL)
		return ;
	new_enemy->idx = curr_addr - game->map;
	new_enemy->next = NULL;
	new_enemy->prev = NULL;
	new_enemy->next_dir = 1;
	if (game->enemy_lst->count == 0)
	{
		game->enemy_lst->head = new_enemy;
		game->enemy_lst->tail = new_enemy;
	}
	else
	{
		game->enemy_lst->tail->next = new_enemy;
		new_enemy->prev = game->enemy_lst->tail;
		game->enemy_lst->tail = new_enemy;
	}
	game->enemy_lst->count += 1;
}

void	create_enemy(t_game *game)
{
	char			*current_enemy_addr;

	current_enemy_addr = ft_strchr(game->map, 'F');
	while (current_enemy_addr)
	{
		create_enemy_node(game, current_enemy_addr);
		current_enemy_addr = ft_strchr(current_enemy_addr + 1, 'F');
	}
}
