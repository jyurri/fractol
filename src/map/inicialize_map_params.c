/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialize_map_params.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:47:47 by jyurrita          #+#    #+#             */
/*   Updated: 2023/01/17 17:48:38 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <fractol.h>

void inicialize_map_params(t_map_params *map_params)
{
	map_params->max_in_x = WIN_WIDTH;
	map_params->max_in_y = WIN_HEIGH;
	map_params->max_out_x = 2;
	map_params->max_out_y = 2;
	map_params->min_in_x = 0;
	map_params->min_in_y = 0;
	map_params->min_out_y = -2;
	map_params->min_out_x = -2;
	map_params->zoom = 2;
	map_params->speed = 0.1;
	map_params->factor = 0.9;
	//set_center(map_params);
}