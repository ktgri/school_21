/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahi <bmahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 20:37:06 by bmahi             #+#    #+#             */
/*   Updated: 2019/04/27 17:14:13 by bmahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	int		i;
	int		neg;
	char	*result;

	neg = 1;
	i = index_int(n);
	result = ft_strnew(i);
	if (!result)
		return (NULL);
	if (n < 0)
	{
		neg = -1;
		result[0] = '-';
	}
	if (n == 0)
		result[0] = '0';
	while (n != 0)
	{
		result[--i] = n % 10 * neg + '0';
		n = n / 10;
	}
	return (result);
}
