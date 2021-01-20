/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_put_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 14:23:15 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/20 21:30:10 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	put_pixel(t_scene **t, t_doub xy, int clr, int save)
{
	if (save)
		mrt_saver(t, xy, clr);
	else
		mlx_pixel_put((*t)->m_mlx, (*t)->m_win, xy.x, xy.y, clr);
}
