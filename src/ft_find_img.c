/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 21:26:40 by orudek            #+#    #+#             */
/*   Updated: 2023/08/19 23:57:54 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*ft_find_img(t_list	*list, char *filename)
{
	while (list)
	{
		if (!ft_strcmp(((t_img *)list->content)->filename, filename))
			return (list->content);
		list = list->next;
	}
	return (NULL);
}
