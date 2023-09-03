/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 16:30:19 by orudek            #+#    #+#             */
/*   Updated: 2023/08/13 22:56:33 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_img.h"
#include <stdio.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

void	ft_img_print(t_img *img)
{
	if (!img)
	{
		printf("\x1B[32;1m" "IMG (%p)\n" RESET, img);
		return ;
	}
	printf("\x1B[32;1m" "IMG (%p) content:\n" RESET, img);
	printf(GREEN "\u2523\u2501 " BLUE "filename:\n" RESET);
	printf(GREEN "\u2503  " CYAN "\u251C\u2500\tdir    : " RESET "%p\n", img->filename);
	printf(GREEN "\u2503  " CYAN "\u2514\u2500\tcontent: " RESET "\"%s\"\n",img->filename);
	printf(GREEN "\u2523\u2501 " BLUE "img     : " RESET "%p\n", img->img);
	printf(GREEN "\u2523\u2501 " BLUE "addr    : " RESET "%p\n", img->addr);
	printf(GREEN "\u2523\u2501 " BLUE "bpp     : " RESET "%d\n", img->bits_per_pixel);
	printf(GREEN "\u2523\u2501 " BLUE "lsize   : " RESET "%d\n", img->size_line);
	printf(GREEN "\u2523\u2501 " BLUE "endian  : " RESET "%d\n", img->endian);
	printf(GREEN "\u2523\u2501 " BLUE "height  : " RESET "%d\n", img->height);
	printf(GREEN "\u2517\u2501 " BLUE "width   : " RESET "%d\n", img->width);
}
