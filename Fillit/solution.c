/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorie <kcorie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 20:08:50 by kcorie            #+#    #+#             */
/*   Updated: 2019/06/04 18:17:56 by kcorie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int		sqqqr(int n)
{
	int	a;

	a = 2;
	while (a * a < n)
		a++;
	return (a);
}

static	t_map	*map_empty(int size)
{
	t_map	*empty;
	int		x;
	int		y;

	empty = (t_map *)ft_memalloc(sizeof(t_map));
	empty->size_map = size;
	empty->matrix = (char **)ft_memalloc(sizeof(char *) * size);
	x = 0;
	while (x < size)
	{
		empty->matrix[x] = ft_strnew(size);
		y = 0;
		while (y < size)
		{
			empty->matrix[x][y] = '.';
			y++;
		}
		x++;
	}
	return (empty);
}

t_map			*solution(t_list *list)
{
	t_map	*map;
	int		size;

	size = sqqqr(ft_lstcount(list) * 4);
	map = map_empty(size);
	while (!feel_it(map, list))
	{
		size++;
		free_map(map);
		map = map_empty(size);
	}
	return (map);
}
