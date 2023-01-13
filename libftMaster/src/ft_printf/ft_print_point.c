/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:29:37 by jyurrita          #+#    #+#             */
/*   Updated: 2022/10/13 10:08:58 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(void *p)
{
	int						num_chars;
	unsigned long long int	lp;

	lp = (unsigned long long int)p;
	num_chars = 2;
	write(1, "0x", 2);
	num_chars += print_hexa_point(lp);
	return (num_chars);
}

int	print_hexa_point(unsigned long long int lnum)
{
	char		*hexa_num;
	int			num_chars;

	num_chars = 0;
	hexa_num = "0123456789abcdef";
	if (lnum < 16)
		num_chars += print_char(hexa_num[lnum % 16]);
	else
	{
		num_chars = print_hexa_point(lnum / 16);
		num_chars += print_char(hexa_num[lnum % 16]);
	}
	return (num_chars);
}
