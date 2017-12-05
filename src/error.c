/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:43:48 by eLopez            #+#    #+#             */
/*   Updated: 2017/12/05 12:41:21 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	fra_error(int error)
{
	static char	*msg[] = {
		"missing/invalid parameter"
	};

	ft_printf("fractol: %{RD}%s%{NC}\n\
usage: ./fractol [julia, mandelbrot, sierpinski]\n", msg[error]);
	exit(0);
}
