/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:28:25 by jyurrita          #+#    #+#             */
/*   Updated: 2023/01/24 09:49:45 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENTS_H
# define ELEMENTS_H

typedef enum e_win_size
{
	WIN_HEIGH= 500,
	WIN_WIDTH = 500
}	t_win_size;

typedef enum e_mandelbrot_param
{
	NUM_MAX_ITERA = 100,
	ESCAPE_ITERA = 16,
}	t_mandelbrot_param;

typedef enum e_fractal_index
{
	MANDELBROT_ID = 1,
	JULIA_ID = 2,
	SUPERMANDELBROT_ID = 3,
}	t_fractal_index;

typedef struct s_pos{
	double	x;
	double	y;
	int		map_x;
	int		map_y;
}	t_pos;

typedef struct s_map_params {
	double	min_in_x;
	double	max_in_x;
	double	max_out_x;
	double	min_out_x;
	double	max_out_y;
	double	min_out_y;
	double	min_in_y;
	double	max_in_y;
	t_pos	*center;
	double	speed;
	double	zoom;
	double	factor;
	int		num_max_iter;
	int		fractal_id;
	int		color_factor;
	t_pos	*julia_point;
}	t_map_params;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_mlx_params {
	void			*mlx;
	void			*mlx_win;
	t_map_params	*map_params;
	t_data			*img;
}	t_mlx_params;

#endif