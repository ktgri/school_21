/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorie <kcorie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 18:43:05 by kcorie            #+#    #+#             */
/*   Updated: 2019/06/04 18:20:36 by kcorie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	valid_tetranigga(char *black, int i)
{
	int neighbro;

	neighbro = 0;
	if ((i + 1) < 20 && black[i + 1] == '#')
		neighbro++;
	if ((i - 1) >= 0 && black[i - 1] == '#')
		neighbro++;
	if ((i + 5) < 20 && black[i + 5] == '#')
		neighbro++;
	if ((i - 5) >= 0 && black[i - 5] == '#')
		neighbro++;
	return (neighbro);
}

static	int	valid_tetrimo(char *black)
{
	int	i;
	int	zeck;
	int	nigga;

	i = -1;
	zeck = 0;
	nigga = 0;
	while (++i < 20)
	{
		if (i % 5 == 4 && black[i] != '\n')
			return (0);
		else if (i % 5 != 4)
		{
			if (black[i] != '#' && black[i] != '.')
				return (0);
			if (black[i] == '#')
			{
				zeck++;
				nigga += valid_tetranigga(black, i);
			}
		}
	}
	if (zeck != 4 || (nigga != 6 && nigga != 8))
		return (0);
	return (1);
}

int			valid_file(char *file)
{
	int		i;
	char	*black;
	int		len;

	i = 0;
	len = ft_strlen(file);
	if (len < 20)
		return (0);
	while (i < len)
	{
		black = ft_strsub(file, i, 20);
		if (!black)
			return (0);
		if (valid_tetrimo(black) == 0)
			return (0);
		free(black);
		i = i + 20;
		if (i < len && file[i] != '\n')
			return (0);
		else if (len - i < 20 && len - i > 0)
			return (0);
		i++;
	}
	return (1);
}
