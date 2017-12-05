/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:17:33 by eLopez            #+#    #+#             */
/*   Updated: 2017/12/05 12:43:52 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static int	mandel_iter(t_comp *m)
{
	int n;

	n = -1;
	while (++n < MAXITER)
	{
		m->aa = (m->a * m->a) - (m->b * m->b);
		m->bb = 2.0 * m->a * m->b;
		m->a = m->aa + m->comp_a;
		m->b = m->bb + m->comp_b;
		if (m->a * m->a + m->b * m->b > 16)
			return (n);
	}
	return (n);
}

void		mandelbrot(t_fra *f)
{
	t_comp		m;
	intmax_t	x;
	intmax_t	y;

	y = -1 + f->mouse_y;
	f->img = mlx_new_image(f->mlx, WIN_X, WIN_Y);
	f->addr = mlx_get_data_addr(f->img, &(f->bpp), &(f->s_line), &(f->endian));
	while (++y < WIN_Y + f->mouse_y)
	{
		x = -1 + f->mouse_x;
		while (++x < WIN_X + f->mouse_x)
		{
			m.a = (long double)x / f->z + -2.1;
			m.b = (long double)y / f->z + -2.1;
			m.comp_a = m.a;
			m.comp_b = m.b;
			putpixel(f, x - f->mouse_x, y - f->mouse_y,\
					get_color(mandel_iter(&m)));
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	mlx_destroy_image(f->mlx, f->img);
	fra_display(f);
}
