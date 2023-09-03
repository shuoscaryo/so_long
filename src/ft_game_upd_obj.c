/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_upd_obj.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 11:35:36 by orudek            #+#    #+#             */
/*   Updated: 2023/08/19 22:50:36 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_game_upd_obj(t_game *game)
{
	t_obj	*obj;
	t_list	*list[2];

	if (!game->player || !game->objects)
		return ;
	list[1] = NULL;
	list[0] = game->objects;
	while (list[0])
	{
		obj = list[0]->content;
		if (obj && obj->x == game->player->x && obj->y == game->player->y)
		{
			if (list[1])
				list[1]->next = list[0]->next;
			else
				game->objects = list[0]->next;
			ft_obj_free(game->mlx, &obj);
			free(list[0]);
			return ;
		}
		list[1] = list[0];
		list[0] = list[0]->next;
	}
}
