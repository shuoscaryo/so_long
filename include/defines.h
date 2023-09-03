/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:14:34 by orudek            #+#    #+#             */
/*   Updated: 2023/08/24 21:42:39 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

enum {
	PLAYER = 'P',
	OBJECT = 'C',
	EXIT = 'E',
	WALL = '1',
	FLOOR = '0'
};

# define NAME "So Long"
# define TILE_LEN 50
# define WINDOW_WIDTH  1000
# define WINDOW_HEIGHT 600

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

/* linux */
enum {
	W_KEY = 119,
	A_KEY = 97,
	S_KEY = 115,
	D_KEY = 100,
	ESC_KEY = 65307
};

/* mac
enum {
	W_KEY = 13,
	A_KEY = 0,
	S_KEY = 1,
	D_KEY = 2,
	ESC_KEY = 53
};
*/
# define PLAYER_SPRITE_FRONT "textures/player_front.xpm"
# define PLAYER_SPRITE_BACK "textures/player_back.xpm"
# define PLAYER_SPRITE_LEFT "textures/player_left.xpm"
# define PLAYER_SPRITE_RIGHT "textures/player_right.xpm"
# define FLOOR_SPRITE "textures/floor.xpm"
# define WALL_SPRITE "textures/wall.xpm"
# define OBJECT_SPRITE "textures/apple.xpm"
# define EXIT_SPRITE "textures/exit.xpm"

# define ERR_BAD_ARGC "Incorrect number of parameters"
# define ERR_MAP_NAME "Map doesn't end with .ber"
# define ERR_GET_MAP "Couldn't get map"
# define ERR_MALLOC "Couldn't allocate memory"
# define ERR_NO_PLAYER	"No player found in the map"
# define ERR_OBJ_NO_REACH "Can't reach all objects"
# define ERR_NO_EXIT "No exit found in the map"
# define ERR_NO_PATH "No path between player and exit"
# define ERR_SQUARE "Map is not square"
# define ERR_CHARS "Map doesn't have correct characters"
# define ERR_ENCLOSE "Map is not enclosed"
# define ERR_LOAD_IMG "Couldn't load images"
# define ERR_LOAD_OBJ "Couldn't load objects"
# define ERR_WINDOW "Couldn't create window"
#endif