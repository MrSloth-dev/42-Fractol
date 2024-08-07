/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_bonus_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:03:51 by joao-pol          #+#    #+#             */
/*   Updated: 2024/06/11 14:57:22 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_point	ft_quartic(t_point z, t_point c)
{
	return (ft_sumsquare(ft_multiply(z, z), c));
}

//NEWTON z - (0.5 * ((z)^3 - 1) / (3 * z^2))
t_point	ft_newton(t_point z, t_point c)
{
	t_point	newton;
	t_point	square;
	t_point	one;
	t_point	half;

	(void)c;
	one = (t_point){.x = 1, .y = 1};
	half = (t_point){.x = 0.5, .y = 0.5};
	square = ft_multiply(z, z);
	square.x *= 3;
	square.y *= 3;
	newton = ft_subtract(z, ft_multiply(half, ft_divide(
					ft_subtract(ft_cube(z), one), square)));
	return (newton);
}

t_point	ft_calc(t_point z, t_point c, t_vars *vars)
{
	if (!ft_strncmp(vars->name, "newton", 6))
		return (ft_newton(z, c));
	else if (!ft_strncmp(vars->name, "quartic", 7))
		return (ft_quartic(z, c));
	else
		return (ft_sumsquare(z, c));
}
