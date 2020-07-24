/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahi <bmahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:13:14 by bmahi             #+#    #+#             */
/*   Updated: 2019/04/25 18:02:21 by bmahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del(void *content, size_t content_size)
{
	if (!content)
		return ;
	free(content);
	content = NULL;
	content_size = 0;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *elmnt;
	t_list *fresh;

	if (!lst || !f)
		return (NULL);
	elmnt = f(lst);
	fresh = elmnt;
	if (!fresh)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		if (!(elmnt->next = f(lst)))
		{
			ft_lstdel(&fresh, del);
			return (NULL);
		}
		elmnt = elmnt->next;
	}
	return (fresh);
}
