/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <slimane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:52:36 by slimane           #+#    #+#             */
/*   Updated: 2025/02/22 13:14:49 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_error_nothing(void)
{
		write(2, "╔══════════════════════════════════════════╗\n", 134);
		write(2, "║       Usage: ./fractol <fractal>         ║\n", 50);
		write(2, "╚══════════════════════════════════════════╝\n", 134);
		write(2, "           ╔════════════════════╗           \n", 90);
		write(2, "╔══════════╣ Available fractals ╠══════════╗\n", 94);
		write(2, "║          ╚════════════════════╝          ║\n", 94);
		write(2, "║                                          ║\n", 50);
		write(2, "║                mandelbrot                ║\n", 50);
		write(2, "║                julia x y                 ║\n", 50);
		write(2, "║                                          ║\n", 50);
		write(2, "╚══════════════════════════════════════════╝\n", 134);
		exit(0);
}

void	set_complex(t_complex *f, double real, double img)
{
	f->real = real;
	f->img = img;
}

int	mandelbort_julia(double real, double imag, t_mlx *mlx)
{
	double		tmp;
	double		c_real;
	double		c_img;
	t_complex	z;
	int			i;

	if (mlx->exist == 0)
	{
		(set_complex(&z, 0, 0), c_real = real);
		c_img = imag;
	}
	else
	{
		(set_complex(&z, real, imag), c_real = mlx->av[0]);
		c_img = mlx->av[1];
	}
	i = 0;
	while (z.real * z.real + z.img * z.img <= 4 && i < 70)
	{
		tmp = z.real * z.real - z.img * z.img + c_real;
		z.img = 2 * (z.img * z.real) + c_img;
		z.real = tmp;
		i++;
	}
	return (i);
}
