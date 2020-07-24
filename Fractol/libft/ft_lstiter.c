/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahi <bmahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:06:09 by bmahi             #+#    #+#             */
/*   Updated: 2019/04/24 19:26:48 by bmahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *repeat_list;

	if (!lst || !f)
		return ;
	while (lst)
	{
		repeat_list = lst->next;
		f(lst);
		lst = repeat_list;
	}
}
