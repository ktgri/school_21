/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahi <bmahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 18:55:19 by bmahi             #+#    #+#             */
/*   Updated: 2019/07/21 18:56:15 by bmahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_lerpi(int first, int second, double p)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * p));
}

int		clerp(int c1, int c2, double p)
{
	int r;
	int g;
	int b;

	if (c1 == c2)
		return (c1);
	r = ft_lerpi((c1 >> 16) & 0xFF, (c2 >> 16) & 0xFF, p);
	g = ft_lerpi((c1 >> 8) & 0xFF, (c2 >> 8) & 0xFF, p);
	b = ft_lerpi(c1 & 0xFF, c2 & 0xFF, p);
	return (r << 16 | g << 8 | b);
}

double	ft_ilerp(double val, double first, double second)
{
	if (val == first)
		return (0.0);
	if (val == second)
		return (1.0);
	return ((val - first) / (second - first));
}

void	search_color(t_map *map, int col1, int col2)
{
	t_pixel	a;
	t_pixel	*peck;

	a.y = 0;
	while (a.y < map->h)
	{
		a.x = 0;
		while (a.x < map->w)
		{
			peck = map->pixel[(int)a.y * map->w + (int)a.x];
			peck->color = clerp(col1, col2, ft_ilerp(peck->z, \
				map->deepmin, map->deepmax));
			a.x++;
		}
		a.y++;
	}
}

void	search_maxmin(t_map *map)
{
	int x;
	int y;
	int min;
	int max;

	min = INT_MAX;
	max = INT_MIN;
	y = 0;
	while (y < map->h)
	{
		x = 0;
		while (x < map->w)
		{
			if (map->pixel[y * map->w + x]->z < min)
				min = map->pixel[y * map->w + x]->z;
			if (map->pixel[y * map->w + x]->z > max)
				max = map->pixel[y * map->w + x]->z;
			x++;
		}
		y++;
	}
	map->deepmin = min;
	map->deepmax = max;
}
