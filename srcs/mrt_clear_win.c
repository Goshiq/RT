/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_clear_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 12:01:47 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/12 12:03:38 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	mrt_clear_win(t_scene **t)
{
	double	x;
	double	resx;
	double	y;
	double	resy;

	resx = (*t)->res->x / 2;
	resy = (*t)->res->y / 2;
	x = 0;
	y = 0;
	while (x++ < resx * 2)
	{
		while (y++ < resy * 2)
		{
			mlx_pixel_put((*t)->m_mlx, (*t)->m_win, x - 1, y - 1, 0);
		}
		y = 0;
	}
}
