/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahi <bmahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:33:28 by bmahi             #+#    #+#             */
/*   Updated: 2019/04/29 17:58:32 by bmahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	i2;

	i2 = 0;
	i = 0;
	while (i < len)
	{
		if (*(src + i2))
			*(dst + i) = *(src + i2++);
		else
			*(dst + i) = '\0';
		i++;
	}
	return (dst);
}
