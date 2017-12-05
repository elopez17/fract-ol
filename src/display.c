/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 12:06:21 by eLopez            #+#    #+#             */
/*   Updated: 2017/12/05 12:43:39 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	fra_display(t_fra *f)
{
	mlx_string_put(f->mlx, f->win, 10, 10, 0x000000ff,
			"Scroll forward to Zoom-in");
	mlx_string_put(f->mlx, f->win, 10, 35, 0x000000ff,
			"Scroll backward to Zoom-out");
	mlx_string_put(f->mlx, f->win, 10, 60, 0x000000ff,
			"use mouse pointer for zoom direction");
	mlx_string_put(f->mlx, f->win, 10, 85, 0x0000ff00,
			"Press `ESC` to exit properly");
	mlx_string_put(f->mlx, f->win, 300, 300, 0x0000ff00, "|");
	mlx_string_put(f->mlx, f->win, 295, 300, 0x0000ff00, "--");
	if (f->fractal == julia)
		mlx_string_put(f->mlx, f->win, 10, 550, 0x000000ff,
			"Left-Click on mouse to pause image");
	mlx_string_put(f->mlx, f->win, 10, 575, 0x00ff0000,
		"Press 'r' to reset.");
}
