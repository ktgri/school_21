/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:24:16 by bmahi             #+#    #+#             */
/*   Updated: 2019/04/05 19:51:32 by bmahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int i;
	int *str;

	i = 0;
	if (min >= max)
		return (0);
	str = (int*)malloc(sizeof(*str) * (max - min));
	if (str == NULL)
		return (0);
	while (min < max)
	{
		str[i] = min;
		i++;
		min++;
	}
	return (str);
}
