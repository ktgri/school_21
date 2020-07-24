/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahi <bmahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 02:53:18 by bmahi             #+#    #+#             */
/*   Updated: 2019/10/03 21:50:24 by bmahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		zoom_cmplx(t_frctl *f, t_complex mouse, double z)
{
	double		interpol;

	interpol = 1.0 / z;
	f->min.re = mouse.re + (f->min.re - mouse.re) * interpol;
	f->min.im = mouse.im + (f->min.im - mouse.im) * interpol;
	f->max.re = mouse.re + (f->max.re - mouse.re) * interpol;
	f->max.im = mouse.im + (f->max.im - mouse.im) * interpol;
	f->fuck = complex_solve((f->max.re - f->min.re) / (SIZE_W - 1),
			(f->max.im - f->min.im) / (SIZE_W - 1));
	f->tmp = (f->max.re - f->min.re) * 0.025;
}

int			zooming(t_frctl *f, int x, int y, int key)
{
	t_complex		mouse;

	if (key == SCROLL_D)
	{
		mouse = complex_solve((double)x / (SIZE_W /
				(f->max.re - f->min.re)) + f->min.re,
				(double)y / (SIZE_W / (f->max.im - f->min.im)) + f->min.im);
		zoom_cmplx(f, mouse, 1.25);
	}
	if (key == SCROLL_U)
	{
		if (f->min.im == -2.0f && f->min.re == -2.0 &&
		f->max.im == 2.0 && f->max.re == 2.0)
			return (0);
		mouse = complex_solve((double)x / (SIZE_W /
				(f->max.re - f->min.re)) + f->min.re,
				(double)y / (SIZE_W / (f->max.im - f->min.im)) + f->min.im);
		zoom_cmplx(f, mouse, 0.8);
	}
	return (1);
}

t_complex	complex_solve(double re, double im)
{
	t_complex	c;

	c.im = im;
	c.re = re;
	return (c);
}
