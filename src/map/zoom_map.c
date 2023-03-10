/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:07:05 by jyurrita          #+#    #+#             */
/*   Updated: 2023/01/24 07:55:34 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	zoom_map(t_map_params *map_params)
{
	double	center_x;
	double	center_y;

	map_params->zoom = map_params->zoom * map_params->factor;
	map_params->speed = map_params->speed * map_params->factor;
	center_x = (map_params->max_out_x + map_params->min_out_x) / 2;
	center_y = (map_params->max_out_y + map_params->min_out_y) / 2;
	map_params->max_out_x = center_x + map_params->zoom;
	map_params->min_out_x = center_x - map_params->zoom;
	map_params->max_out_y = center_y + map_params->zoom;
	map_params->min_out_y = center_y - map_params->zoom;
	map_params->num_max_iter = map_params->num_max_iter + 1;
}
