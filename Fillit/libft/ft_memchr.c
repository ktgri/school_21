/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahi <bmahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:23:30 by bmahi             #+#    #+#             */
/*   Updated: 2019/04/29 18:03:46 by bmahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	sym;
	size_t			i;

	str = (unsigned char*)s;
	sym = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == sym)
			return (str + i);
		i++;
	}
	return (NULL);
}
