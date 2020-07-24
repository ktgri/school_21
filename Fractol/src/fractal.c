/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahi <bmahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 20:21:27 by bmahi             #+#    #+#             */
/*   Updated: 2019/10/03 21:22:33 by bmahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		mandelbrot(t_complex c, t_frctl *f)
{
	int			i;
	t_complex	z;

	z = complex_solve(c.re, c.im);
	i = -1;
	while (z.re * z.re + z.im * z.im <= 4.0 && ++i < f->max_iter)
	{
		z = complex_solve(z.re * z.re - z.im * z.im + c.re,
				2.0 * z.re * z.im + c.im);
	}
	return (i);
}

int		mandelbar(t_complex c, t_frctl *f)
{
	int			i;
	t_complex	z;

	z = complex_solve(c.re, c.im);
	i = 0;
	while (z.re * z.im + z.im * z.im <= 4 && i < f->max_iter)
	{
		z = complex_solve(z.re * z.re - z.im * z.im + c.re,
				-2.0 * z.re * z.im + c.im);
		i++;
	}
	return (i);
}

int		julia(t_complex c, t_frctl *f)
{
	int			i;
	t_complex	z;

	z = c;
	i = 0;
	while (z.re * z.re + z.im * z.im <= 4 && i < f->max_iter)
	{
		z = complex_solve(z.re * z.re - z.im * z.im + f->c.re,
				2 * z.re * z.im + f->c.im);
		i++;
	}
	return (i);
}

void	*fractal(void *thread)
{
	t_thr		*t;
	int			x;
	int			iter;
	t_complex	c;

	t = (t_thr *)thread;
	while (++(t->in) < t->end)
	{
		c.im = (t->fcl.max.im + t->fcl.offset_y -
				(double)(t->in) * t->fcl.fuck.im);
		x = -1;
		while (++x < (int)SIZE_W)
		{
			c.re = (t->fcl.min.re + t->fcl.offset_x +
					(double)x * t->fcl.fuck.re);
			if ((iter = t->fcl.f(c, &(t->fcl))) < t->fcl.max_iter)
				color(iter, x, t->in, &(t->fcl));
			else
				new_religion(&t->fcl, x, t->in);
		}
	}
	return (NULL);
}

int		choose_frctl(t_frctl *fr, char *av)
{
	if (ft_strcmp("julia", av) == 0)
		fr->f = julia;
	else if (ft_strcmp("mandelbrot", av) == 0)
		fr->f = mandelbrot;
	else if (ft_strcmp("mandelbar", av) == 0)
		fr->f = mandelbar;
	else
	{
		ft_putstr("\nUsage:\n\t ./Fractal <type of fractal>"
			"\n\nList of fractal:\n\t\t\t\t - ");
		ft_putstr("julia\n\t\t\t\t - mandelbrot\n\t\t\t\t - mandelbar\n");
		return (0);
	}
	return (1);
}
