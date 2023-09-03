/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:52:29 by orudek            #+#    #+#             */
/*   Updated: 2023/08/24 14:29:09 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "so_long.h"
#include "map.h"
#include <unistd.h>
#include <stdio.h>

int	ft_onkeydown(int key, t_game *game)
{
	if (!game->player)
		return (0);
	if (key == W_KEY)
		ft_game_move_player(game, 0, -1);
	if (key == A_KEY)
		ft_game_move_player(game, -1, 0);
	if (key == S_KEY)
		ft_game_move_player(game, 0, 1);
	if (key == D_KEY)
		ft_game_move_player(game, 1, 0);
	if (key == ESC_KEY)
		ft_game_exit(game, 0);
	return (1);
}

int	update(t_game *game)
{
	ft_game_upd_obj(game);
	ft_game_upd_exit(game);
	ft_game_display(game);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_msg_err(ERR_BAD_ARGC, 1));
	ft_game_init(&game);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (ft_msg_err(ERR_WINDOW, 1));
	game.win = mlx_new_window(game.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, NAME);
	if (!ft_game_load_map(&game, argv[1]))
		ft_game_exit(&game, 1);
	if (!ft_game_load_sprites(&game))
		ft_game_exit(&game, 1);
	if (!ft_game_load_objs(&game))
		ft_game_exit(&game, 1);
	mlx_hook(game.win, ON_DESTROY, 0, ft_game_exit, &game);
	mlx_hook(game.win, ON_KEYDOWN, 1L << 0, ft_onkeydown, &game);
	mlx_loop_hook(game.mlx, update, &game);
	mlx_loop(game.mlx);
}
