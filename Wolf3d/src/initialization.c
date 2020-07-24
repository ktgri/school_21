/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahi <bmahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 23:03:43 by dgorold-          #+#    #+#             */
/*   Updated: 2019/10/27 16:38:45 by bmahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void				player_init(t_w *w)
{
	w->texture = NULL;
	w->sdl = NULL;
	w->player.direction = 90;
	w->player.x = -1;
	w->player.y = -1;
	w->player.turn = 6;
	w->player.speed = 6;
	w->player.players = 0;
}

static SDL_Surface	*load_surface(char *file)
{
	SDL_Surface		*surf;
	SDL_Surface		*result;

	surf = SDL_LoadBMP(file);
	if (surf != NULL && surf->w == 64 && surf->h == 64)
	{
		result = SDL_ConvertSurfaceFormat(surf, SDL_PIXELFORMAT_ARGB8888, 1);
		SDL_FreeSurface(surf);
		return (result);
	}
	else
	{
		alert_error(3);
	}
	return (NULL);
}

static void			init_textures(t_w *w)
{
	w->texture->walls[0] = load_surface(WALL0);
	w->texture->walls[1] = load_surface(WALL1);
	w->texture->walls[2] = load_surface(WALL2);
	w->texture->walls[3] = load_surface(WALL3);
}

static void			malloc_stuff(t_w *w)
{
	w->sdl = (t_sdl *)malloc(sizeof(t_sdl));
	w->texture = (t_textures *)malloc(sizeof(t_textures));
	w->texture->walls = (SDL_Surface **)malloc(sizeof(SDL_Surface *) * 4);
}

void				initialization_(t_w *w)
{
	double			fov;

	malloc_stuff(w);
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		alert_error(3);
	w->sdl->window = SDL_CreateWindow(SDL_ATR);
	w->sdl->surface = SDL_GetWindowSurface(w->sdl->window);
	init_textures(w);
	w->m.map_h = w->m.map_h + 2;
	w->m.map_w = w->m.map_w + 2;
	fov = (M_PI / 6.0);
	w->sdl->keyboard = SDL_GetKeyboardState(NULL);
	w->half_width = (int)(W * 0.5);
	w->half_height = (int)(H * 0.5);
	w->dist_to_projection_plane = (int)((double)w->half_width / tan(fov));
}
