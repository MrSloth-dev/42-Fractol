/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:43:11 by joao-pol          #+#    #+#             */
/*   Updated: 2024/05/27 15:19:59 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_convert(double i, t_limit new, t_limit old)
{
	return ((new.max - new.min) *(i - old.min) / (old.max - old.min) + new.min);
}

t_point	ft_sumsquare(t_point z, t_point c)
{
	t_point	square;
	t_point	sum;

	square.x = (z.x * z.x) - (z.y * z.y);
	square.y = 2 * (z.x * z.y);
	sum.x = square.x + c.x;
	sum.y = square.y + c.y;
	return (sum);
}

double	ft_atodouble(char *str)
{
	double	dec;
	double	fractional;
	long	integer;
	int		neg;

	if (ft_isdigit(str) == 0)
		return (-43.42);
	neg = 1;
	integer = 0;
	fractional = 0;
	dec = 1;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			neg = -1;
	while (str && *str != '.')
		integer = (integer * 10) + (*str++ - 48);
	if (*str == '.')
		str++;
	while (*str)
	{
		dec /= 10;
		fractional = fractional + (*str++ - 48) * dec;
	}
	return ((integer + fractional) * neg);
}
