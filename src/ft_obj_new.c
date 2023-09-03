/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:34:30 by orudek            #+#    #+#             */
/*   Updated: 2023/08/17 22:40:29 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_obj.h"
#include <stdlib.h>

t_obj	*ft_obj_new(t_img *img, int img_ref, int x, int y)
{
	t_obj	*new_obj;

	new_obj = malloc(sizeof(t_obj));
	if (!new_obj)
		return (NULL);
	new_obj->sprite = img;
	new_obj->x = x;
	new_obj->y = y;
	new_obj->img_ref = img_ref;
	new_obj->val = 0;
	return (new_obj);
}
