/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahi <bmahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 17:50:47 by bmahi             #+#    #+#             */
/*   Updated: 2019/04/25 17:53:37 by bmahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *first_link;

	if (!alst || !*alst || !del)
		return ;
	while (alst && *alst)
	{
		first_link = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = first_link;
	}
	*alst = NULL;
}
