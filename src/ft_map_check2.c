/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 23:36:31 by orudek            #+#    #+#             */
/*   Updated: 2023/08/23 17:06:26 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "stdlib.h"
#include "libft.h"

/*	ft_find_char
		1 -	searches the whole map until the character is found
		2 -	if it's found and x and y are not NULL, the position is saved and
			returns 1. if x or y are NULL, only returns 1
		3 - if the character has not been found returns 0
*/
static char	ft_find_char(char **map, char c, int *x, int *y)
{
	int	i;
	int	j;

	j = -1;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
		{
			if (map[j][i] == c)
			{
				if (x && y)
				{
					*x = i;
					*y = j;
				}
				return (1);
			}
		}
	}
	return (0);
}

static char	ft_is_walkable(char c)
{
	if (c == FLOOR || c == OBJECT || c == PLAYER)
		return (1);
	return (0);
}

static char	ft_exit_func(char *msg, char **map)
{
	ft_array_free(map);
	return (ft_msg_err(msg, 0));
}

/*	ft_map_mark_path
		1 -	The function starts from the x and y coordinates given
		2 - Replaces the tile in the position x,y to the character selected
		3 - Looks at the adjacent tiles and if any is a walkable tile, calls
			itself but with the selected tile coordinates
			*	The priority is trying to go left, then up, right and down
*/
static void	ft_map_mark_path(char **map, int x, int y, char c)
{
	if (ft_is_walkable(map[y][x]))
		map[y][x] = c;
	if (x != 0 && ft_is_walkable(map[y][x - 1]))
		ft_map_mark_path(map, x - 1, y, c);
	if (y != 0 && ft_is_walkable(map[y - 1][x]))
		ft_map_mark_path(map, x, y - 1, c);
	if (ft_is_walkable(map[y][x + 1]))
		ft_map_mark_path(map, x + 1, y, c);
	if (map[y + 1] != NULL && ft_is_walkable(map[y + 1][x]))
		ft_map_mark_path(map, x, y + 1, c);
}

/*	ft_check_valid_path
		1 -	copies input map into another variable
			*	the copy function already tests for NULL arrays
		2 -	tries to find the player, saving the coordinates on the pos variable
			*	pos[0]: x
			*	pos[1]: y
		3 -	calls the recursive function to find the EXIT that will mark all
			reachable tiles and objects with an X. it wont mark the exit
		4 -	tries to find an object in the map. If any object is found, it
			means that it is not reachable because it hasn't been marked with X
		5 -	Tries to find the EXIT and saves the coordinates
		6 -	Looks at left, top, right, down positions and if any is an X
			returns 1. otherwise it returns 0
			*	LEFT: if x is zero it won't search the left tile
			*	UP: if y is zero it won't search the upper tile
			*	RIGHT: no condition needed because if it is at the right of the
				map, the next tile is always '\0'
			*	DOWN: if the next line of the map is NULL it won't searh the
				bottom tile
		7 -	The aux map is freed before exiting the function as it is not
			needed
*/
char	ft_check_valid_path(char **map)
{
	char	**aux_map;
	int		pos[2];

	aux_map = ft_array_cp(map);
	if (!aux_map)
		return (ft_msg_err(ERR_MALLOC, 0));
	if (!ft_find_char(aux_map, PLAYER, &(pos[0]), &(pos[1])))
		return (ft_exit_func(ERR_NO_PLAYER, aux_map));
	ft_map_mark_path(aux_map, pos[0], pos[1], 'X');
	if (ft_find_char(aux_map, OBJECT, NULL, NULL))
		return (ft_exit_func(ERR_OBJ_NO_REACH, aux_map));
	if (!ft_find_char(aux_map, EXIT, &(pos[0]), &(pos[1])))
		return (ft_exit_func(ERR_NO_EXIT, aux_map));
	if ((pos[0] != 0 && aux_map[pos[1]][pos[0] - 1] == 'X')
		|| (pos[1] != 0 && aux_map[pos[1] - 1][pos[0]] == 'X')
		|| (aux_map[pos[1]][pos[0] + 1] == 'X')
		|| (aux_map[pos[1] + 1] != NULL && aux_map[pos[1] + 1][pos[0]] == 'X'))
	{
		ft_array_free(aux_map);
		return (1);
	}
	return (ft_msg_err(ERR_NO_PATH, 0));
}
