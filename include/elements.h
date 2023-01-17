/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:28:25 by jyurrita          #+#    #+#             */
/*   Updated: 2023/01/17 12:44:15 by jyurrita         ###   ########.fr       */
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

typedef struct	s_pos {
	double x;
	double y;
	int map_x;
	int map_y;
}	t_pos;

typedef struct	s_map_params {
	double min_in_x;
	double max_in_x;
	double max_out_x;
	double min_out_x;
	double max_out_y;
	double min_out_y;
	double min_in_y;
	double max_in_y;
	t_pos	*center;
	double 	speed;
	double 	zoom;
	double 	factor;
} t_map_params;

typedef struct	s_mlx_params {
	void			*mlx;
	void			*mlx_win;
	t_map_params	*map_params;
}	t_mlx_params;


#endif