/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:33:01 by joonhan           #+#    #+#             */
/*   Updated: 2022/09/02 20:02:06 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

void	init_collect_lst(t_game *game)
{
	t_collect		*collect_lst;

	collect_lst = malloc(sizeof(t_collect));
	if (collect_lst == NULL)
		return ;
	collect_lst->count = 0;
	collect_lst->head = NULL;
	collect_lst->tail = NULL;
	game->collect_lst = collect_lst;
}

void	create_collect_node(t_game *game, size_t idx)
{
	t_collect_node	*new_node;

	new_node = malloc(sizeof(t_collect_node));
	if (new_node == NULL)
		return ;
	new_node->idx = idx;
	new_node->next = NULL;
	if (game->collect_lst->count == 0)
	{
		game->collect_lst->head = new_node;
		game->collect_lst->tail = new_node;
	}
	else
	{
		game->collect_lst->tail->next = new_node;
		game->collect_lst->tail = new_node;
	}
	game->collect_lst->count += 1;
}

void	free_collect(t_game *game, size_t idx)
{
	t_collect_node	*prev;
	t_collect_node	*curr;

	prev = NULL;
	curr = game->collect_lst->head;
	while (curr->idx != idx)
	{
		prev = curr;
		curr = curr->next;
	}
	if (prev == NULL)
	{
		game->collect_lst->head = NULL;
		game->collect_lst->tail = NULL;
	}
	else if (curr->next == NULL)
	{
		prev->next = NULL;
		game->collect_lst->tail = prev;
	}
	else
		prev->next = curr->next;
	free(curr);
	game->collect_lst->count -= 1;
}

void	draw_collect(t_game *game)
{
	size_t			count;
	size_t			height;
	t_collect_node	*curr;

	curr = game->collect_lst->head;
	while (curr != NULL)
	{
		height = (curr->idx) / game->map_width;
		count = (curr->idx) % game->map_width;
		ft_put_image_to_16(game, game->collectible, count, height);
		curr = curr->next;
	}
}
