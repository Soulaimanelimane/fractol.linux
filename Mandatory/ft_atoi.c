/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <slimane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:11:51 by slimane           #+#    #+#             */
/*   Updated: 2025/02/15 21:18:22 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_help_atof(const char *str, double sign, int *i, int *check)
{
	double	div;
	double	result;

	div = 1.0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		result = result * 10.0 + (str[*i] - '0');
		(*i)++;
	}
	if (str[*i] == '.')
	{
		(*i)++;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			div *= 10.0;
			result += (str[*i] - '0') / div;
			if (result > 2.0)
				return (*check = 1, *check);
			(*i)++;
		}
	}
	return (result * sign);
}

double	ft_atof(const char *str, int *check)
{
	double	result;
	double	sign;
	int		i;

	result = 0.0;
	sign = 1.0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1.0;
		i++;
	}
	result = ft_help_atof(&str[i], sign, &i, check);
	if (str[i] != '\0' || *check == 1)
		return (*check = 1, *check);
	return (result);
}
