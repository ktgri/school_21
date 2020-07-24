/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahi <bmahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:35:45 by bmahi             #+#    #+#             */
/*   Updated: 2019/10/03 21:29:22 by bmahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			frctl_pthrd(t_frctl *f)
{
	t_thr		*t;
	int			i;

	i = 0;
	if ((t = (t_thr *)malloc(sizeof(t_thr) * THREAD)) == NULL)
		error("ERROR : Malloc dead! You're win!\n");
	while (i < THREAD)
	{
		t[i].in = i * PARTY - 1;
		t[i].end = (i + 1) * PARTY;
		t[i].fcl = *f;
		pthread_create(&(t[i].p), NULL, fractal, (void *)&t[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i].p, NULL);
	free(t);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void			frctl_solve(t_frctl *f)
{
	f->max_iter = 100;
	f->mousej = 1;
	f->tmp = 1.0f;
	f->offset_x = 0.0f;
	f->offset_y = 0.0f;
	f->flag = 0;
	f->min = complex_solve(-2.0f, -2.0f);
	f->max.re = 2.0f;
	f->max.im = f->min.im + (f->max.re - f->min.re);
	f->fuck = complex_solve((f->max.re - f->min.re) / (SIZE_W - 1),
			(f->max.im - f->min.im) / (SIZE_W - 1));
}

void			create_win(t_frctl *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, SIZE_W, SIZE_W, "My_fractal");
	f->img = mlx_new_image(f->mlx, SIZE_W, SIZE_W);
	f->img_ptr = mlx_get_data_addr(f->img, &(f->bpp),
			&(f->size_line), &(f->endian));
	frctl_solve(f);
}

int				main(int ac, char **av)
{
	t_frctl		*f;

	if (!(f = (t_frctl *)malloc(sizeof(t_frctl))))
		return (-1);
	if (ac == 2)
	{
		if (choose_frctl(f, av[1]))
		{
			create_win(f);
			frctl_pthrd(f);
			hooks(f);
			mlx_loop(f->mlx);
		}
	}
	else
	{
		ft_putstr("\nUsage:\n\t ./Fractal <type of fractal>"
			"\n\nList of fractal:\n\t\t\t\t - ");
		ft_putstr("julia\n\t\t\t\t - mandelbrot\n\t\t\t\t - mandelbar\n");
	}
	free(f);
	return (0);
}
