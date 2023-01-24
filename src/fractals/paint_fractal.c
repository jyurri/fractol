/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:44:18 by jyurrita          #+#    #+#             */
/*   Updated: 2023/01/24 10:13:13 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static	void	paint_pixel(t_mlx_params *mlx_params, t_map_params *map_params,
					int num_itera_esc, t_pos *point);
static void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
static void	loop_window_points(t_pos *point, t_mlx_params *mlx_params,
					t_map_params *map_params);

void	paint_fractal(t_mlx_params *mlx_params, t_map_params *map_params)
{
	t_pos	*point;
	t_data	img;

	point = (t_pos *)malloc(sizeof(t_pos));
	mlx_clear_window(mlx_params->mlx, mlx_params->mlx_win);
	img.img = mlx_new_image(mlx_params->mlx, WIN_WIDTH, WIN_HEIGH);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	mlx_params->img = &img;
	loop_window_points(point, mlx_params, map_params);
	mlx_put_image_to_window(mlx_params->mlx, mlx_params->mlx_win,
		img.img, 0, 0);
	mlx_destroy_image(mlx_params->mlx, img.img);
	if (point)
		free (point);
}

static void	paint_pixel(t_mlx_params *mlx_params, t_map_params *map_params,
		int num_itera_esc, t_pos *point)
{
	int	col;

	if (num_itera_esc == map_params->num_max_iter)
		my_mlx_pixel_put(mlx_params->img, point->map_x, point->map_y, 0xFFFFFF);
	else
	{
		col = 255 * ((float)num_itera_esc / (float)map_params->num_max_iter);
		col += col * map_params->color_factor;
		my_mlx_pixel_put(mlx_params->img, point->map_x, point->map_y, col);
	}
}

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

static void	loop_window_points(t_pos *point, t_mlx_params *mlx_params,
				t_map_params *map_params)
{
	int		num_itera_esc;

	point->map_x = 0;
	point->map_y = 0;
	while (point->map_y < WIN_HEIGH)
	{
		while (point->map_x < WIN_WIDTH)
		{
			map(point, map_params);
			if (map_params->fractal_id == MANDELBROT_ID)
				num_itera_esc = check_num_iterations_mandelbrot(point,
						map_params->num_max_iter, ESCAPE_ITERA);
			else if (map_params->fractal_id == SUPERMANDELBROT_ID)
				num_itera_esc = check_num_iterations_supermandelbrot(point,
						map_params->num_max_iter, ESCAPE_ITERA);
			else if (map_params->fractal_id == JULIA_ID)
				num_itera_esc = check_num_iterations_julia(point,
						map_params->num_max_iter,
						ESCAPE_ITERA, map_params->julia_point);
			paint_pixel(mlx_params, map_params, num_itera_esc, point);
			point->map_x++;
		}
		point->map_x = 0;
		point->map_y++;
	}
}
