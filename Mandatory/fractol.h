/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <slimane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 22:48:38 by slimane           #+#    #+#             */
/*   Updated: 2025/02/15 22:28:48 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <math.h>
# include <mlx.h>

# define WID 700
# define HIT 700


typedef struct complex_n
{
	double real;
	double img;
}   t_complex;

typedef struct s_mlx {
	void    *mlx;
	void    *win;
	void    *img;
	char    *addr; 
	int     bpp;
	int     line_length;
	int     endian;
	double 	x_min;
	double 	x_max;
	double	y_min;
	double	y_max;
	double	*av;
	int		exist;
}           t_mlx;

double	ft_atof(const char *str, int *check);
int		mandelbort_julia(double real, double imag, t_mlx *mlx);
void	draw_mandel_julia(t_mlx *mlx);
int		ft_strcmp(char *s1, char *s2);

#endif