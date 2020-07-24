/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahi <bmahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:15:26 by bmahi             #+#    #+#             */
/*   Updated: 2019/04/27 16:37:08 by bmahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ds;
	unsigned char	*sr;

	ds = (unsigned char *)dst;
	sr = (unsigned char *)src;
	while (n > 0 && *sr != (unsigned char)c)
	{
		*ds++ = *sr++;
		n--;
	}
	if (n > 0)
	{
		*ds++ = *sr++;
		return (ds);
	}
	return (NULL);
}
