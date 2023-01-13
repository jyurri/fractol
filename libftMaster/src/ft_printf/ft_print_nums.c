/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 08:01:32 by jyurrita          #+#    #+#             */
/*   Updated: 2022/12/27 09:54:36 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(int n)
{
	int			num_chars;

	num_chars = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			write(1, "-2147483648", 11);
			return (11);
		}
		n = n * -1;
		write(1, "-", 1);
		num_chars++;
	}
	if (n >= 10)
	{
		num_chars = num_chars + print_int(n / 10);
		num_chars += print_numb_digit(n);
	}
	else
		num_chars += print_numb_digit(n);
	return (num_chars);
}

int	print_unsigned_int(int n)
{
	unsigned long int	lnum;
	char				c;
	int					num_chars;

	lnum = (unsigned)n;
	num_chars = 0;
	if (lnum >= 10)
	{
		c = lnum % 10 + '0';
		lnum = lnum / 10;
		num_chars = print_unsigned_int(lnum);
		write(1, &c, 1);
		num_chars++;
	}
	else
	{
		c = lnum % 10 + '0';
		write(1, &c, 1);
		num_chars++;
	}
	return (num_chars);
}

int	print_hexa(unsigned int lnum)
{
	int			digi;
	char		*hexa_num;
	int			num_chars;

	num_chars = 0;
	hexa_num = "0123456789abcdef";
	if (lnum >= 16)
	{
		digi = lnum % 16;
		lnum = lnum / 16;
		num_chars = print_hexa(lnum);
		write(1, &hexa_num[digi], 1);
		num_chars++;
	}
	else
	{
		digi = lnum % 16;
		write(1, &hexa_num[digi], 1);
		num_chars++;
	}
	return (num_chars);
}

int	print_hexa_mayus(unsigned int lnum)
{
	int			digi;
	char		*hexa_num;
	int			num_chars;

	num_chars = 0;
	hexa_num = "0123456789ABCDEF";
	if (lnum >= 16)
	{
		digi = lnum % 16;
		lnum = lnum / 16;
		num_chars = print_hexa_mayus(lnum);
		write(1, &hexa_num[digi], 1);
		num_chars++;
	}
	else
	{
		digi = lnum % 16;
		write(1, &hexa_num[digi], 1);
		num_chars++;
	}
	return (num_chars);
}

int	print_numb_digit(int num)
{
	char	c;

	c = num % 10 + '0';
	write(1, &c, 1);
	return (1);
}
