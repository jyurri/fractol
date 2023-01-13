/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 07:43:14 by jyurrita          #+#    #+#             */
/*   Updated: 2022/10/24 16:11:36 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *text, ...)
{
	va_list	args;
	int		i;
	int		num_chars;

	i = 0;
	num_chars = 0;
	va_start(args, text);
	while (text[i])
	{
		if (text[i] == '%')
		{
			i++;
			if (text[i] && (text[i] == 'c' || text[i] == 's' || text[i] == 'p'
					|| text[i] == 'd' || text[i] == 'i' || text[i] == 'u'
					|| text[i] == 'x' || text[i] == 'X' || text[i] == '%'))
				num_chars = num_chars + print_arg(text[i], args);
		}
		else
			num_chars += print_char(text[i]);
		i++;
	}
	va_end(args);
	return (num_chars);
}

int	print_arg(char c, va_list args)
{
	int	num_chars;

	num_chars = 0;
	if (c == 'c')
		num_chars = print_char(va_arg(args, int));
	else if (c == 's')
		num_chars = print_string(va_arg(args, char *));
	else if (c == 'p')
		num_chars = print_pointer(va_arg(args, void *));
	else if (c == 'i')
		num_chars = print_int(va_arg(args, int));
	else if (c == 'd')
		num_chars = print_int(va_arg(args, int));
	else if (c == 'u')
		num_chars = print_unsigned_int(va_arg(args, int));
	else if (c == 'x')
		num_chars = print_hexa(va_arg(args, int));
	else if (c == 'X')
		num_chars = print_hexa_mayus(va_arg(args, int));
	else if (c == '%')
		num_chars = print_char('%');
	return (num_chars);
}
