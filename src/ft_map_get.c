/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:51:14 by orudek            #+#    #+#             */
/*   Updated: 2023/08/23 18:06:15 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "libft.h"
#include "so_long.h"

char	ft_str_ends_with(const char *filename, const char *str)
{
	int	i;
	int	j;

	i = ft_strlen(filename) - 1;
	j = ft_strlen(str) - 1;
	while (i >= 0 && j >= 0)
	{
		if (filename[i--] != str[j--])
			return (0);
	}
	return (1);
}

static void	ft_free_list(t_list *list)
{
	t_list	*aux;

	while (list)
	{
		aux = list->next;
		free (list->content);
		free (list);
		list = aux;
	}
}

static void	ft_rm_new_lines(char **map)
{
	int	i;

	i = 0;
	while (*map)
	{
		i = 0;
		while ((*map)[i])
		{
			if ((*map)[i] == '\n')
				(*map)[i] = 0;
			i++;
		}
		map++;
	}
}

char	**ft_lst_to_array(t_list *list)
{
	int		i;
	char	**array;

	array = malloc(sizeof(char *) * (ft_lstsize(list) + 1));
	if (!array)
		return (NULL);
	i = -1;
	while (++i < ft_lstsize(list))
	{
		array[i] = ft_strdup((char *)ft_lstget_val(list, i));
		if (!array[i])
			return ((char **)ft_array_free(array));
	}
	array[i] = NULL;
	ft_rm_new_lines(array);
	return (array);
}

/*	ft_map_get: saves the map from a file inside an array
		1 - Check if filename ends with .ber
		2 - Try to open the file
		3 - Save every string returned from gnl into a linked list
			*	ft_lstadd_back_content creates a new t_list element, saves the
				str value provided and adds it at the end of the list
		4 -	closes file when done reading from it
		5 -	Creates an array and stores the lines from the list in it
		6 -	Removes the new line characters from the array
		7 -	frees the list and returns the string
*/
char	**ft_map_get(const char *filename)
{
	int		fd;
	t_list	*list;
	char	**map;

	if (!ft_str_ends_with(filename, ".ber"))
		return ((void *)ft_msg_err(ERR_MAP_NAME, 0));
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return ((void *)ft_msg_perror(filename, 0));
	list = NULL;
	while (ft_lstadd_back_content(&list, get_next_line(fd)))
		;
	close(fd);
	map = ft_lst_to_array(list);
	ft_free_list(list);
	if (!map)
		return ((void *)ft_msg_err(ERR_GET_MAP, 0));
	return (map);
}
