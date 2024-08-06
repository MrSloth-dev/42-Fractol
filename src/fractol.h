/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:13:48 by joao-pol          #+#    #+#             */
/*   Updated: 2024/06/13 16:12:18 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define ERR_MSG_INPUT "WARNING!\nUsage\n\t\"./fractol mandelbrot\"\
	\n\tor\n\t\"./fractol_bonus julia <real> <imag>\"\n"
# define ERR_MSG_INPUT_BONUS "WARNING!\nUsage\n\t\"./fractol_bonus mandelbrot\"\
	\n\tor\n\t\"./fractol_bonus julia <real> <imag>\"\n \
	or\n\t\"./fractol_bonus newton\"\n \
	or\n\t\"./fractol_bonus quartic\"\n"
# define ERR_INPUT 1
# define ERR_MSG_MLX "Error in MLX"
# define ERR_MLX 2
# define WIN_HEIGHT 600
# define WIN_WIDTH 800
# define IMG_HEIGHT 600
# define IMG_WIDTH 800
# define PRECISION 7
# define STEP 1

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_limit
{
	double	min;
	double	max;
}	t_limit;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_img;

typedef struct s_vars
{
	char		*program;
	char		*name;
	void		*mlx;
	void		*win;
	t_img		*img;
	t_limit		winlimit_x;
	t_limit		winlimit_y;
	t_limit		mandellimit_x;
	t_limit		mandellimit_y;
	t_limit		color;
	t_limit		iter;
	double		scale;
	double		offset_x;
	double		offset_y;
	double		julia_x;
	double		julia_y;
	int			toggle_julia;
	int			mousetrack;
	int			pointer;
	int			help;
	t_img		*menu;
}				t_vars;

//INITIALIZE
int		ft_setup(t_vars *vars);
void	ft_displayintro(char *program);
void	ft_menu_init(t_vars *vars);
//EVENTS
int		key_handler(int keycode, t_vars *vars);
int		mouse_handler(int mousecode, int x, int y, t_vars *vars);
int		help_handler(int keysym, t_vars *vars);
int		close_handler(t_vars *vars);
int		julia_track(int x, int y, t_vars *vars);
////GRAPHICS  AND CALCULATIONS
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
int		ft_drawimage(t_vars *vars);
void	ft_choose_fractal(t_point *z, t_point *c, t_vars *vars);
void	ft_renderimage(t_vars *vars);
int		ft_refreshframe(t_vars *vars);
t_point	ft_nova(t_point z, t_point c);
t_point	ft_newton(t_point z, t_point c);
t_point	ft_calc(t_point z, t_point c, t_vars *vars);
//MATH
double	ft_convert(double i, t_limit new, t_limit old);
double	ft_atodouble(char *str);
t_point	ft_sum(t_point z1, t_point z2);
t_point	ft_square(t_point z);
t_point	ft_sumsquare(t_point z, t_point c);
t_point	ft_cube(t_point a);
t_point	ft_divide(t_point a, t_point b);
t_point	ft_subtract(t_point a, t_point b);
t_point	ft_add(t_point a, t_point b);
t_point	ft_multiply(t_point a, t_point b);
//STRINGS
int		ft_strncmp(char *s1, char *s2, size_t n);
int		ft_isdigit(char *str);
void	ft_helpmenu(t_vars *vars);

# define WHITE          0xFFFFFF  // Pure white (all channels at max)
# define BLACK          0x000000  // Pure black (all channels at min)
# 
// Basic psychedelic colors
# define PSYCHEDELIC_RED  0xFF00FF  // Magenta
# define PSYCHEDELIC_GREEN 0x00FF00  // Lime green
# define PSYCHEDELIC_BLUE  0x00FFFF  // Cyan
# 
// Additional psychedelic colors
# define LAVENDER_HUE      0xCCFFFF  // Light lavender with a blueish tint
# define TROPICAL_TEAL     0x33CC99  // Deep teal with a hint of green
# define SUNSET_ORANGE    0xFF9933  // Rich orange reminiscent of a sunset

#endif //FRACTOL_H
