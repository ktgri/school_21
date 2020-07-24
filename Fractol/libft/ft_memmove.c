/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahi <bmahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:14:55 by bmahi             #+#    #+#             */
/*   Updated: 2019/04/29 18:05:58 by bmahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*sr;
	unsigned char	*ds;

	sr = (unsigned char*)src;
	ds = (unsigned char*)dst;
	if (src == dst)
		return (dst);
	if (ds < sr)
		while (len--)
			*ds++ = *sr++;
	else
	{
		ds = ds + (len - 1);
		sr = sr + (len - 1);
		while (len--)
			*ds-- = *sr--;
	}
	return (dst);
}
