/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorie <kcorie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 16:28:28 by bmahi             #+#    #+#             */
/*   Updated: 2019/06/04 18:49:02 by kcorie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int	printerror(char *str)
{
	ft_putendl(str);
	return (1);
}

int			main(int ac, char **av)
{
	t_list	*list;
	t_map	*map;
	int		fd;
	int		ret;
	char	buf[552];

	list = NULL;
	if (ac != 2)
		return (printerror("usage: fillit input_file"));
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0 || (ret = read(fd, buf, 551)) < 0 || !buf[0])
			return (printerror("error"));
		if (valid_file(buf) == 1)
			list = read_block(buf);
		else
			return (printerror("error"));
		close(fd);
	}
	map = solution(list);
	print_map(map);
	free_map(map);
	free_list(list);
	return (0);
}
