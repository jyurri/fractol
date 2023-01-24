/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_out_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:41:28 by jyurrita          #+#    #+#             */
/*   Updated: 2023/01/24 09:51:47 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	zoom_out_map(t_map_params *map_params)
{
	double	center_x;
	double	center_y;

	map_params->zoom = map_params->zoom / map_params->factor;
	map_params->speed = map_params->speed / map_params->factor;
	center_x = (map_params->max_out_x + map_params->min_out_x) / 2;
	center_y = (map_params->max_out_y + map_params->min_out_y) / 2;
	map_params->max_out_x = center_x + map_params->zoom;
	map_params->min_out_x = center_x - map_params->zoom;
	map_params->max_out_y = center_y + map_params->zoom;
	map_params->min_out_y = center_y - map_params->zoom;
	map_params->num_max_iter = map_params->num_max_iter - 1;
}
