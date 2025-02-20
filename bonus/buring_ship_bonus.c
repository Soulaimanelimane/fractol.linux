/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buring_ship_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <slimane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 09:20:48 by slimane           #+#    #+#             */
/*   Updated: 2025/02/19 11:11:56 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int burning_ship(double real, double imag)
{
    t_complex   z;
    double      tmp;
    int         i;

    i = 0;
	z.real = 0;
	z.img = 0;
	while (z.real * z.real + z.img * z.img <= 4 && i < 70)
	{
		tmp =  pow(z.real, 2) -  pow(z.img, 2) + real;
		z.img = fabs(2 * (z.img * z.real) + imag);
		z.real = fabs(tmp);
		i++;
	}
	return (i);
}
