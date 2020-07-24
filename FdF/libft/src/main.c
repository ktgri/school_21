/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahi <bmahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:14:30 by bmahi             #+#    #+#             */
/*   Updated: 2019/07/21 19:04:12 by bmahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int ac, char **av)
{
	int		ret;
	t_list	*list;
	t_map	*map;
	t_fdf	*fdf;

	if (ac != 2)
		error("add a map");
	if (!(reader_map(ret = open(av[1], O_RDONLY), &map, &list)))
		error("fatal error");
	fdf_solve(&fdf);
	fdf->map = map;
	paint(fdf, map);
	mlx_key_hook(fdf->win, hook_keydown, fdf);
	mlx_hook(fdf->win, 4, 0, hook_mousedown, fdf);
	mlx_hook(fdf->win, 5, 0, hook_mouseup, fdf);
	mlx_hook(fdf->win, 6, 0, hook_mousemove, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
