/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_load_sprites.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:22:02 by orudek            #+#    #+#             */
/*   Updated: 2023/08/23 17:34:24 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

static char	ft_push_to_list(void *mlx, t_list **list, const char *filename)
{
	t_img	*img;

	img = ft_img_new(mlx, (char *)filename, TILE_LEN, TILE_LEN);
	if (!img)
		return (0);
	if (!ft_lstadd_back_content(list, img))
	{
		ft_img_free(mlx, &img);
		return (0);
	}
	return (1);
}

char	ft_game_load_sprites(t_game *game)
{
	if (!ft_push_to_list(game->mlx, &game->sprites, PLAYER_SPRITE_FRONT))
		return (ft_msg_err(ERR_LOAD_IMG, 0));
	if (!ft_push_to_list(game->mlx, &game->sprites, PLAYER_SPRITE_BACK))
		return (ft_msg_err(ERR_LOAD_IMG, 0));
	if (!ft_push_to_list(game->mlx, &game->sprites, PLAYER_SPRITE_LEFT))
		return (ft_msg_err(ERR_LOAD_IMG, 0));
	if (!ft_push_to_list(game->mlx, &game->sprites, PLAYER_SPRITE_RIGHT))
		return (ft_msg_err(ERR_LOAD_IMG, 0));
	if (!ft_push_to_list(game->mlx, &game->sprites, EXIT_SPRITE))
		return (ft_msg_err(ERR_LOAD_IMG, 0));
	if (!ft_push_to_list(game->mlx, &game->sprites, OBJECT_SPRITE))
		return (ft_msg_err(ERR_LOAD_IMG, 0));
	if (!ft_push_to_list(game->mlx, &game->sprites, WALL_SPRITE))
		return (ft_msg_err(ERR_LOAD_IMG, 0));
	if (!ft_push_to_list(game->mlx, &game->sprites, FLOOR_SPRITE))
		return (ft_msg_err(ERR_LOAD_IMG, 0));
	return (1);
}
