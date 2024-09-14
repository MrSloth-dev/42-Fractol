/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:59:15 by joao-pol          #+#    #+#             */
/*   Updated: 2024/09/07 01:46:34 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_handler(int keysym, t_vars *vars)
{
	if (keysym == XK_Escape || keysym == XK_q)
		close_handler(vars);
	else if (keysym == XK_a || keysym == XK_Left)
		vars->offset_x -= (0.25 * vars->scale);
	else if (keysym == XK_d || keysym == XK_Right)
		vars->offset_x += (0.25 * vars->scale);
	else if (keysym == XK_w || keysym == XK_Up)
		vars->offset_y -= (0.25 * vars->scale);
	else if (keysym == XK_s || keysym == XK_Down)
		vars->offset_y += (0.25 * vars->scale);
	else if (keysym == 65451)
		vars->iter.max += 1;
	else if ((keysym == XK_minus || keysym == 65453) && vars->iter.max > 1)
		vars->iter.max -= 1;
	else if (keysym == XK_r)
	{
		vars->offset_x = 0;
		vars->offset_y = 0;
		vars->scale = 1;
		vars->iter.max = 42;
	}
	else if (keysym == XK_j)
		vars->toggle_julia = !vars->toggle_julia;
	help_handler(keysym, vars);
	return (0);
}

int	mouse_handler(int mousecode, int x, int y, t_vars *vars)
{
	if (mousecode == 1)
		vars->mousetrack = !vars->mousetrack;
	else if (mousecode == 2)
		vars->pointer = !vars->pointer;
	if (mousecode == 4)
	{
		vars->scale *= 0.9;
		if (vars->mousetrack)
		{
			vars->offset_x += (0.75 * (x - (double)IMG_WIDTH / 2)
					/ IMG_WIDTH * vars->scale);
			vars->offset_y += (0.75 * (y - (double)IMG_HEIGHT / 2)
					/ IMG_HEIGHT * vars->scale);
		}
	}
	else if (mousecode == 5)
		vars->scale /= 0.9;
	if (vars->toggle_julia)
		mlx_hook(vars->win, MotionNotify, PointerMotionMask, julia_track, vars);
	ft_refreshframe(vars);
	return (0);
}

int	close_handler(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->menu->img);
	mlx_destroy_image(vars->mlx, vars->img->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->menu);
	free(vars->img);
	free(vars->mlx);
	exit (0);
}

int	julia_track(int x, int y, t_vars *vars)
{
	if (!ft_strncmp(vars->name, "julia", 5) && vars->toggle_julia)
	{
		vars->julia_x = (ft_convert(x, vars->mandellimit_x, vars->winlimit_x)
				* vars->scale) + vars->offset_x;
		vars->julia_y = (ft_convert(y, vars->mandellimit_y, vars->winlimit_y)
				* vars->scale) + vars->offset_y;
		ft_refreshframe(vars);
	}
	return (0);
}

int	ft_refreshframe(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img->img);
	vars->img->img = mlx_new_image(vars->mlx, IMG_WIDTH, IMG_HEIGHT);
	vars->img->addr = mlx_get_data_addr(vars->img->img,
			&vars->img->bits_per_pixel,
			&vars->img->size_line, &vars->img->endian);
	if (vars->pointer)
		my_mlx_pixel_put(vars->img, IMG_WIDTH / 2, IMG_HEIGHT / 2, WHITE);
	ft_renderimage(vars);
	ft_helpmenu(vars);
	return (0);
}
