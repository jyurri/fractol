/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:16:57 by jyurrita          #+#    #+#             */
/*   Updated: 2022/09/28 19:00:00 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cont_digit(long int n);

char	*ft_itoa(int n)
{
	long int	num;
	char		*num_str;
	int			num_digit;

	num = (long int)n;
	num_digit = cont_digit(num);
	num_str = (char *)malloc((num_digit + 1) * sizeof(char));
	if (num_str == NULL)
		return (NULL);
	if (num < 0)
	{
		num = num * (-1);
		num_str[0] = '-';
	}
	if (num == 0)
		num_str[0] = '0';
	while (num > 0)
	{
		num_str[num_digit - 1] = (char)((num % 10) + '0');
		num = num / 10;
		num_digit--;
	}
	num_str[cont_digit(n)] = '\0';
	return (num_str);
}

static int	cont_digit(long int n)
{
	long int	num;
	int			num_digit;

	num_digit = 1;
	num = n;
	if (num < 0)
	{
		num = num * (-1);
		num_digit++;
	}
	while (num >= 10)
	{
		num = num / 10;
		num_digit ++;
	}
	return (num_digit);
}
/*
int main(void)
{
	int n = 1093002813;
	
	printf("%s", ft_itoa(n));
}*/