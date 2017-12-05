/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:44:26 by eLopez            #+#    #+#             */
/*   Updated: 2017/11/27 19:19:50 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int			main(int argc, char **argv)
{
	t_fra	f;

	if (ft_strcmp(argv[--argc], "mandelbrot") == 0 && argc == 1)
		f.fractal = mandelbrot;
	else if (ft_strcmp(argv[argc], "julia") == 0 && argc == 1)
		f.fractal = julia;
	else if (ft_strcmp(argv[argc], "sierpinski") == 0 && argc == 1)
		f.fractal = sierpinski;
	else
		fra_error(0);
	fra_init(&f);
	f.fractal(&f);
	mlx_hook(f.win, 2, 0, keypress, &f);
	mlx_hook(f.win, 4, 0, mousepress, &f);
	mlx_hook(f.win, 6, 0, motion_hook, &f);
	mlx_hook(f.win, 12, 0, expose_hook, &f);
	mlx_loop(f.mlx);
	return (0);
}
