/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:00:01 by bmahi             #+#    #+#             */
/*   Updated: 2019/04/05 15:18:52 by bmahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int		main(int ac, char **av)
{
	int		i;
	char	*swp;
	int		sort;

	sort = 1;
	while (sort == 1)
	{
		sort = 0;
		i = 0;
		while (++i < ac - 1)
		{
			if (ft_strcmp(av[i], av[i + 1]) > 0)
			{
				swp = av[i];
				av[i] = av[i + 1];
				av[i + 1] = swp;
				sort = 1;
			}
		}
	}
	i = 0;
	while (++i < ac)
		ft_putstr(av[i]);
	return (0);
}
