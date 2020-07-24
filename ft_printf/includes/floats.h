/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorie <kcorie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 21:15:53 by kcorie            #+#    #+#             */
/*   Updated: 2020/01/14 21:16:27 by kcorie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOATS_H
# define FLOATS_H

typedef union	u_bits
{
	long double			l;
	short				lsh[5];
}				t_bits;

typedef struct	s_ld
{
	uint64_t			mantissa: 64;
	int					exponent: 15;
	int					sign: 1;
}				t_ld;

int				process_a(long double n, int sign, t_frmt *prm);
int				process_efg(char *out, t_frmt *prm, int sign, int e);
int				process_efg_2(char *out, t_frmt *prm, int sign);
void			power2(char *dot, int power);
void			suffix_float(char *out, int e, int spec);

#endif
