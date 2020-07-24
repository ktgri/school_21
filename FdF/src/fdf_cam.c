/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_cam.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahi <bmahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 18:57:13 by bmahi             #+#    #+#             */
/*   Updated: 2019/07/21 19:04:10 by bmahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_cam	*camera_solve(void)
{
	t_cam *cam;

	if (!(cam = (t_cam*)malloc(sizeof(t_cam))))
		error("error");
	cam->x = 0;
	cam->y = 0;
	cam->factor = 30;
	cam->setx = WGHT / 2;
	cam->sety = HGHT / 2;
	return (cam);
}

int		fdf_solve(t_fdf **fdf)
{
	if (!((*fdf) = (t_fdf*)malloc(sizeof(t_fdf))))
		error("error");
	if (!((*fdf)->mlx = mlx_init()))
		error("error");
	if (!((*fdf)->win = mlx_new_window((*fdf)->mlx, WGHT, HGHT, "my_fdf")))
		error("error");
	if (!((*fdf)->img = mlx_new_image((*fdf)->mlx, WGHT, HGHT)))
		error("error");
	(*fdf)->pointer_adr = mlx_get_data_addr((*fdf)->img, &(*fdf)->bpp, \
		&(*fdf)->wide, &(*fdf)->end);
	(*fdf)->bpp /= 8;
	if (!((*fdf)->mouse = (t_mouse*)malloc(sizeof(t_mouse))))
		error("error");
	(*fdf)->cam = camera_solve();
	return (1);
}
