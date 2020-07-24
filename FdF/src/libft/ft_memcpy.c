/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahi <bmahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:43:22 by bmahi             #+#    #+#             */
/*   Updated: 2019/06/27 22:23:30 by bmahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *ds;
	unsigned char *sr;

	ds = (unsigned char *)dst;
	sr = (unsigned char *)src;
	while (n--)
		*ds++ = *sr++;
	return (dst);
}
