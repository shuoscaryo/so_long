/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:23:20 by orudek            #+#    #+#             */
/*   Updated: 2023/08/23 18:04:59 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

static void	ft_sprites_free(void *mlx, t_list *sprites)
{
	t_list	*aux;

	while (sprites)
	{
		aux = sprites->next;
		ft_img_free(mlx, (t_img **)&(sprites->content));
		free(sprites);
		sprites = aux;
	}
}

static void	ft_obj_lst_free(void *mlx, t_list *objs)
{
	t_list	*aux;

	while (objs)
	{
		aux = objs->next;
		ft_obj_free(mlx, (t_obj **)&(objs->content));
		free(objs);
		objs = aux;
	}
}

int	ft_game_exit(t_game *game, int status)
{
	if (game->map)
		ft_array_free(game->map);
	if (game->sprites)
		ft_sprites_free(game->mlx, game->sprites);
	if (game->player)
		ft_obj_free(game->mlx, &game->player);
	if (game->tiles)
		ft_obj_lst_free(game->mlx, game->tiles);
	if (game->objects)
		ft_obj_lst_free(game->mlx, game->objects);
	if (game->exit)
		ft_obj_free(game->mlx, &game->exit);
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	exit(status);
}
