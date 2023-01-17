/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:57:34 by jyurrita          #+#    #+#             */
/*   Updated: 2023/01/17 18:18:06 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <fractol.h>

int	mouse_event_handler(int button, int x, int y, t_mlx_params *mlx_params)
{
	
	if (button == 1) 
	{
		center_map(x, y, mlx_params);
	}
    if (button == 5)
	{
		zoom_map(mlx_params->map_params);
    }
    else if (button == 4)
	{
    }
	paint_mandelbrot(mlx_params, mlx_params->map_params);
    return 0;
}
