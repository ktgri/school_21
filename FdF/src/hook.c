/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahi <bmahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 19:02:09 by bmahi             #+#    #+#             */
/*   Updated: 2019/07/21 19:04:09 by bmahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	hook_mousemove(int x, int y, t_fdf *fdf)
{
	fdf->mouse->lastx = fdf->mouse->x;
	fdf->mouse->lasty = fdf->mouse->y;
	fdf->mouse->x = x;
	fdf->mouse->y = y;
	if (fdf->mouse->isdown & (1 << 1) && fdf->mouse->isdown & (1 << 2))
	{
		fdf->cam->setx += (x - fdf->mouse->lastx);
		fdf->cam->sety += (y - fdf->mouse->lasty);
	}
	else if (fdf->mouse->isdown & (1 << 1))
	{
		fdf->cam->x += (fdf->mouse->lasty - y) / 200.0f;
		fdf->cam->y -= (fdf->mouse->lastx - x) / 200.0f;
	}
	else if (fdf->mouse->isdown & (1 << 2))
	{
		fdf->cam->factor += (fdf->mouse->lasty - y) / 10.0f + 0.5f;
		if (fdf->cam->factor < 1)
			fdf->cam->factor = 1;
	}
	if (fdf->mouse->isdown)
		paint(fdf, fdf->map);
	return (0);
}

int	hook_mouseup(int button, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	fdf->mouse->isdown &= ~(1 << button);
	return (0);
}

int	hook_mousedown(int button, int x, int y, t_fdf *fdf)
{
	(void)x;
	if (y < 0)
		return (0);
	fdf->mouse->isdown |= 1 << button;
	return (0);
}

int	hook_keydown(int key, t_fdf *fdf)
{
	t_fdf	*tmp;

	(void)fdf;
	tmp = fdf;
	if (key == 53)
		exit(0);
	else if (key == 82)
		search_color(tmp->map, FIRST_COL, SECOND_COL);
	else if (key == 83)
		search_color(tmp->map, 0x84b384, 0xe824dA);
	else if (key == 84)
		search_color(tmp->map, 0xe4cd9c, 0x6f6e8d);
	else if (key == 85)
		search_color(tmp->map, 0xf2f4ab, 0xf02f18);
	else if (key == 86)
		search_color(tmp->map, 0xee1258, 0x479b9e);
	else if (key == 87)
		search_color(tmp->map, 0x162bc7, 0xd9ab21);
	else
		return (0);
	return (1);
}
