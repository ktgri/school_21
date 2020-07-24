/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahi <bmahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 18:58:05 by bmahi             #+#    #+#             */
/*   Updated: 2019/07/21 19:04:06 by bmahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		rotate_line(t_pixel *pxl1, t_pixel *pxl2)
{
	t_pixel	tmp;
	int		spot1;
	int		spot2;
	int		shape;

	spot1 = place(pxl1->x, pxl1->y);
	spot2 = place(pxl2->x, pxl2->y);
	while (!(!(spot1 | spot2) || (spot1 & spot2)))
	{
		shape = spot1 ? spot1 : spot2;
		alter(&tmp, pxl1, pxl2, shape);
		if (shape == spot1)
		{
			pxl1->x = tmp.x;
			pxl1->y = tmp.y;
			spot1 = place(pxl1->x, pxl1->y);
		}
		else
		{
			pxl2->x = tmp.x;
			pxl2->y = tmp.y;
			spot2 = place(pxl2->x, pxl2->y);
		}
	}
	return (!(spot1 | spot2));
}

void	paint_line(t_fdf *fdf, t_pixel pxl1, t_pixel pxl2)
{
	t_tmp	tmp;

	pxl1.x = (int)pxl1.x;
	pxl2.x = (int)pxl2.x;
	pxl1.y = (int)pxl1.y;
	pxl2.y = (int)pxl2.y;
	tmp.start = pxl1;
	tmp.stop = pxl2;
	if (!rotate_line(&pxl1, &pxl2))
		return ;
	tmp.dx = (int)absolute((int)pxl2.x - (int)pxl1.x);
	tmp.sx = (int)pxl1.x < (int)pxl2.x ? 1 : -1;
	tmp.dy = (int)absolute((int)pxl2.y - (int)pxl1.y);
	tmp.sy = (int)pxl1.y < (int)pxl2.y ? 1 : -1;
	tmp.err1 = (tmp.dx > tmp.dy ? tmp.dx : -tmp.dy) / 2;
	while (((int)pxl1.x != (int)pxl2.x || (int)pxl1.y != (int)pxl2.y))
		if (borderline(fdf, &tmp, &pxl1, &pxl2))
			break ;
}

t_pixel	proect_line(t_fdf *fdf, t_pixel pxl1)
{
	t_pixel	pxl2;
	double	x;
	double	y;
	double	z;

	x = pxl1.x;
	z = pxl1.z;
	pxl2.x = cos(fdf->cam->y) * x + sin(fdf->cam->y) * z;
	pxl2.z = -sin(fdf->cam->y) * x + cos(fdf->cam->y) * z;
	y = pxl1.y;
	z = pxl2.z;
	pxl2.y = cos(fdf->cam->x) * y - sin(fdf->cam->x) * z;
	pxl2.z = sin(fdf->cam->x) * y + cos(fdf->cam->x) * z;
	pxl2.color = pxl1.color;
	return (pxl2);
}

t_pixel	proection(t_pixel pxl, t_fdf *fdf)
{
	pxl.x -= (double)(fdf->map->w - 1) / 2.0f;
	pxl.y -= (double)(fdf->map->h - 1) / 2.0f;
	pxl.z -= (double)(fdf->map->deepmin + fdf->map->deepmax) / 2.0f;
	pxl = proect_line(fdf, pxl);
	pxl.x *= fdf->cam->factor;
	pxl.y *= fdf->cam->factor;
	pxl.x += fdf->cam->setx;
	pxl.y += fdf->cam->sety;
	return (pxl);
}

void	paint(t_fdf *fdf, t_map *map)
{
	int		y;
	int		x;

	ft_bzero(fdf->pointer_adr, WGHT * HGHT * fdf->bpp);
	y = 0;
	while (y < map->h)
	{
		x = 0;
		while (x < map->w)
		{
			if (x + 1 < map->w)
				paint_line(fdf, proection(*map->pixel[y * map->w + x], fdf), \
				proection(*map->pixel[y * map->w + x + 1], fdf));
			if (y + 1 < map->h)
				paint_line(fdf, proection(*map->pixel[y * map->w + x], fdf), \
				proection(*map->pixel[(y + 1) * map->w + x], fdf));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
