/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:01:57 by joao-pol          #+#    #+#             */
/*   Updated: 2024/06/13 15:18:22 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_events_init(t_vars *vars);
static void	ft_mallocerror(void);
static void	ft_data_init(t_vars *vars);
static void	ft_mlx_init(t_vars *vars);

int	ft_setup(t_vars *vars)
{
	ft_mlx_init(vars);
	ft_data_init(vars);
	ft_events_init(vars);
	return (0);
}

static void	ft_data_init(t_vars *vars)
{
	vars->iter = (t_limit){.min = 0, .max = 42};
	vars->scale = 1.0;
	vars->mousetrack = 0;
	vars->pointer = 0;
	vars->offset_x = 0.0;
	vars->offset_y = 0.0;
	vars->color = (t_limit){.min = 0x0f0f00, .max = SUNSET_ORANGE};
	vars->winlimit_x = (t_limit){.min = 0.0, .max = IMG_WIDTH};
	vars->winlimit_y = (t_limit){.min = 0.0, .max = IMG_HEIGHT};
	vars->mandellimit_x = (t_limit){.min = -2.0, .max = 2.0};
	vars->mandellimit_y = (t_limit){.min = -2.0, .max = 2.0};
	vars->toggle_julia = 0;
	vars->help = 0;
}

static void	ft_mlx_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		ft_mallocerror();
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT, vars->name);
	if (vars->win == NULL)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(ERR_MLX);
	}
	vars->img = (t_img *)malloc(sizeof(t_img));
	if (!vars->img)
	{
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit (ERR_MLX);
	}
	vars->img->img = mlx_new_image(vars->mlx, IMG_WIDTH, IMG_HEIGHT);
	vars->img->addr = mlx_get_data_addr(vars->img->img,
			&vars->img->bits_per_pixel, &vars->img->size_line,
			&vars->img->endian);
}

static void	ft_events_init(t_vars *vars)
{
	mlx_hook(vars->win, KeyPress, KeyPressMask, key_handler, vars);
	mlx_hook(vars->win, ButtonPress, ButtonPressMask, mouse_handler, vars);
	mlx_hook(vars->win, DestroyNotify, StructureNotifyMask, close_handler,
		vars);
	mlx_hook(vars->win, MotionNotify, PointerMotionMask, julia_track, vars);
}

static void	ft_mallocerror(void)
{
	perror("Problem with Malloc!");
	exit(ERR_MLX);
}
