/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:00:15 by eLopez            #+#    #+#             */
/*   Updated: 2017/12/03 20:40:44 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	fra_init(t_fra *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIN_X, WIN_Y, "42 fractal");
	f->z = 150;
	f->scalar = 1.0;
	f->mouse_x = 0;
	f->mouse_y = 0;
	f->julia.x = 100;
	f->julia.y = 100;
	f->pause = 0;
	f->level = 15;
}

void	fra_reset(t_fra *f)
{
	f->z = 150;
	f->scalar = 1.0;
	f->mouse_x = 0;
	f->mouse_y = 0;
	f->pause = 0;
}
