/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:09:45 by joao-pol          #+#    #+#             */
/*   Updated: 2024/06/13 16:52:18 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractal(double x, double y, t_vars *vars)
{
	t_point	z;
	t_point	c;
	int		color;
	int		iter;

	iter = 0;
	c = (t_point){.x = 0, .y = 0};
	z.x = (ft_convert(x, vars->mandellimit_x, vars->winlimit_x)
			* vars->scale) + vars->offset_x;
	z.y = (ft_convert(y, vars->mandellimit_y, vars->winlimit_y)
			* vars->scale) + vars->offset_y;
	ft_choose_fractal(&z, &c, vars);
	while (iter++ < vars->iter.max)
	{
		z = ft_calc(z, c, vars);
		if ((z.x * z.x) * (z.y * z.y) > 4)
		{
			color = ft_convert(iter, vars->color, vars->iter);
			my_mlx_pixel_put(vars->img, x, y, color);
			return ;
		}
	}
}

void	ft_renderimage(t_vars *vars)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < IMG_HEIGHT)
	{
		x = 0;
		while (x < IMG_WIDTH)
		{
			draw_fractal(x, y, vars);
			x += STEP;
		}
		y += STEP;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img,
		(WIN_WIDTH - IMG_WIDTH) / 2, (WIN_HEIGHT - IMG_HEIGHT) / 2);
}

void	ft_choose_fractal(t_point *z, t_point *c, t_vars *vars)
{
	if (!ft_strncmp(vars->name, "julia", 2))
		*c = (t_point){.x = vars->julia_x, .y = vars->julia_y};
	else
		*c = (t_point){.x = z->x, .y = z->y};
}

t_point	ft_calc(t_point z, t_point c, t_vars *vars)
{
	vars->mousetrack = vars->mousetrack;
	return (ft_sumsquare(z, c));
}
