/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_img.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 19:36:22 by orudek            #+#    #+#             */
/*   Updated: 2023/08/23 18:09:21 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_IMG_H
# define T_IMG_H

/*	t_img is a struct that handles the images added to the window of minilibx
		-filename: variable contains the name of the file used to load the
			image.
		-img: where the image created by minilibx is stored.
		-addr: String with the pixels of the image. Every pixel is 4 bytes, and
			the length of addr is width * length of the image.
		-bits_per_pixel: How much bits a pixel of the img needs to store all
			its data. (the same 4 bytes as in the addr part)
		-size_line: variable used to put pixels on the img.
		-endian: marks the endianness of the pixels information.
		-height: indicates the vertical length of the image.
		-width indicates the horizontal length of the image.
*/
typedef struct s_img
{
	char	*filename;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		height;
	int		width;
}	t_img;

//creates a new image from a file
t_img	*ft_img_new(void *mlx, char *filename, int width, int height);

//creates a new image from a reference image scaled to the specified dimensions
t_img	*ft_img_new2(void *mlx, t_img *img, int width, int height);

//modifies the size of the image passed to the specified dimensions
char	ft_img_resize(void *mlx, t_img *img, int width, int height);

//deallocates all the memory of the pointers of the img and sets the mto NULL
char	ft_img_free(void *mlx, t_img **img);

#endif