/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahi <bmahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 18:52:57 by bmahi             #+#    #+#             */
/*   Updated: 2019/07/21 19:04:07 by bmahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_point(char ***splt)
{
	int n;

	n = 0;
	while ((*splt)[n])
		free((*splt)[n++]);
	free((*splt));
}

t_pixel	*pixel_solve(int x, int y, char *splt)
{
	t_pixel *pxl;

	if (!(pxl = (t_pixel*)malloc(sizeof(t_pixel))))
		error("error");
	pxl->x = (double)x;
	pxl->y = (double)y;
	pxl->z = (double)atoi(splt);
	pxl->color = 0x8b0000;
	return (pxl);
}

void	pixel(t_list **list, t_map **map)
{
	int		x;
	int		y;
	char	**splt;
	t_list	*lst;

	lst = (*list);
	y = 0;
	while (y < (*map)->h)
	{
		x = 0;
		if (!(splt = ft_strsplit(lst->content, ' ')))
			error("error");
		while (x < (*map)->w)
		{
			(*map)->pixel[y * (*map)->w + x] = pixel_solve(x, y, splt[x]);
			x++;
		}
		free_point(&splt);
		lst = lst->next;
		y++;
	}
}

t_map	*map_solve(size_t x, size_t y)
{
	t_map *map;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		error("error");
	map->w = (int)x;
	map->h = (int)y;
	map->deepmax = INT_MAX;
	map->deepmin = INT_MIN;
	if (!(map->pixel = (t_pixel**)malloc(sizeof(t_pixel*) * (int)x * (int)y)))
		error("error");
	return (map);
}

int		reader_map(int fd, t_map **map, t_list **list)
{
	int		i;
	int		ret;
	char	*line;
	t_list	*tmp;

	i = 0;
	while ((ret = (get_next_line(fd, &line))) == 1)
	{
		if (i == 0)
			i = ft_ispoint(line, ' ');
		if (!(tmp = ft_lstnew(line, ft_strlen(line) + 1)))
			error("error");
		ft_lstadd(list, tmp);
		if (i != (int)ft_ispoint(line, ' '))
			return (0);
		free(line);
	}
	if (i == 0 || ret == -1)
		return (0);
	ft_lstrev(list);
	(*map) = map_solve(i, ft_lstcount((*list)));
	pixel(list, map);
	search_maxmin(*map);
	search_color((*map), FIRST_COL, SECOND_COL);
	return (1);
}
