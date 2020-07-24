/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahi <bmahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:00:47 by bmahi             #+#    #+#             */
/*   Updated: 2019/04/27 17:15:29 by bmahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**new;
	int		ind_w;
	int		word;

	word = 0;
	if (!s || !(new = (char **)ft_memalloc(sizeof(char *)
		* (sum_word(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		ind_w = 0;
		s = ptr_word(s, c);
		if (*s && !(new[word] = ft_strnew(len_word(s, c))))
		{
			while (word--)
				free(new[word]);
			free(new);
			return (NULL);
		}
		while (*s != c && *s)
			new[word][ind_w++] = *s++;
		word++;
	}
	return (new);
}
