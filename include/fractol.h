/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:06:57 by jyurrita          #+#    #+#             */
/*   Updated: 2023/01/17 18:16:32 by jyurrita         ###   ########.fr       */
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

void map(t_pos *point, t_map_params *map_params);
void paint_mandelbrot(t_mlx_params *mlx_params, t_map_params *map_params);
void inicialize_map_params(t_map_params *map_params);
int key_hook(int key, t_mlx_params *mlx_params);
int	mouse_event_handler(int button, int x, int y, t_mlx_params *mlx_params);
void zoom_map(t_map_params *map_params);
void center_map(int x, int y, t_mlx_params *mlx_params);

#endif