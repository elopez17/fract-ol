/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 20:06:13 by eLopez            #+#    #+#             */
/*   Updated: 2017/12/03 20:30:15 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	get_color(int n)
{
	static int	colors[50] = { 0xf, 0x2f, 0x4f, 0x6f, 0x8f, 0xaf, 0xcf, 0xff,
0xff, 0x1f, 0x3f, 0x5f, 0x7f, 0x9f, 0xbf, 0xdf, 0xff, 0x1ff, 0x3ff, 0x5ff,
0x7ff, 0x9ff, 0x8b6508, 0xcd950c, 0xffb90f, 0xcd950c, 0xb8860b, 0x8b6508, 0x0,
0x330000, 0x7f0000, 0xb20000, 0x7f0000, 0x660000, 0x330000, 0x8f, 0x6f, 0x4f,
0x2f, 0xf, 0xb00ff, 0x7fff, 0xbfff, 0xdfff, 0xffff, 0xffffff, 0xffffff,
0xffffff, 0xffff00, 0x0};

	if (n == 0)
		return (0x0a);
	return (colors[n-1]);
}
