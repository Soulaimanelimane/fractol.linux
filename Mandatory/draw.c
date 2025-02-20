/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <slimane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 00:12:54 by slimane           #+#    #+#             */
/*   Updated: 2025/02/18 19:19:00 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int itr)
{
	if (itr == 70)
		return (0x000000);
	return (itr * 255 / 70);
}

double	map(double value, t_mlx *mlx)
{
	return (mlx->x_min + value * (mlx->x_max  - mlx->x_min) / 700);
}

void	mandelbrot_pixel(t_mlx *mlx, int x, int y)
{
	double	real;
	double	imag;
	int		iter;
	int		color;
	int		pixl;
	char	*dest;

	real = map(x ,mlx);
	imag = map(y, mlx);
    if (mlx->exist == 0)
        iter = mandelbort_julia(real, imag, mlx);
    else
        iter = mandelbort_julia(real, imag, mlx);
	color = get_color(iter);
	pixl = (y * mlx->line_length) + (x * (mlx->bpp / 8));
	dest = (mlx->addr + pixl);
	*(unsigned int *)dest = color;
}

void	draw_mandel_julia(t_mlx *mlx)
{
	int		x;
	int		y;

	y = 0;
	while (y < HIT)
	{
		x = 0;
		while (x < WID)
		{
			mandelbrot_pixel(mlx, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
