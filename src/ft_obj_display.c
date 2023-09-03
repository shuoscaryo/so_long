/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 21:13:03 by orudek            #+#    #+#             */
/*   Updated: 2023/08/24 19:31:37 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_obj.h"
#include "mlx.h"
#include "defines.h"

void	ft_obj_display(void *mlx, void *win, t_obj *obj, int offset[2])
{
	if (!mlx || !win || !obj)
		return ;
	mlx_put_image_to_window(mlx, win, obj->sprite->img,
		obj->x * TILE_LEN + offset[0], obj->y * TILE_LEN + offset[1]);
}
