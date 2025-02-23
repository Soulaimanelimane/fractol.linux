/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <slimane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 09:16:22 by slimane           #+#    #+#             */
/*   Updated: 2025/02/22 20:40:58 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"
#include <stdio.h>
int	get_color(int itr, t_mlx *mlx)
{
	if (itr == 70)
		return (0);
	if (mlx->color >= 24)
		mlx->color = 0;
	return (itr * 255 / 70) << mlx->color;
}


double map(double value, double in_min, double in_max, double out_min, double out_max)
{
	return out_min + (value - in_min) * (out_max - out_min) / (in_max - in_min);
}


void	burning_ship_pixel(t_mlx *mlx, int x, int y)
{
	double	real;
	double	imag;
	int		iter;
	int		color;
	int		pixl;
	char	*dest;

	real = map(x, 0, 700, mlx->x_min, mlx->x_max) - mlx->move_x;
	imag =  map(y, 0, 700, mlx->y_min, mlx->y_max) - mlx->move_y;
    iter = burning_ship(real, imag);
	color = get_color(iter, mlx);
	pixl = (y * mlx->line_length) + (x * (mlx->bpp / 8));
	dest = (mlx->addr + pixl);
	*(unsigned int *)dest = color;
}

void	draw_burning_ship(t_mlx *mlx)
{
	int		x;
	int		y;

	y = 0;
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, WID, HIT);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->line_length, &mlx->endian);
	if (mlx->addr == NULL)
		return ;
	while (y < HIT)
	{
		x = 0;
		while (x < WID)
		{
			burning_ship_pixel(mlx, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
