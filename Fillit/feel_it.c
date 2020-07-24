/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feel_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorie <kcorie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 20:15:21 by kcorie            #+#    #+#             */
/*   Updated: 2019/06/04 17:54:46 by kcorie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	void	add_sym(t_figure *figure, t_map *map,\
	t_coordinate *coordinate, char sym)
{
	int		q;
	int		z;

	q = 0;
	while (q < figure->w)
	{
		z = 0;
		while (z < figure->h)
		{
			if (figure->piece[z][q] == '#')
				map->matrix[coordinate->y + z][coordinate->x + q] = sym;
			z++;
		}
		q++;
	}
	ft_memdel((void **)&coordinate);
}

static	int		place(t_figure *figure, t_map *map, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < figure->w)
	{
		j = 0;
		while (j < figure->h)
		{
			if (figure->piece[j][i] == '#' && map->matrix[y + j][x + i] != '.')
				return (0);
			j++;
		}
		i++;
	}
	add_sym(figure, map, new_coordinate(x, y), figure->sym);
	return (1);
}

int				feel_it(t_map *map, t_list *list)
{
	t_figure	*felt;
	int			x;
	int			y;

	if (list == NULL)
		return (1);
	y = 0;
	felt = (t_figure *)(list->content);
	while (y < map->size_map - felt->h + 1)
	{
		x = 0;
		while (x < map->size_map - felt->w + 1)
		{
			if (place(felt, map, x, y) == 1)
			{
				if (feel_it(map, list->next))
					return (1);
				else
					add_sym(felt, map, new_coordinate(x, y), '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}
