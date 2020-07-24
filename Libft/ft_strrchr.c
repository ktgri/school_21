/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahi <bmahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 17:46:34 by bmahi             #+#    #+#             */
/*   Updated: 2019/04/29 17:55:09 by bmahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*p;
	const char	*fd;

	fd = NULL;
	p = NULL;
	if (c == '\0')
		return (ft_strchr(s, '\0'));
	while ((p = ft_strchr(s, c)))
	{
		fd = p;
		s = p + 1;
	}
	return ((char *)fd);
}
