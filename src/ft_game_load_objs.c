/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_load_objs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 23:51:31 by orudek            #+#    #+#             */
/*   Updated: 2023/08/24 13:28:11 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	ft_new_object(t_game *game, int x, int y, char c)
{
	t_obj	*obj;
	t_img	*img;

	if (c == OBJECT)
		img = ft_find_img(game->sprites, OBJECT_SPRITE);
	else if (c == PLAYER && !game->player)
		img = ft_find_img(game->sprites, PLAYER_SPRITE_FRONT);
	else if (c == EXIT && !game->exit)
		img = ft_find_img(game->sprites, EXIT_SPRITE);
	else
		return (1);
	if (!img)
		return (0);
	obj = ft_obj_new(img, 1, x, y);
	if (!obj)
		return (0);
	if (c == OBJECT)
		if (!ft_lstadd_back_content(&game->objects, obj))
			return (ft_obj_free(game->mlx, &obj));
	if (c == PLAYER)
		game->player = obj;
	if (c == EXIT)
		game->exit = obj;
	return (1);
}

static char	ft_new_tile(t_game *game, int x, int y)
{
	t_obj	*obj;
	t_img	*img;

	if (game->map[y][x] == WALL)
		img = ft_find_img(game->sprites, WALL_SPRITE);
	else
		img = ft_find_img(game->sprites, FLOOR_SPRITE);
	if (!img)
		return (0);
	obj = ft_obj_new(img, 1, x, y);
	if (!obj)
		return (0);
	obj->val = (game->map[y][x] == WALL);
	if (!ft_lstadd_back_content(&game->tiles, obj))
	{
		ft_obj_free(game->mlx, &obj);
		return (0);
	}
	return (1);
}

char	ft_game_load_objs(t_game *game)
{
	int		i;
	int		j;

	j = -1;
	while (game->map[++j])
	{
		i = -1;
		while (game->map[j][++i])
		{
			if (!ft_new_tile(game, i, j))
				return (ft_msg_err(ERR_LOAD_OBJ, 0));
			if (!ft_new_object(game, i, j, game->map[j][i]))
				return (ft_msg_err(ERR_LOAD_OBJ, 0));
		}
	}
	return (1);
}
