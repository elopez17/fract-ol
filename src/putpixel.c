/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpixel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:33:42 by eLopez            #+#    #+#             */
/*   Updated: 2017/11/29 10:35:51 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	putpixel(t_fra *f, int x, int y, int color)
{
	int i;

	if (x < 0 || x >= WIN_X || y < 0 || y >= WIN_Y)
		return ;
	i = (f->bpp / 8) * x + f->s_line * y;
	if (f->endian == 0)
	{
		f->addr[i++] = (0x000000ff & color);
		f->addr[i++] = (0x0000ff00 & color) >> 8;
		f->addr[i++] = (0x00ff0000 & color) >> 16;
		f->addr[i++] = (0xff000000 & color) >> 24;
	}
}
