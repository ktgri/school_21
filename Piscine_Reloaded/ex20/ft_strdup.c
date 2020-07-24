/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:19:59 by bmahi             #+#    #+#             */
/*   Updated: 2019/04/05 16:24:37 by bmahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
		i++;
	dst = malloc(i + 1);
	if (dst == NULL)
		return (0);
	while (j < i)
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (dst);
}
