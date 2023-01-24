/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:06:57 by jyurrita          #+#    #+#             */
/*   Updated: 2023/01/24 10:29:28 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <unistd.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "elements.h"
# include "math.h"

void	map(t_pos *point, t_map_params *map_params);
void	paint_fractal(t_mlx_params *mlx_params, t_map_params *map_params);
void	inicialize_map_params(t_map_params *map_params);
void	inicialize_mlx_params(t_mlx_params *mlx_params);
int		key_hook(int key, t_mlx_params *mlx_params);
int		mouse_event_handler(int button, int x, int y, t_mlx_params *mlx_params);
void	zoom_map(t_map_params *map_params);
void	zoom_out_map(t_map_params *map_params);
void	center_map(int x, int y, t_mlx_params *mlx_params);
int		format_julia_arg(int argc, char *argv[], t_pos *julia_point);
void	format_user_input(t_mlx_params *mlx_params, int argc, char *argv[]);
int		check_num_iterations_mandelbrot(t_pos *point, int itera, int esc);
int		check_num_iterations_supermandelbrot(t_pos *point, int itera, int esc);
int		check_num_iterations_julia(t_pos *point, int itera,
			int esc, t_pos *start_z);

#endif