/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:39:04 by jyurrita          #+#    #+#             */
/*   Updated: 2023/01/17 17:59:30 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <fractol.h>

int main(void)
{
	t_mlx_params	*mlx_params;
	t_map_params	*map_params;
	
	//int color = 0x008000;
	mlx_params = (t_mlx_params *)malloc(sizeof(t_mlx_params));
	mlx_params->mlx = mlx_init();
	mlx_params->mlx_win = mlx_new_window(mlx_params->mlx, WIN_WIDTH, WIN_HEIGH, "Fractol");
	map_params = (t_map_params *)malloc(sizeof(t_map_params));
	inicialize_map_params(map_params);
	paint_mandelbrot(mlx_params, map_params);
	mlx_params->map_params = map_params;
	mlx_mouse_hook(mlx_params->mlx_win, mouse_event_handler, mlx_params);
	mlx_key_hook(mlx_params->mlx_win, key_hook, mlx_params);
	mlx_loop(mlx_params->mlx);
	return (0);
}