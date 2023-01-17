/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_mandelbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:44:18 by jyurrita          #+#    #+#             */
/*   Updated: 2023/01/17 17:45:17 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <fractol.h>

static int check_num_iterations_mandelbrot(t_pos *point, int itera, int esc);

void paint_mandelbrot(t_mlx_params *mlx_params, t_map_params *map_params)
{
	int num_itera_esc;
	t_pos *point;
	
	point = (t_pos *)malloc(sizeof(t_pos));
	point->map_x = 0;
	point->map_y = 0;
	mlx_clear_window(mlx_params->mlx, mlx_params->mlx_win);
	while (point->map_y < WIN_HEIGH)
	{
		while (point->map_x < WIN_WIDTH)
		{
			map(point, map_params);
			num_itera_esc = check_num_iterations_mandelbrot(point, NUM_MAX_ITERA, ESCAPE_ITERA);
			if (num_itera_esc == NUM_MAX_ITERA)
				mlx_pixel_put(mlx_params->mlx, mlx_params->mlx_win, point->map_x, point->map_y, 0xFFFFFF);
			else
			{
				int col = 255 * ((float)num_itera_esc / (float)100) * 15;
				col += col * 16 * 8 ;
				mlx_pixel_put(mlx_params->mlx, mlx_params->mlx_win, point->map_x, point->map_y, col);
			}
			point->map_x++;
		}
		point->map_x = 0;
		point->map_y++;
	}
}

static int check_num_iterations_mandelbrot(t_pos *point, int itera, int esc)
{
	double new_x;
	double new_y;
	double cx;
	double cy;
	int n;
	
	
	n = 0;
	cx = point->x;
	cy = point->y;
	while (n < itera && (fabs(point->x) + fabs(point->x) < esc))
	{
		new_x = point->x * point->x - point->y * point->y;
		new_y = 2 * point->x * point->y;
		point->x  = new_x + cx;
		point->y  = new_y + cy;
		
		n++;
	}
	return n;
}