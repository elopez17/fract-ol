/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:43:48 by eLopez            #+#    #+#             */
/*   Updated: 2017/11/27 16:39:01 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	fra_error(int error)
{
	char	*msg[] =
	{
		"missing/invalid parameter"
	};
	ft_printf("fractol: %{RD}%s%{NC}\n\
usage: ./fractol [julia, mandelbrot, sierpinski]\n", msg[error]);
	exit(0);
}
