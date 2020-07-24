/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_gabarites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorie <kcorie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 19:21:26 by kcorie            #+#    #+#             */
/*   Updated: 2019/06/04 17:48:26 by kcorie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	void			ga(char *blck_str, t_coordinate *min, t_coordinate *max)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (blck_str[i] == '#')
		{
			if (i % 5 < min->x)
				min->x = i % 5;
			if (i % 5 > max->x)
				max->x = i % 5;
			if (i / 5 < min->y)
				min->y = i / 5;
			if (i / 5 > max->y)
				max->y = i / 5;
		}
		i++;
	}
}

static	t_figure		*new_block(char **pos, int x, int y, char letter)
{
	t_figure		*figure;

	figure = ft_memalloc(sizeof(t_figure));
	figure->piece = pos;
	figure->w = x;
	figure->h = y;
	figure->sym = letter;
	return (figure);
}

t_coordinate			*new_coordinate(int x, int y)
{
	t_coordinate	*coordinate;

	coordinate = ft_memalloc(sizeof(t_coordinate));
	coordinate->x = x;
	coordinate->y = y;
	return (coordinate);
}

static	t_figure		*get_block(char *blck_str, char symbol)
{
	char			**figure_pos;
	int				i;
	t_coordinate	*min;
	t_coordinate	*max;
	t_figure		*fig;

	min = new_coordinate(3, 3);
	max = new_coordinate(0, 0);
	ga(blck_str, min, max);
	figure_pos = ft_memalloc(sizeof(char *) * (max->y - min->y + 1));
	i = 0;
	while (i < max->y - min->y + 1)
	{
		figure_pos[i] = ft_strnew(max->x - min->x + 1);
		ft_strncpy(figure_pos[i], blck_str + min->x + (i + min->y) * 5,
			max->x - min->x + 1);
		i++;
	}
	fig = new_block(figure_pos, max->x - min->x + 1, max->y - min->y + 1,
		symbol);
	ft_memdel((void **)&min);
	ft_memdel((void **)&max);
	return (fig);
}

t_list					*read_block(char *file)
{
	char			*buf;
	char			letter;
	t_list			*list;
	t_figure		*figure;
	size_t			len;

	len = 0;
	letter = 'A';
	list = NULL;
	while (len <= ft_strlen(file))
	{
		buf = ft_strsub(file, len, 21);
		if ((figure = get_block(buf, letter++)) == NULL)
		{
			ft_memdel((void **)&buf);
			return (free_list(list));
		}
		ft_lstend(&list, ft_lstnew(figure, sizeof(t_figure)));
		ft_memdel((void **)&buf);
		ft_memdel((void **)&figure);
		len += 21;
	}
	ft_memdel((void **)&buf);
	return (list);
}
