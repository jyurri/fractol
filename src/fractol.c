/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:39:04 by jyurrita          #+#    #+#             */
/*   Updated: 2023/01/24 10:29:01 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	main(int argc, char *argv[])
{
	t_mlx_params	*mlx_params;
	t_map_params	*map_params;

	mlx_params = (t_mlx_params *)malloc(sizeof(t_mlx_params));
	inicialize_mlx_params(mlx_params);
	map_params = mlx_params->map_params;
	format_user_input(mlx_params, argc, argv);
	mlx_mouse_hook(mlx_params->mlx_win, mouse_event_handler, mlx_params);
	mlx_key_hook(mlx_params->mlx_win, key_hook, mlx_params);
	mlx_loop(mlx_params->mlx);
	return (0);
}
