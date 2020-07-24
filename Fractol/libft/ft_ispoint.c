/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispoint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahi <bmahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 19:49:08 by bmahi             #+#    #+#             */
/*   Updated: 2019/07/06 19:56:35 by bmahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_ispoint(const char *str, char count)
{
	size_t res;
	size_t i;

	i = 0;
	res = 0;
	while (str[i] && str[i] == count)
		i++;
	while (str[i])
	{
		while (str[i] && str[i] != count)
			i++;
		res++;
		while (str[i] && str[i] == count)
			i++;
	}
	return (res);
}
