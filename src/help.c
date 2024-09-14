/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:46:21 by joao-pol          #+#    #+#             */
/*   Updated: 2024/06/13 16:51:00 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_refreshmenu(t_vars *vars);

int	help_handler(int keysym, t_vars *vars)
{
	if (keysym == XK_h)
		vars->help = !vars->help;
	ft_refreshframe(vars);
	ft_helpmenu(vars);
	return (0);
}

void	ft_helpmenu(t_vars *vars)
{
	auto int offset = WIN_WIDTH - 230;
	ft_refreshmenu(vars);
	if (vars->help)
	{
		mlx_string_put(vars->mlx, vars->win, offset, 20, WHITE,
			"Press 'h' to close help        MENU");
		mlx_string_put(vars->mlx, vars->win, offset, 40, WHITE,
			"Scroll to Zoom");
		mlx_string_put(vars->mlx, vars->win, offset, 60, WHITE,
			"Keys or WASD to Move");
		mlx_string_put(vars->mlx, vars->win, offset, 80, WHITE,
			"'+' to increment iterations");
		mlx_string_put(vars->mlx, vars->win, offset, 100, WHITE,
			"'-' to decrement iterations");
		mlx_string_put(vars->mlx, vars->win, offset, 120, WHITE,
			"Press 'r' to reset");
		mlx_string_put(vars->mlx, vars->win, offset, 140, WHITE,
			"MousePressLeft to follow cursor");
		if (!ft_strncmp("julia", vars->name, 5))
			mlx_string_put(vars->mlx, vars->win, offset, 160, WHITE,
				"Press 'j' to activate mouse listener");
	}
	else
		mlx_string_put(vars->mlx, vars->win, offset, 20, WHITE,
			"Press 'h' to open help");
}

static int	ft_refreshmenu(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->menu->img);
	if (vars->help)
	{
		if (ft_strncmp("julia", vars->name, 5))
			vars->menu->img = mlx_new_image(vars->mlx, 225, 140);
		else
			vars->menu->img = mlx_new_image(vars->mlx, 225, 170);
		vars->menu->addr = mlx_get_data_addr(vars->menu->img,
				&vars->menu->bits_per_pixel,
				&vars->menu->size_line, &vars->menu->endian);
	}
	else
	{
		vars->menu->img = mlx_new_image(vars->mlx, 225, 20);
		vars->menu->addr = mlx_get_data_addr(vars->menu->img,
				&vars->menu->bits_per_pixel,
				&vars->menu->size_line, &vars->menu->endian);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->menu->img,
		WIN_WIDTH - 235, 5);
	if (vars->pointer)
		my_mlx_pixel_put(vars->img, IMG_WIDTH / 2, IMG_HEIGHT / 2, WHITE);
	return (0);
}

void	ft_menu_init(t_vars *vars)
{
	vars->menu = (t_img *)malloc(sizeof(t_img));
	if (!vars->menu)
	{
		mlx_destroy_image(vars->mlx, vars->menu);
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit (ERR_MLX);
	}
	vars->menu->img = mlx_new_image(vars->mlx, 10, 10);
	vars->menu->addr = mlx_get_data_addr(vars->menu->img,
			&vars->menu->bits_per_pixel,
			&vars->menu->size_line,
			&vars->menu->endian);
}
