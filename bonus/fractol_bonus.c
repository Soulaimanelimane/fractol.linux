/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <slimane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 08:15:08 by slimane           #+#    #+#             */
/*   Updated: 2025/02/19 11:09:59 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"
#include <libc.h>
void    init_mlx(t_mlx *mlx, char **av)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WID, HIT, av[1]);
	mlx->img = mlx_new_image(mlx->mlx, WID, HIT);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->line_length, &mlx->endian);
	if (mlx->addr == NULL)
		return ;
	mlx->x_max = 2.0;
	mlx->x_min = -2.0;
	mlx->y_max = 2.0;
	mlx->y_min = -2.0;
	mlx->move_x = 0;
	mlx->move_y = 0;
	mlx->color = 0;
}

int	close_mlx(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}

int	zoom_in_out(int button, int x, int y, t_mlx *mlx)
{
	double	zoom;
	double	mouse_x;
	double	mouse_y;

	zoom = 0;
	if (button == 4)
		zoom = 0.9;
	else if (button == 5)
		zoom = 1.1;
	else
		return 0;

	mouse_x = map(x, 0, 700, mlx->x_min, mlx->x_max);
	mouse_y = map(y, 0, 700, mlx->y_min, mlx->y_max);
	mlx->x_min = mouse_x + (mlx->x_min - mouse_x) * zoom;
	mlx->x_max = mouse_x + (mlx->x_max - mouse_x) * zoom;
	mlx->y_max = mouse_y + (mlx->y_max - mouse_y) * zoom;
	mlx->y_min = mouse_y + (mlx->y_min - mouse_y) * zoom;
	draw_burning_ship(mlx);
	return 0;
}

int	esc_close(int button, t_mlx *mlx)
{
	if (button == 53)
	{
		mlx_destroy_image(mlx->mlx, mlx->img);
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	else if (button == 123)
		mlx->move_x += 0.5;
	else if (button == 124)
		mlx->move_x -= 0.5;
	else if (button == 125)
		mlx->move_y -= 0.5;
	else if (button == 126)
		mlx->move_y += 0.5;
	else if (button == 1)
	{
		mlx->color += 2;
		printf("%d\n", mlx->color);	
	}
	draw_burning_ship(mlx);
	return (0);
}

int main(int ac, char *av[]){

    if (ac != 2)
		return (0);
    t_mlx   mlx;
    init_mlx(&mlx, av);
	draw_burning_ship(&mlx);
	mlx_mouse_hook(mlx.win, zoom_in_out, &mlx);
	mlx_hook(mlx.win, 17, 0, close_mlx, &mlx);
	mlx_key_hook(mlx.win, esc_close, &mlx);
    mlx_loop(mlx.mlx);
}