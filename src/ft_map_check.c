/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 23:36:15 by orudek            #+#    #+#             */
/*   Updated: 2023/08/24 13:31:17 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "libft.h"

char	ft_check_valid_path(char **map);

/*	ft_map_check_square
		1 -	checks that the input is not NULL
		2 -	saves the length of the first line as reference
		3 - loops through all the lines and if one has different length than
			the first one, returns error
		4 - on success returns 1
*/
static char	ft_map_check_square(char **map)
{
	int		i;
	size_t	map_len;

	if (!map)
		return (ft_msg_err(ERR_MALLOC, 0));
	i = 0;
	map_len = ft_strlen(map[0]);
	while (map[++i])
		if (map_len != ft_strlen(map[i]))
			return (0);
	return (1);
}

/*	ft_map_check_characters
		1 -	checks that the input is not NULL
		2 -	initializes the count variables to 0
			*	count[0]: counter of player characters
			*	count[1]: counter of exit characters
			*	count[2]: counter of object characters
		3 -	Loops all the map
		4 -	Adds 1 to the counters every time the required characters are found
			and if a not allowed character is found, returns error
		5 - Returns a logic operation testing that there is at least 1 object 
			and there is only one exit and player
*/
static char	ft_map_check_characters(char **map)
{
	int	i;
	int	j;
	int	count[3];

	if (!map)
		return (0);
	j = -1;
	ft_bzero(count, sizeof(int) * 3);
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
		{
			if (map [j][i] == OBJECT)
				count[2]++;
			else if (map [j][i] == EXIT)
				count[1]++;
			else if (map [j][i] == PLAYER)
				count[0]++;
			else if (map[j][i] != WALL && map[j][i] != FLOOR)
				return (0);
		}
	}
	return (count[2] > 0 && count[1] == 1 && count[0] == 1);
}

/*	ft_map_check_enclosed
		1 - if the input variable is NULL returns error
		2 - starts a while loop for all the characters of the map
		3 - if positioned at y = 0, x = 0, x = max , y = max and the character
			is not a wall, returns error
		4 -	if everything ok, then return a 1
*/
static char	ft_map_check_enclosed(char **map)
{
	int	i;
	int	j;

	if (!map)
		return (0);
	j = -1;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
			if ((!j || !i || !map[j][i + 1] || !map[j + 1])
				&& map[j][i] != WALL)
				return (0);
	}
	return (1);
}

/*	ft_map_check steps:
		1 -	checks whether the map is a NULL pointer
		2 -	Makes sure the map given has rectangular shape
		3 - Looks at the characters in the map and counts if there is the
			correct amount of players, exits and objects
		4 - Checks if the map is surrounded by walls
		5 - tries to find a path to all objects and the exit. The exit can't
			block the path to objects
*/
char	ft_map_check(char **map)
{
	if (!map)
		return (0);
	if (!ft_map_check_square(map))
		return (ft_msg_err(ERR_SQUARE, 0));
	if (!ft_map_check_characters(map))
		return (ft_msg_err(ERR_CHARS, 0));
	if (!ft_map_check_enclosed(map))
		return (ft_msg_err(ERR_ENCLOSE, 0));
	if (!ft_check_valid_path(map))
		return (0);
	return (1);
}
