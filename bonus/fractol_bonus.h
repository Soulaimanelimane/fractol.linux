/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <slimane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 08:15:34 by slimane           #+#    #+#             */
/*   Updated: 2025/02/19 11:12:14 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
#define FRACTOL_BONUS_H
# include <math.h>
# include <stdlib.h>
# include <mlx.h>
#include <stdio.h>

# define WID 700
# define HIT 700
# define X_MIN -2.0
# define X_MAX 1.0
# define Y_MIN -1.5
# define Y_MIN -1.5


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
	double  move_x;
	double  move_y;
	int		color;
}           t_mlx;
void	draw_burning_ship(t_mlx *mlx);
int		burning_ship(double real, double imag);
double	map(double value, double in_min, double in_max, double out_min, double out_max);

#endif