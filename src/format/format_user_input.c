/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_user_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:38:57 by jyurrita          #+#    #+#             */
/*   Updated: 2023/01/24 09:31:05 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	select_mandelbrot(t_mlx_params *mlx_params);
static void	select_julia(t_mlx_params *mlx_params, int argc, char *argv[]);
static void	select_supermandelbrot(t_mlx_params *mlx_params);

void	format_user_input(t_mlx_params *mlx_params, int argc, char *argv[])
{
	t_map_params	*map_params;

	map_params = mlx_params->map_params;
	if (argc == 2 && ft_strncmp(argv[1], "mandelbrot", 11) == 0)
		select_mandelbrot(mlx_params);
	else if (argc == 2 && ft_strncmp(argv[1], "supermandelbrot", 16) == 0)
		select_supermandelbrot(mlx_params);
	else if (argc == 4 && ft_strncmp(argv[1], "julia", 6) == 0)
		select_julia(mlx_params, argc, argv);
	else
	{
		ft_printf("For Mandelbrot fractal: format your input this way"
			" <./fractol mandelbrot\n"
			"For Julia fractal: format your input this way "
			"<./fractol julia 0.01 -0.02>\n"
			"the numbers from before are an examples of the x and y values");
		exit(0);
	}
}

static void	select_supermandelbrot(t_mlx_params *mlx_params)
{
	mlx_params->map_params->fractal_id = SUPERMANDELBROT_ID;
	paint_fractal(mlx_params, mlx_params->map_params);
}

static void	select_mandelbrot(t_mlx_params *mlx_params)
{
	mlx_params->map_params->fractal_id = MANDELBROT_ID;
	paint_fractal(mlx_params, mlx_params->map_params);
}

static void	select_julia(t_mlx_params *mlx_params, int argc, char *argv[])
{
	t_pos			*julia_point;
	t_map_params	*map_params;

	map_params = mlx_params->map_params;
	julia_point = (t_pos *)malloc(sizeof(t_pos));
	if (format_julia_arg(argc, argv, julia_point) == 1)
	{
		map_params->fractal_id = JULIA_ID;
		map_params->julia_point = julia_point;
		paint_fractal(mlx_params, map_params);
	}
	else
	{
		ft_printf("Format your input this way <./fractol julia 0.01 -0.02>"
			"the numbers from before are an examples of the x and y value");
		exit(0);
	}
}
