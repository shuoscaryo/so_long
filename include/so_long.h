/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 21:10:09 by orudek            #+#    #+#             */
/*   Updated: 2023/08/24 18:08:33 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "defines.h"
# include "t_obj.h"
# include "t_img.h"
# include "libft.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		offset[2];
	t_list	*sprites;
	t_obj	*player;
	t_list	*tiles;
	t_list	*objects;
	t_obj	*exit;
}	t_game;

t_img	*ft_find_img(t_list *list, char *filename);
void	ft_game_init(t_game *game);
int		ft_game_exit(t_game *game, int status);
void	ft_game_display(t_game *game);
void	ft_game_upd_obj(t_game *game);
void	ft_game_upd_exit(t_game *game);
char	ft_game_load_sprites(t_game *game);
char	ft_game_load_objs(t_game *game);
char	ft_game_load_map(t_game *game, char *filename);
void	ft_game_move_player(t_game *game, int x, int y);

#endif