/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_load_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 23:58:17 by orudek            #+#    #+#             */
/*   Updated: 2023/08/20 13:59:40 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "map.h"

char	ft_game_load_map(t_game *game, char *filename)
{
	game->map = ft_map_get(filename);
	if (!ft_map_check(game->map))
		return (0);
	return (1);
}
