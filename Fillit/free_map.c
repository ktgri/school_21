/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorie <kcorie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 19:41:08 by kcorie            #+#    #+#             */
/*   Updated: 2019/06/04 18:00:18 by kcorie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_lstend(t_list **list, t_list *fig)
{
	t_list *head;

	head = *list;
	if (head)
	{
		while (head->next)
			head = head->next;
		head->next = fig;
	}
	else
		*list = fig;
}

static	void	free_figure(t_figure *figure)
{
	int y;

	y = 0;
	while (y < figure->h)
	{
		ft_memdel((void **)(&figure->piece[y]));
		y++;
	}
	ft_memdel((void **)(&figure->piece));
	ft_memdel((void **)&figure);
}

t_list			*free_list(t_list *list)
{
	t_figure	*figure;
	t_list		*next;

	while (list != NULL)
	{
		figure = (t_figure *)list->content;
		next = list->next;
		free_figure(figure);
		ft_memdel((void **)&list);
		list = next;
	}
	return (NULL);
}

void			free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size_map)
	{
		ft_memdel((void **)&(map->matrix[i]));
		i++;
	}
	ft_memdel((void **)&(map->matrix));
	ft_memdel((void **)&map);
}

void			print_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size_map)
	{
		ft_putstr(map->matrix[i]);
		ft_putchar('\n');
		i++;
	}
}
