/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <slimane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:33:15 by slimane           #+#    #+#             */
/*   Updated: 2025/02/23 22:29:38 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	zoom_in_out(int button, int x, int y, t_mlx *mlx)
{
	double	zoom;

	zoom = 0;
	if (button == 4)
		zoom = 0.9;
	else if (button == 5)
		zoom = 1.1;
	else
		return 0;
	x = x * 1;
	y = y * 1;
	mlx->x_min = mlx->x_min * zoom;
	mlx->x_max = mlx->x_max * zoom;
	mlx->y_max = mlx->y_max  * zoom;
	mlx->y_min = mlx->y_min  * zoom;
	draw_mandel_julia(mlx);
	return 0;
}

void	init_mlx(t_mlx *mlx, char **av)
{
	int	check;

	check = 0;
	if (mlx->exist)
	{
		mlx->av = malloc(2 * sizeof(double));
		mlx->av[0] = ft_atof(av[2], &check);
		mlx->av[1] = ft_atof(av[3], &check);
		if (check == 1)
			(free(mlx->av), exit(1));
	}
	if (ft_mlx_init_av(mlx, av) == -1)
	{
		free(mlx->av);
		exit(1);
	}
	mlx->x_max = 2.0;
	mlx->x_min = -2.0;
	mlx->y_max = 2.0;
	mlx->y_min = -2.0;
}

int	close_mlx(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}
int	esc_close(int button, t_mlx *mlx)
{
	if (button == 53)
	{
		mlx_destroy_image(mlx->mlx, mlx->img);
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	return (0);
}

void f (){
	system("leaks -q fractol");
}
int main(int ac, char *av[])
{
	t_mlx    mlx;
	atexit(f);
	if (ac == 1)
		return (0);
	if (ft_strcmp(av[1], "julia\0") == 0 && ac != 4)
	{
		write(1,"\033[31m./fractol julia num1 num2\n",31);
		return (0);
	}
	if (ft_strcmp(av[1], "mandelbrot\0") == 0 && ac != 2)
	{
		write(1,"\033[31m./fractol mandelbrot \n",31);
		return (0);
	}
	if (ft_strcmp(av[1], "julia\0") && ft_strcmp(av[1], "mandelbrot\0"))
		ft_error_nothing();
	if (ft_strcmp(av[1], "mandelbrot\0") == 0)
		mlx.exist = 0;
	else
		mlx.exist = 1;
	(init_mlx(&mlx, av), draw_mandel_julia(&mlx));
	mlx_mouse_hook(mlx.win, zoom_in_out, &mlx);
	mlx_hook(mlx.win, 17, 0, close_mlx, &mlx);
	mlx_key_hook(mlx.win, esc_close, &mlx);
	mlx_loop(mlx.mlx);
}

