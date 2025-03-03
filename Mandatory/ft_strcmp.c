/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <slimane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:58:16 by slimane           #+#    #+#             */
/*   Updated: 2025/02/23 23:49:34 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mlx_init_av(t_mlx *mlx, char **av)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (-1);
	mlx->win = mlx_new_window(mlx->mlx, WID, HIT, av[1]);
	if (!mlx->win)
		return (-1);
	mlx->img = mlx_new_image(mlx->mlx, WID, HIT);
	if (!mlx->img)
	{
		mlx_destroy_window(mlx->mlx ,mlx->win);
		return (-1);
	}
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->line_length,
		&mlx->endian);
	if (mlx->addr == NULL)
	{
		mlx_destroy_window(mlx->mlx ,mlx->win);
		mlx_destroy_image(mlx->mlx, mlx->img);
		return (-1);
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s1)
		return (-1);
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
