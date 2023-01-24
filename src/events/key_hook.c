/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:42:02 by jyurrita          #+#    #+#             */
/*   Updated: 2023/01/24 09:53:00 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	move_left(t_map_params *map_params);
static void	move_right(t_map_params *map_params);
static void	move_down(t_map_params *map_params);
static void	move_up(t_map_params *map_params);

int	key_hook(int key, t_mlx_params *mlx_params)
{
	t_map_params	*map_params;

	map_params = mlx_params->map_params;
	if (key == 123)
		move_left(map_params);
	else if (key == 124)
		move_right(map_params);
	else if (key == 126)
		move_down(map_params);
	else if (key == 125)
		move_up(map_params);
	else if (key == 6)
		zoom_map(map_params);
	else if (key == 7)
		zoom_out_map(map_params);
	else if (key == 53)
		exit(0);
	else if (key == 8)
		map_params->color_factor = map_params->color_factor * 16 ;
	if (map_params->color_factor > (16 * 16 * 16 * 16))
		map_params->color_factor = 16 * 16;
	paint_fractal(mlx_params, map_params);
	return (0);
}

static void	move_left(t_map_params *map_params)
{
	map_params->max_out_x = map_params->max_out_x - map_params->speed;
	map_params->min_out_x = map_params->min_out_x - map_params->speed;
}

static void	move_right(t_map_params *map_params)
{
	map_params->max_out_x = map_params->max_out_x + map_params->speed;
	map_params->min_out_x = map_params->min_out_x + map_params->speed;
}

static void	move_down(t_map_params *map_params)
{
	map_params->max_out_y = map_params->max_out_y - map_params->speed;
	map_params->min_out_y = map_params->min_out_y - map_params->speed;
}

static void	move_up(t_map_params *map_params)
{
	map_params->max_out_y = map_params->max_out_y + map_params->speed;
	map_params->min_out_y = map_params->min_out_y + map_params->speed;
}
