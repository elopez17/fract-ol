/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:17:33 by eLopez            #+#    #+#             */
/*   Updated: 2017/12/05 12:42:58 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static int	julia_iter(t_comp *j, t_point screen)
{
	int		n;
	float	comp_a;
	float	comp_b;

	comp_a = RANGE_CHANGE(screen.x, -1.0, 1.0, 0.0, WIN_X);
	comp_b = RANGE_CHANGE(screen.y, -1.0, 1.0, 0.0, WIN_Y);
	n = -1;
	while (++n < MAXITER)
	{
		j->aa = (j->a * j->a) - (j->b * j->b);
		j->bb = 2.0 * j->a * j->b;
		j->a = j->aa + comp_a;
		j->b = j->bb + comp_b;
		if (j->a * j->a + j->b * j->b > 16)
			return (n);
	}
	return (n);
}

void		julia(t_fra *f)
{
	t_comp		j;
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
			j.a = (long double)x / f->z + -2.1;
			j.b = (long double)y / f->z + -2.1;
			j.comp_a = j.a;
			j.comp_b = j.b;
			putpixel(f, x - f->mouse_x, y - f->mouse_y,\
					get_color(julia_iter(&j, f->julia)));
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	mlx_destroy_image(f->mlx, f->img);
	fra_display(f);
}
