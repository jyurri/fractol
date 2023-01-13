/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyurrita <jyurrita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:39:04 by jyurrita          #+#    #+#             */
/*   Updated: 2023/01/13 18:14:18 by jyurrita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <fractol.h>

static int mouse_event_handler(int button, int x, int y, t_mlx_params *mlx_params);
int key_hook(int key, t_mlx_params *mlx_params);
static void map_point(t_pos *pos_top, t_pos *center, double zoom);
static int check_num_iterations_mandelbrot(t_pos *point, int itera, int esc);
static void paint_mandelbrot(t_mlx_params *mlx_params, t_pos *center, double zoom);

int main(void)
{
	t_mlx_params	*mlx_params;
	
	//int color = 0x008000;
	mlx_params = (t_mlx_params *)malloc(sizeof(t_mlx_params));
	mlx_params->mlx = mlx_init();
	mlx_params->mlx_win = mlx_new_window(mlx_params->mlx, WIN_WIDTH, WIN_HEIGH, "Fractol");
	mlx_params->zoom = (double)(WIN_WIDTH/4);
	mlx_params->center = (t_pos *)malloc(sizeof(t_pos));
	mlx_params->center->x = WIN_WIDTH / 2;
	mlx_params->center->y = WIN_HEIGH / 2;
	paint_mandelbrot(mlx_params, mlx_params->center, mlx_params->zoom);
	mlx_mouse_hook(mlx_params->mlx_win, mouse_event_handler, mlx_params);
	mlx_key_hook(mlx_params->mlx_win, key_hook, mlx_params);
	mlx_loop(mlx_params->mlx);
	return (0);
}

int key_hook(int key, t_mlx_params *mlx_params) 
{
	int speed = WIN_WIDTH/20;
    if (key == 123) 
        mlx_params->center->x = mlx_params->center->x + speed;
    else if (key == 124) 
        mlx_params->center->x = mlx_params->center->x - speed;
    else if (key == 126) 
        mlx_params->center->y = mlx_params->center->y + speed;
    else if (key == 125) 
        mlx_params->center->y = mlx_params->center->y - speed;
    else if (key == 8) 
	{
		mlx_params->center->x = WIN_WIDTH / 2;
		mlx_params->center->y = WIN_HEIGH / 2;
		mlx_params->zoom = (double)(WIN_WIDTH/4);
		
	}
	paint_mandelbrot(mlx_params, mlx_params->center, mlx_params->zoom);
    return 0;
}

static int mouse_event_handler(int button, int x, int y, t_mlx_params *mlx_params)
{
	printf("%d, %d\n", x, y);
	if (button == 1) {
		mlx_params->center->x = mlx_params->center->x - (x - WIN_WIDTH / 2);
		mlx_params->center->y = mlx_params->center->y - (y - WIN_HEIGH / 2);
		mlx_params->zoom = mlx_params->zoom * 1.1;
		mlx_params->center->x = mlx_params->center->x * 1.1 ;
	}
    if (button == 5) {
		mlx_params->zoom = mlx_params->zoom * 1.1;
		mlx_params->center->x = mlx_params->center->x * 1.1 ;
    }
    else if (button == 4) {
        mlx_params->zoom = mlx_params->zoom / 1.1;
		mlx_params->center->x = mlx_params->center->x / 1.1 ;
		mlx_params->center->y = mlx_params->center->y / 1.1;
    }
	paint_mandelbrot(mlx_params, mlx_params->center, mlx_params->zoom);
    return 0;
}

static void map_point(t_pos *point, t_pos *center,double zoom)
{
	point->x = 	(double)point->map_x/(zoom/1.1) - center->x/zoom;
	point->y = (center->y - (double)point->map_y) /zoom;
}

static void paint_mandelbrot(t_mlx_params *mlx_params, t_pos *center, double zoom)
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
			map_point(point, center, zoom);
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