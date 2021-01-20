/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_init_structs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:03:27 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/20 19:51:14 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_res(t_res **t)
{
	(*t)->x = 0;
	(*t)->y = 0;
}

void	init_sc(t_scene **t)
{
	if (!((*t)->m_mlx = mlx_init()))
		mrt_doerr("Can't init MLX\n", 0x0, t);
	(*t)->m_win = 0x0;
	(*t)->m_img = 0x0;
	(*t)->res = 0x0;
	(*t)->figs = 0x0;
	(*t)->cams = 0x0;
	(*t)->lghts = 0x0;
	(*t)->alght = 0x0;
	(*t)->ptr = 0x0;
	(*t)->fd = -1;
}

void	init_cams(t_cams **t)
{
	(*t)->c_crd = pnts_to_vec(0, 0, 0);
	(*t)->n_crd = pnts_to_vec(0, 0, 0);
	(*t)->fov = -1;
	(*t)->d = -1;
	(*t)->c_scr = pnts_to_vec(0, 0, 0);
	(*t)->px = pnts_to_vec(0, 0, 0);
	(*t)->py = pnts_to_vec(0, 0, 0);
	(*t)->next = 0x0;
	(*t)->prev = 0x0;
}

void	init_lghts(t_lght **t)
{
	(*t)->next = 0x0;
	(*t)->bright = -1;
	(*t)->c_crd = pnts_to_vec(0, 0, 0);
	(*t)->clr = make_clr(0, 0, 0);
}

void	init_figs(t_figs **t)
{
	(*t)->type = DEF;
	(*t)->data = 0x0;
	(*t)->next = 0x0;
}
