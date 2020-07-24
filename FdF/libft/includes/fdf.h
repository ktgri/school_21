/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahi <bmahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 19:50:03 by bmahi             #+#    #+#             */
/*   Updated: 2019/07/21 19:05:43 by bmahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WGHT 1920
# define HGHT 1024

# define FIRST_COL 0x9ef68e
# define SECOND_COL 0xed6983

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <math.h>
# include <limits.h>

typedef struct	s_cam
{
	double		setx;
	double		sety;
	double		x;
	double		y;
	int			factor;
}				t_cam;

typedef struct	s_pixel
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_pixel;

typedef struct	s_map
{
	int			w;
	int			h;
	int			deepmin;
	int			deepmax;
	t_pixel		**pixel;
}				t_map;

typedef struct	s_tmp
{
	t_pixel		start;
	t_pixel		stop;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err1;
	int			err2;
}				t_tmp;

typedef struct	s_mouse
{
	char		isdown;
	int			x;
	int			y;
	int			lastx;
	int			lasty;
}				t_mouse;

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*pointer_adr;
	int			bpp;
	int			wide;
	int			end;
	t_map		*map;
	t_cam		*cam;
	t_mouse		*mouse;
}				t_fdf;

void			set_pxl(t_fdf *fdf, int x, int y, int color);
int				borderline(t_fdf *fdf, t_tmp *tmp, t_pixel *pxl1, \
				t_pixel *pxl2);
void			alter(t_pixel *tmp, t_pixel *pxl1, t_pixel *pxl2, int shape);
int				place(int x, int y);

int				rotate_line(t_pixel *pxl1, t_pixel *pxl2);
void			paint_line(t_fdf *fdf, t_pixel pxl1, t_pixel pxl2);
t_pixel			proect_line(t_fdf *fdf, t_pixel pxl1);
t_pixel			proection(t_pixel pxl, t_fdf *fdf);
void			paint(t_fdf *fdf, t_map *map);

t_cam			*camera_solve(void);
int				fdf_solve(t_fdf **fdf);

int				ft_lerpi(int first, int second, double p);
int				clerp(int c1, int c2, double p);
double			ft_ilerp(double val, double first, double second);
void			search_color(t_map *map, int col1, int col2);
void			search_maxmin(t_map *map);

void			free_point(char ***splt);
t_pixel			*pixel_solve(int x, int y, char *splt);
void			pixel(t_list **list, t_map **map);
t_map			*map_solve(size_t x, size_t y);
int				reader_map(int fd, t_map **map, t_list **list);

int				hook_keydown(int key, t_fdf *fdf);
int				hook_mousemove(int x, int y, t_fdf *mlx);
int				hook_mouseup(int button, int x, int y, t_fdf *mlx);
int				hook_mousedown(int button, int x, int y, t_fdf *mlx);

#endif
