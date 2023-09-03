/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 23:32:33 by orudek            #+#    #+#             */
/*   Updated: 2023/08/24 18:09:01 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_game_init(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->offset[0] = 0;
	game->offset[1] = 0;
	game->sprites = NULL;
	game->player = NULL;
	game->tiles = NULL;
	game->objects = NULL;
	game->exit = NULL;
}
