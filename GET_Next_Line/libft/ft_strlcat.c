/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahi <bmahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 20:32:20 by bmahi             #+#    #+#             */
/*   Updated: 2019/04/19 17:33:40 by bmahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *rsrc, size_t size)
{
	size_t i;
	size_t len;

	i = 0;
	len = ft_strlen(dst) + ft_strlen(rsrc);
	if (size <= ft_strlen(dst))
		return (ft_strlen(rsrc) + size);
	while (*dst)
		dst++;
	while (rsrc[i] && (i < size - (len - ft_strlen(rsrc)) - 1))
	{
		dst[i] = rsrc[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
