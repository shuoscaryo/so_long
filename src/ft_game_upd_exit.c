/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_upd_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:05:00 by orudek            #+#    #+#             */
/*   Updated: 2023/08/19 23:55:53 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_game_upd_exit(t_game *game)
{
	if (!game->player || !game->exit)
		return ;
	if (!game->objects)
		game->exit->val = 1;
	if (game->player->x == game->exit->x && game->player->y == game->exit->y
		&& game->exit->val == 1)
		ft_game_exit(game, 0);
}
