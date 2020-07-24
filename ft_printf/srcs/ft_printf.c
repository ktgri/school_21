/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorie <kcorie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 21:18:14 by kcorie            #+#    #+#             */
/*   Updated: 2020/01/14 21:18:16 by kcorie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_output	g_ftprintf;

static t_frmt	initialize_params(void)
{
	t_frmt prm;

	prm.flags = 0;
	prm.mod = 0;
	prm.width = 0;
	prm.precision = 1;
	prm.spec = 0;
	return (prm);
}

static void		parse_string(const char **format, va_list *argp)
{
	while (**format)
	{
		if (**format == '%')
		{
			++(*format);
			if (**format == '%')
			{
				char_to_buf('%', 1);
				++(*format);
			}
			else if (**format)
				if (parse_params(format, argp, initialize_params()) == -1)
					return ;
		}
		else if (**format == '{')
			check_color_and_fd(format, argp);
		else
		{
			char_to_buf(**format, 1);
			++(*format);
		}
	}
}

int				ft_printf(const char *format, ...)
{
	va_list	argp;

	g_ftprintf.printed = 0;
	if (g_ftprintf.error != -1)
		g_ftprintf.error = 0;
	if (format)
	{
		g_ftprintf.len = 0;
		g_ftprintf.fd = 1;
		va_start(argp, format);
		parse_string(&format, &argp);
		print_buf();
		va_end(argp);
	}
	return (g_ftprintf.error ? -1 : g_ftprintf.printed);
}
