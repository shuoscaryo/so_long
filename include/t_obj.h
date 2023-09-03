/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_obj.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:03:03 by orudek            #+#    #+#             */
/*   Updated: 2023/08/11 13:38:16 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_OBJ_H
# define T_OBJ_H
# include "t_img.h"
# include "defines.h"

typedef struct s_obj
{
	int		x;
	int		y;
	int		img_ref;
	t_img	*sprite;
	int		val;
}	t_obj;

t_obj	*ft_obj_new(t_img *img, int img_ref, int x, int y);
void	ft_obj_display(void *mlx, void *win, t_obj *obj, int offset[2]);
char	ft_obj_free(void *mlx, t_obj **object);
void	ft_obj_set_pos(t_obj *object, int x, int y);
void	ft_obj_add_pos(t_obj *object, int x, int y);
void	ft_obj_set_sprite(void *mlx, t_obj *object, t_img *img, int img_ref);

#endif