/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 00:06:40 by eLopez            #+#    #+#             */
/*   Updated: 2017/12/05 12:39:37 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <ft_printf.h>
# include <get_next_line.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# define MAX(a, b) (a > b ? a : b)
# define MIN(a, b) (a < b ? a : b)
# define KEYESC 53
# define KEYR 15
# define WIN_X 600
# define WIN_Y 600
# define RANGE_CHANGE(x,a,b,min,max) (((b)-(a))*((x)-(min))/((max)-(min)))+(a)
# define MAXITER 50

typedef struct	s_comp
{
	long double	a;
	long double	b;
	long double	comp_a;
	long double	comp_b;
	long double	aa;
	long double	bb;
}				t_comp;

typedef struct	s_point
{
	intmax_t	x;
	intmax_t	y;
}				t_point;

typedef struct	s_sierpinski
{
	t_point p1;
	t_point p2;
	t_point p3;
}				t_sier;

typedef struct	s_fractal
{
	void		*mlx;
	void		*img;
	char		*addr;
	int			bpp;
	int			s_line;
	int			endian;
	void		*win;
	void		(*fractal)();
	intmax_t	z;
	long double	scalar;
	intmax_t	mouse_x;
	intmax_t	mouse_y;
	t_point		julia;
	int			pause;
	int			level;
}				t_fra;

/*
**	These functions are used to set values ad reset.
*/
void			fra_init(t_fra *f);
void			fra_reset(t_fra *f);

/*
**	These functions implement the necessary procedure to produce specified
**		fractal: mandelbrot, julia, or sierpinski.
*/
void			mandelbrot(t_fra *f);
void			julia(t_fra *f);
void			sierpinski(t_fra *f);

/*
**	This function displays control instructions in window.
*/
void			fra_display(t_fra *f);

/*
**	These functions are used to catch events and handle expose.
*/
int				keypress(int key, t_fra *f);
int				mousepress(int key, int x, int y, t_fra *f);
int				motion_hook(int x, int y, t_fra *f);
int				expose_hook(t_fra *f);

/*
**	Utilities.
*/
void			putpixel(t_fra *f, int x, int y, int color);
int				get_color(int n);

/*
**	These functions are used to exit due to 'ESC' or error.
*/
void			fra_error(int error);
void			fra_exit(t_fra *f);

#endif
