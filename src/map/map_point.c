/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 08:27:58 by jyurrita          #+#    #+#             */
/*   Updated: 2023/01/19 19:12:57 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	map(t_pos *point, t_map_params *map_params)
{
	point->x = ((double)point->map_x - (double)map_params->min_in_x)
		* ((double)map_params->max_out_x - (double)map_params->min_out_x)
		/ ((double)map_params->max_in_x - (double)map_params->min_in_x)
		+ (double)map_params->min_out_x;
	point->y = ((double)point->map_y - (double)map_params->min_in_y)
		* ((double)map_params->max_out_y - (double)map_params->min_out_y)
		/ ((double)map_params->max_in_y - (double)map_params->min_in_y)
		+ map_params->min_out_y;
}
