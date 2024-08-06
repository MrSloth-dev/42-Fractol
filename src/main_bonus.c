/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:54:37 by joao-pol          #+#    #+#             */
/*   Updated: 2024/06/13 16:54:18 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_check_errors(int argc, char *argv[]);

int	main(int argc, char *argv[])
{
	t_vars	vars;

	vars.name = argv[1];
	vars.program = argv[0];
	ft_check_errors(argc, argv);
	if (!ft_strncmp("julia", vars.name, 5))
	{
		vars.julia_x = ft_atodouble(argv[2]);
		vars.julia_y = ft_atodouble(argv[3]);
		if (vars.julia_x == -43.42 || vars.julia_y == -43.42)
		{
			perror(ERR_MSG_INPUT);
			exit (ERR_INPUT);
		}
	}
	ft_setup(&vars);
	ft_renderimage(&vars);
	mlx_loop(vars.mlx);
	return (0);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*pxl;

	if (x < IMG_WIDTH && y < IMG_HEIGHT)
	{
		pxl = data->addr + (y * data->size_line + x
				* (data->bits_per_pixel / 8));
		*(unsigned int *)pxl = color;
	}
}

static int	ft_check_errors(int argc, char *argv[])
{
	if ((!ft_strncmp(argv[1], "mandelbrot", 10) && argc == 2)
		|| (!ft_strncmp(argv[1], "julia", 5) && argc == 4))
		return (0);
	else
	{
		perror(ERR_MSG_INPUT);
		exit (ERR_INPUT);
	}
}
