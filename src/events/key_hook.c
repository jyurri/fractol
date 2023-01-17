/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:42:02 by jyurrita          #+#    #+#             */
/*   Updated: 2023/01/17 18:17:42 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <fractol.h>

int key_hook(int key, t_mlx_params *mlx_params) 
{
	t_map_params 	*map_params;

	map_params = mlx_params->map_params;
    if (key == 123)
	{
		map_params->max_out_x = map_params->max_out_x - map_params->speed;
		map_params->min_out_x = map_params->min_out_x - map_params->speed;
	}
    else if (key == 124)
	{
		map_params->max_out_x = map_params->max_out_x + map_params->speed;
		map_params->min_out_x = map_params->min_out_x + map_params->speed;
	}
    else if (key == 126)
	{
		map_params->max_out_y = map_params->max_out_y - map_params->speed;
		map_params->min_out_y = map_params->min_out_y - map_params->speed;
	}
    else if (key == 125) 
    {
		map_params->max_out_y = map_params->max_out_y + map_params->speed;
		map_params->min_out_y = map_params->min_out_y + map_params->speed;
	}
    else if (key == 8) 
	{
		zoom_map(map_params);
	}
	paint_mandelbrot(mlx_params, map_params);
    return 0;
}