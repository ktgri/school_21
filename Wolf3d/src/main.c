/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahi <bmahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 19:00:08 by dgorold-          #+#    #+#             */
/*   Updated: 2019/10/27 17:15:19 by bmahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void			alert_error(int key)
{
	if (key == 0)
		write(2, "bad fd or file\n", 15);
	else if (key == 1)
		write(2, "non valid map\n", 14);
	else if (key == 2)
		write(2, "memory not allocated\n", 21);
	else if (key == 3)
		write(2, "SDL drop\n", 9);
	else if (key == 4)
		write(2, "You need one player\n", 20);
	else if (key == 5)
		write(1, "Usage: ./Wolf <name_of_map>\n", 28);
	exit(0);
}

int				main(int argc, char *argv[])
{
	t_w			*wolf;

	if ((wolf = (t_w*)malloc(sizeof(t_w))) == NULL)
		alert_error(2);
	if (argc == 2)
	{
		player_init(wolf);
		read_map(wolf, argv[1]);
		initialization_(wolf);
		while (!check_for_quit(&wolf->sdl->event, wolf))
		{
			ft_memset(wolf->sdl->surface->pixels, 0, W * H * 4);
			print_layer(wolf, 0, H * 0.5, 0x5c4a4a);
			print_layer(wolf, H * 0.5, H, 0x585352);
			SDL_PollEvent(&wolf->sdl->event);
			keyboard_input(wolf);
			process_of_wolf(wolf);
			SDL_UpdateWindowSurface(wolf->sdl->window);
		}
	}
	else
		alert_error(5);
	return (0);
}
