/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:19:51 by orudek            #+#    #+#             */
/*   Updated: 2023/08/19 15:47:03 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_obj.h"
#include <stdlib.h>

char	ft_obj_free(void *mlx, t_obj **obj)
{
	if (!(*obj)->img_ref && (*obj)->sprite)
		ft_img_free(mlx, &(*obj)->sprite);
	free (*obj);
	*obj = (void *)0;
	return (0);
}
