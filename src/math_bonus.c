/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:48:30 by joao-pol          #+#    #+#             */
/*   Updated: 2024/05/27 16:23:50 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_point	ft_multiply(t_point a, t_point b)
{
	t_point	result;

	result.x = a.x * b.x - a.y * b.y;
	result.y = a.x * b.y + a.y * b.x;
	return (result);
}

t_point	ft_add(t_point a, t_point b)
{
	t_point	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	return (result);
}

t_point	ft_subtract(t_point a, t_point b)
{
	t_point	result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	return (result);
}

t_point	ft_divide(t_point a, t_point b)
{
	t_point	result;
	double	denominator;

	denominator = b.x * b.x + b.y * b.y;
	result.x = (a.x * b.x + a.y * b.y) / denominator;
	result.y = (a.y * b.x - a.x * b.y) / denominator;
	return (result);
}

t_point	ft_cube(t_point a)
{
	t_point	result;

	result = ft_multiply(a, a);
	result = ft_multiply(result, a);
	return (result);
}
