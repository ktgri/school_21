/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:28:06 by bmahi             #+#    #+#             */
/*   Updated: 2019/04/09 21:31:35 by bmahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int		main(int ac, char **av)
{
	int		a;
	char	s;

	if (ac > 2)
		write(2, "Too many arguments.\n", 20);
	if (ac < 2)
		write(2, "File name missing.\n", 19);
	if (ac == 2)
	{
		a = open(av[1], O_RDONLY);
		if (a >= 0)
		{
			while (read(a, &s, 1))
				write(1, &s, 1);
			close(a);
		}
	}
	return (0);
}
