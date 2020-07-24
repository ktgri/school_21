/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahi <bmahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 19:01:11 by bmahi             #+#    #+#             */
/*   Updated: 2019/07/21 19:01:50 by bmahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_pxl(t_fdf *fdf, int x, int y, int color)
{
	if (x < 0 || x >= WGHT || y < 0 || y >= HGHT)
		return ;
	*(int*)(fdf->pointer_adr + ((x + y * WGHT) * fdf->bpp)) = color;
}

int		borderline(t_fdf *fdf, t_tmp *tmp, t_pixel *pxl1, t_pixel *pxl2)
{
	double proc;

	if (pxl1->x < 0 || pxl1->x >= WGHT || pxl1->y < 0 || pxl1->y >= HGHT
	|| pxl2->x < 0 || pxl2->x >= WGHT || pxl2->y < 0 || pxl2->y >= HGHT)
		return (1);
	proc = (tmp->dx > tmp->dy ? \
		ft_ilerp((int)pxl1->x, (int)tmp->start.x, (int)tmp->stop.x) \
		: ft_ilerp((int)pxl1->y, (int)tmp->start.y, (int)tmp->stop.y));
	set_pxl(fdf, (int)pxl1->x, (int)pxl1->y, clerp(pxl1->color, \
		pxl2->color, proc));
	tmp->err2 = tmp->err1;
	if (tmp->err2 > -tmp->dx)
	{
		tmp->err1 -= tmp->dy;
		pxl1->x += tmp->sx;
	}
	if (tmp->err2 < tmp->dy)
	{
		tmp->err1 += tmp->dx;
		pxl1->y += tmp->sy;
	}
	return (0);
}

void	alter(t_pixel *tmp, t_pixel *pxl1, t_pixel *pxl2, int shape)
{
	if (shape & 1)
	{
		tmp->x = pxl1->x + \
			(pxl2->x - pxl1->x) * (HGHT - pxl1->y) / (pxl2->y - pxl1->y);
		tmp->y = HGHT - 1;
	}
	else if (shape & 2)
	{
		tmp->x = pxl1->x + (pxl2->x - pxl1->x) * -pxl1->y / (pxl2->y - pxl1->y);
		tmp->y = 0;
	}
	else if (shape & 4)
	{
		tmp->x = WGHT - 1;
		tmp->y = pxl1->y + \
			(pxl2->y - pxl1->y) * (WGHT - pxl1->x) / (pxl2->x - pxl1->x);
	}
	else
	{
		tmp->x = 0;
		tmp->y = pxl1->y + (pxl2->y - pxl1->y) * -pxl1->x / (pxl2->x - pxl1->x);
	}
}

int		place(int x, int y)
{
	int tmp;

	tmp = 0;
	if (y >= HGHT)
		tmp |= 1;
	else if (y < 0)
		tmp |= 2;
	if (x >= WGHT)
		tmp |= 4;
	else if (x < 0)
		tmp |= 8;
	return (tmp);
}
