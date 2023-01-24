/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:01:03 by jyurrita          #+#    #+#             */
/*   Updated: 2023/01/23 12:18:08 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	check_num_iterations_julia(t_pos *point, int itera,
	int esc, t_pos *start_z)
{
	double	new_x;
	double	new_y;
	double	cx;
	double	cy;
	int		n;

	n = 0;
	cx = start_z->x;
	cy = start_z->y;
	while (n < itera && (fabs(point->x) + fabs(point->x) < esc))
	{
		new_x = point->x * point->x - point->y * point->y;
		new_y = 2 * point->x * point->y;
		point->x = new_x + cx;
		point->y = new_y + cy;
		n++;
	}
	return (n);
}
