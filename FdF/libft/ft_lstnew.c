/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahi <bmahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 20:34:30 by bmahi             #+#    #+#             */
/*   Updated: 2019/04/24 17:28:53 by bmahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *list_new;

	list_new = (t_list *)malloc(sizeof(t_list));
	if (!list_new)
		return (NULL);
	if (!content)
	{
		list_new->content = NULL;
		list_new->content_size = 0;
	}
	else
	{
		if (!(list_new->content = (void *)malloc(content_size)))
		{
			free(list_new);
			return (NULL);
		}
		ft_memcpy(list_new->content, content, content_size);
		list_new->content_size = content_size;
	}
	list_new->next = NULL;
	return (list_new);
}
