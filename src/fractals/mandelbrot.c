/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:59:50 by jyurrita          #+#    #+#             */
/*   Updated: 2023/01/24 09:31:16 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	check_num_iterations_mandelbrot(t_pos *point, int itera, int esc)
{
	double	new_x;
	double	new_y;
	double	cx;
	double	cy;
	int		n;

	n = 0;
	cx = point->x;
	cy = point->y;
	while (n < itera && (fabs(point->x) + fabs(point->y) < esc))
	{
		new_x = point->x * point->x - point->y * point->y;
		new_y = 2 * point->x * point->y;
		point->x = new_x + cx;
		point->y = new_y + cy;
		n++;
	}
	return (n);
}
