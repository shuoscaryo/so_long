/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_move_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:47:33 by orudek            #+#    #+#             */
/*   Updated: 2023/08/24 13:29:04 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	ft_is_wall(t_list *tiles, int x, int y)
{
	while (tiles)
	{
		if (((t_obj *)tiles->content)->x == x
			&& ((t_obj *)tiles->content)->y == y
			&& ((t_obj *)tiles->content)->val == 1)
			return (1);
		tiles = tiles->next;
	}
	return (0);
}

static void	ft_change_sprite(t_game *game, int x, int y)
{
	t_img	*img;

	img = NULL;
	if (y < 0)
		img = ft_find_img(game->sprites, PLAYER_SPRITE_BACK);
	else if (y > 0)
		img = ft_find_img(game->sprites, PLAYER_SPRITE_FRONT);
	else if (x < 0)
		img = ft_find_img(game->sprites, PLAYER_SPRITE_LEFT);
	else if (x > 0)
		img = ft_find_img(game->sprites, PLAYER_SPRITE_RIGHT);
	if (!img)
		return ;
	ft_obj_set_sprite(game->mlx, game->player, img, 1);
}

static char	ft_is_exit_lock(t_obj *exit, int x, int y)
{
	if (exit->x == x && exit->y == y && exit->val == 0)
		return (1);
	return (0);
}

// Tries to move the player one tile of the coordinate specified
void	ft_game_move_player(t_game *game, int x, int y)
{
	if (!game->player)
		return ;
	ft_change_sprite(game, x, y);
	x = (x > 0) - (x < 0);
	y = (y > 0) - (y < 0);
	if (ft_is_wall(game->tiles, game->player->x + x, game->player->y + y))
		return ;
	if (ft_is_exit_lock(game->exit, game->player->x + x, game->player->y + y))
		return ;
	game->player->val++;
	write(1, "moves: ", 7);
	ft_putnbr_fd(game->player->val, 1);
	write(1, "\n", 1);
	ft_obj_add_pos(game->player, x, y);
}
