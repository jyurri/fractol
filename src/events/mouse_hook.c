/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:57:34 by jyurrita          #+#    #+#             */
/*   Updated: 2023/01/24 10:07:41 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	paint_julia(int x, int y, t_mlx_params *mlx_params);

int	mouse_event_handler(int button, int x, int y, t_mlx_params *mlx_params)
{
	t_map_params	*map_params;

	map_params = mlx_params->map_params;
	if (button == 1 && x >= 0 && y >= 0)
		center_map(x, y, mlx_params);
	if (button == 2 && x >= 0 && y >= 0)
		paint_julia(x, y, mlx_params);
	if (button == 5)
		zoom_map(mlx_params->map_params);
	else if (button == 4)
		zoom_out_map(map_params);
	paint_fractal(mlx_params, map_params);
	return (0);
}

static void	paint_julia(int x, int y, t_mlx_params *mlx_params)
{
	t_pos	*julia_point;

	julia_point = (t_pos *)malloc(sizeof(t_pos));
	julia_point->map_x = x;
	julia_point->map_y = y;
	map(julia_point, mlx_params->map_params);
	mlx_params->map_params->fractal_id = JULIA_ID;
	mlx_params->map_params->julia_point = julia_point;
	paint_fractal(mlx_params, mlx_params->map_params);
}
