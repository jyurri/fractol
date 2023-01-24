/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_julia_arg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:11:39 by jyurrita          #+#    #+#             */
/*   Updated: 2023/01/19 19:16:45 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static double	str_to_double(char *str, int *error);
static double	get_num_no_decimal(int i, char *str, int *decimal, int *error);

int	format_julia_arg(int argc, char *argv[], t_pos *julia_point)
{
	int	error;

	error = 0;
	if (argc != 4)
		return (-1);
	julia_point->x = str_to_double(argv[2], &error);
	ft_printf("x juia %f\n", julia_point->x);
	if (error == 1)
		return (-1);
	julia_point->y = str_to_double(argv[3], &error);
	if (error == 1)
		return (-1);
	return (1);
}

static double	str_to_double(char *str, int *error)
{
	double	result;
	int		i;
	int		decimal;
	int		negativ;

	*error = 0;
	result = 0;
	i = 0;
	decimal = 0;
	negativ = 1;
	if (str[i] == '-' )
	{
		negativ = -1;
		i++;
	}
	result = get_num_no_decimal(i, str, &decimal, error);
	while (decimal > 1)
	{
		result = result / 10;
		decimal--;
	}
	return (result);
}

static double	get_num_no_decimal(int i, char *str, int *decimal, int *error)
{
	double	result;

	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			result = result * 10 + (str[i] - '0');
			if (*decimal > 0)
				*decimal = *decimal + 1;
		}
		else if (str[i] == '.' && *decimal == 0)
			*decimal = *decimal + 1;
		else
		{
			*error = 1;
			return (0);
		}
		i++;
	}
	return (result);
}
