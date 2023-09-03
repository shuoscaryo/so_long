/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj_set_sprite.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:19:55 by orudek            #+#    #+#             */
/*   Updated: 2023/08/13 23:08:13 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_obj.h"

void	ft_obj_set_sprite(void *mlx, t_obj *obj, t_img *img, int img_ref)
{
	if (!obj)
		return ;
	if (!img_ref)
		ft_img_free(mlx, &obj->sprite);
	obj->sprite = img;
	obj->img_ref = (img_ref > 0);
}
