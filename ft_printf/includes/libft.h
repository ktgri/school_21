/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorie <kcorie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 21:16:19 by kcorie            #+#    #+#             */
/*   Updated: 2020/01/14 21:16:22 by kcorie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

int				ft_atoi(char const *s);
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *s, int c, size_t n);
size_t			ft_strlen(char const *s);
int				ft_strnequ(char const *s1, char const *s2, size_t n);

#endif
