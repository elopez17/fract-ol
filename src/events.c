/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:04:48 by eLopez            #+#    #+#             */
/*   Updated: 2017/12/03 10:10:28 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	keypress(int key, t_fra *f)
{
	if (key == KEYR)
		fra_reset(f);
	else if (key == KEYESC)
		fra_exit(f);
	f->fractal(f);
	return (0);
}

int	mousepress(int key, int x, int y, t_fra *f)
{
	if (key == 4)
	{
		f->scalar += 4.0;
		f->mouse_x += (x * 4);
		f->mouse_y += (y * 4);
		f->z = 150 * f->scalar;
	}
	else if (key == 5 && f->scalar >= 5.0)
	{
		f->scalar -= 4.0;
		f->mouse_x -= (x * 4);
		f->mouse_y -= (y * 4);
		f->z = 150 * f->scalar;
	}
	else if (key == 1)
		f->pause ^= 1;
	f->fractal(f);
	return (0);
}

int	motion_hook(int x, int y, t_fra *f)
{
	if (f->fractal == julia && !f->pause)
	{
		f->julia.x = x;
		f->julia.y = y;
		f->fractal(f);
	}
	return (0);
}

int	expose_hook(t_fra *f)
{
	f->fractal(f);
	return (0);
}
