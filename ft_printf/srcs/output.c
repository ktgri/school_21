/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorie <kcorie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 21:18:23 by kcorie            #+#    #+#             */
/*   Updated: 2020/01/14 21:18:26 by kcorie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_buf(void)
{
	int printed;

	printed = write(g_ftprintf.fd, g_ftprintf.buf, g_ftprintf.len);
	if (printed != g_ftprintf.len)
		g_ftprintf.error = -1;
	g_ftprintf.printed += printed;
	g_ftprintf.len = 0;
}

void	char_to_buf(char c, int n)
{
	while (n)
	{
		*(g_ftprintf.buf + g_ftprintf.len) = c;
		++g_ftprintf.len;
		if (g_ftprintf.len == BUFF_SIZE)
			print_buf();
		--n;
	}
}

void	string_to_buf(const char *s, const char *end)
{
	while (s < end)
	{
		*(g_ftprintf.buf + g_ftprintf.len) = *s;
		++s;
		++g_ftprintf.len;
		if (g_ftprintf.len == BUFF_SIZE)
			print_buf();
	}
}

char	*make_width(t_frmt *prm)
{
	char *width;

	prm->width -= prm->len;
	if (!(width = (char *)malloc(sizeof(char) * (prm->width + 1))))
	{
		g_ftprintf.error = -1;
		return (NULL);
	}
	ft_memset(width, (prm->flags & F_ZERO ? '0' : ' '), prm->width);
	*(width + prm->width) = 0;
	return (width);
}

void	to_print(char *out, char *width, t_frmt *prm)
{
	if (!(prm->flags & F_MINUS) && width)
	{
		string_to_buf(width, width + prm->width);
		free(width);
	}
	string_to_buf(out, out + prm->len);
	if ((prm->flags & F_MINUS) && width)
	{
		string_to_buf(width, width + prm->width);
		free(width);
	}
}
