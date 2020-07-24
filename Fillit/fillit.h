/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorie <kcorie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 17:57:44 by bmahi             #+#    #+#             */
/*   Updated: 2019/06/04 18:43:51 by kcorie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"

typedef struct		s_map
{
	int		size_map;
	char	**matrix;
}					t_map;

typedef struct		s_coordinate
{
	int		x;
	int		y;
}					t_coordinate;

typedef struct		s_figure
{
	char	**piece;
	int		w;
	int		h;
	char	sym;
}					t_figure;

int					valid_file(char *file);
t_list				*read_block(char *file);
t_coordinate		*new_coordinate(int x, int y);
t_list				*free_list(t_list *list);
void				free_map(t_map *map);
t_map				*solution(t_list *list);
void				print_map(t_map *map);
void				ft_lstend(t_list **list, t_list *fig);
int					feel_it(t_map *map, t_list *list);

#endif
