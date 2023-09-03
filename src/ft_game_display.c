/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:39:10 by orudek            #+#    #+#             */
/*   Updated: 2023/08/24 21:41:32 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	ft_display_list(void *mlx, void *win, t_list *list, int offset[2])
{
	while (list)
	{
		ft_obj_display(mlx, win, (t_obj *)list->content, offset);
		list = list->next;
	}
}

static void	ft_print_filler(t_game *game)
{
	static char	first_time = 1;
	int			i;
	int			j;
	t_img		*img;

	img = ft_find_img(game->sprites, WALL_SPRITE);
	if (!first_time || !img || !game->mlx || !game->win)
		return ;
	j = -1;
	while (++j * TILE_LEN < WINDOW_HEIGHT)
	{
		i = -1;
		while (++i * TILE_LEN < WINDOW_WIDTH)
			mlx_put_image_to_window(game->mlx, game->win, img->img,
				i * TILE_LEN, j * TILE_LEN);
	}
	first_time = 0;
}

static void	ft_set_offset(t_game *game)
{
	int	m_width;
	int	m_height;

	m_height = 0;
	while (game->map[m_height])
		m_height++;
	m_width = ft_strlen(game->map[0]);
	if (m_width * TILE_LEN < WINDOW_WIDTH)
		game->offset[0] = (-m_width * TILE_LEN + WINDOW_WIDTH) / 2;
	else if (game->player->x * TILE_LEN < WINDOW_WIDTH / 2)
		game->offset[0] = 0;
	else if ((m_width - game->player->x) * TILE_LEN < WINDOW_WIDTH / 2)
		game->offset[0] = -m_width * TILE_LEN + WINDOW_WIDTH;
	else
		game->offset[0] = -game->player->x * TILE_LEN + WINDOW_WIDTH / 2;
	if (m_height * TILE_LEN < WINDOW_HEIGHT)
		game->offset[1] = (-m_height * TILE_LEN + WINDOW_HEIGHT) / 2;
	else if (game->player->y * TILE_LEN < WINDOW_HEIGHT / 2)
		game->offset[1] = 0;
	else if ((m_height - game->player->y) * TILE_LEN < WINDOW_HEIGHT / 2)
		game->offset[1] = -m_height * TILE_LEN + WINDOW_HEIGHT;
	else
		game->offset[1] = -game->player->y * TILE_LEN + WINDOW_HEIGHT / 2;
}

void	ft_game_display(t_game *game)
{	
	ft_print_filler(game);
	ft_set_offset(game);
	ft_display_list(game->mlx, game->win, game->tiles, game->offset);
	ft_display_list(game->mlx, game->win, game->objects, game->offset);
	ft_obj_display(game->mlx, game->win, game->player, game->offset);
	ft_obj_display(game->mlx, game->win, game->exit, game->offset);
}
