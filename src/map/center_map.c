/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:15:44 by jyurrita          #+#    #+#             */
/*   Updated: 2023/01/17 18:16:19 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <fractol.h>

void center_map(int x, int y, t_mlx_params *mlx_params)
{
	t_map_params 	*map_params;
	t_pos *new_center;
	
	map_params = mlx_params->map_params;
	new_center = (t_pos *)malloc(sizeof(t_pos));
	new_center->map_x = x;
	new_center->map_y = y;
	map(new_center, map_params);
	map_params->max_out_x = new_center->x + map_params->zoom;
	map_params->min_out_x = new_center->x - map_params->zoom;
	map_params->max_out_y = new_center->y + map_params->zoom;
	map_params->min_out_y = new_center->y - map_params->zoom;
}