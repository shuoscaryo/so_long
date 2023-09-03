/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_new2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:11:42 by orudek            #+#    #+#             */
/*   Updated: 2023/08/13 21:07:05 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_img.h"
#include "mlx.h"
#include <stdlib.h>
#include "libft.h"

void	ft_img_pixel_put(t_img *img, int x, int y, int color);
int		ft_img_get_pixel(t_img img, int x, int y);

static char	ft_set_filename(t_img *img, const char *filename)
{
	img->filename = ft_strdup(filename);
	if (!(img->filename))
		return (0);
	return (1);
}

static char	ft_malloc_img(t_img **img)
{
	*img = malloc(sizeof(t_img));
	if (!(*img))
		return (0);
	(*img)->filename = NULL;
	(*img)->img = NULL;
	(*img)->addr = NULL;
	return (1);
}

static void	ft_scale_pixels(t_img *new_img, t_img img, int width, int height)
{
	int	i;
	int	j;

	j = -1;
	while (++j < height)
	{
		i = -1;
		while (++i < width)
			ft_img_pixel_put(new_img, i, j, ft_img_get_pixel(img,
					(int)((float)i / width * img.width),
					(int)((float)j / height * img.height)));
	}
}

static void	ft_set_dimensions(t_img *new_img, const t_img img, int w, int h)
{
	if (w <= 0 && h <= 0)
	{
		new_img->height = img.height;
		new_img->width = img.width;
	}
	else if (h <= 0)
	{
		new_img->height = (int)((float)img.height / img.width * w);
		new_img->width = w;
	}
	else if (w <= 0)
	{
		new_img->height = h;
		new_img->width = (int)((float)img.width / img.height * h);
	}
	else
	{
		new_img->height = h;
		new_img->width = w;
	}
}

t_img	*ft_img_new2(void *mlx, t_img *img, int width, int height)
{
	t_img	*new_img;

	if (!img || !ft_malloc_img(&new_img))
		return (NULL);
	if (!ft_set_filename(new_img, img->filename))
		return ((void *)(long)ft_img_free(mlx, &new_img));
	ft_set_dimensions(new_img, *img, width, height);
	new_img->img = mlx_new_image(mlx, new_img->width, new_img->height);
	if (!new_img->img)
		return ((void *)(long)ft_img_free(mlx, &new_img));
	new_img->addr = mlx_get_data_addr(new_img->img, &new_img->bits_per_pixel,
			&new_img->size_line, &new_img->endian);
	ft_scale_pixels(new_img, *img, width, height);
	return (new_img);
}
