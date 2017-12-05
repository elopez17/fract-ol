/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:17:33 by eLopez            #+#    #+#             */
/*   Updated: 2017/12/03 21:23:44 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#define MIDPOINT(x1, x2) (x1 + x2) / 2;

static void	fill_tri(t_fra *f, t_sier s)
{
	t_point		p;
	long double	slope;
	int			color;

	color = RANGE_CHANGE(s.p1.y, 0xffffff, 0xf, 0, WIN_Y);
	while (s.p1.y <= s.p2.y)
	{
		p = s.p1;
		slope = 0.5774;
		while (p.y <= s.p3.y)
		{
			putpixel(f, p.x + (int)slope, p.y, color);
			putpixel(f, p.x - (int)slope, p.y++, color);
			slope += 0.5774;
		}
		++s.p1.y;
	}
}

static void	sierpinski_recur(t_fra *f, t_sier s, int level)
{
	t_sier		j;

	if (level == 1)
		return (fill_tri(f, s));
	j.p1.x = MIDPOINT(s.p1.x, s.p2.x);
	j.p1.y = MIDPOINT(s.p1.y, s.p2.y);
	j.p2.x = MIDPOINT(s.p2.x, s.p3.x);
	j.p2.y = MIDPOINT(s.p2.y, s.p3.y);
	j.p3.x = MIDPOINT(s.p1.x, s.p3.x);
	j.p3.y = MIDPOINT(s.p1.y, s.p3.y);
	sierpinski_recur(f, (t_sier){s.p1, j.p1, j.p3}, level - 1);
	sierpinski_recur(f, (t_sier){j.p1, s.p2, j.p2}, level - 1);
	sierpinski_recur(f, (t_sier){j.p3, j.p2, s.p3}, level - 1);
}

void		sierpinski(t_fra *f)
{
	t_sier	s;

	s.p1.x = (300 * f->scalar) - f->mouse_x;
	s.p1.y = (117 * f->scalar) - f->mouse_y;
	s.p2.x = (50 * f->scalar) - f->mouse_x;
	s.p2.y = (550 * f->scalar) - f->mouse_y;
	s.p3.x = (550 * f->scalar) - f->mouse_x;
	s.p3.y = (550 * f->scalar) - f->mouse_y;
	f->img = mlx_new_image(f->mlx, WIN_X, WIN_Y);
	f->addr = mlx_get_data_addr(f->img, &(f->bpp), &(f->s_line), &(f->endian));
	sierpinski_recur(f, s, f->level);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	mlx_destroy_image(f->mlx, f->img);
	fra_display(f);
}
