/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialize_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:53:05 by jyurrita          #+#    #+#             */
/*   Updated: 2023/01/24 09:34:40 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	inicialize_mlx_params(t_mlx_params *mlx_params)
{
	t_map_params	*map_params;

	mlx_params->mlx = mlx_init();
	mlx_params->mlx_win = mlx_new_window(mlx_params->mlx,
			WIN_WIDTH, WIN_HEIGH, "Fractol");
	map_params = (t_map_params *)malloc(sizeof(t_map_params));
	inicialize_map_params(map_params);
	mlx_params->map_params = map_params;
}
