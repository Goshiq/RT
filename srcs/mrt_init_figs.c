/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_init_figs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 11:35:22 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/19 11:48:14 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_cy(t_cy **t)
{
	(*t)->c_crd = pnts_to_vec(0, 0, 0);
	(*t)->n_crd = pnts_to_vec(0, 0, 0);
	(*t)->diam = 0.0;
	(*t)->height = 0.0;
	(*t)->clr = make_clr(0, 0, 0);
}

void	init_pl(t_pl **t)
{
	(*t)->c_crd = pnts_to_vec(0, 0, 0);
	(*t)->n_crd = pnts_to_vec(0, 0, 0);
	(*t)->clr = make_clr(0, 0, 0);
}

void	init_sq(t_sq **t)
{
	(*t)->c_crd = pnts_to_vec(0, 0, 0);
	(*t)->n_crd = pnts_to_vec(0, 0, 0);
	(*t)->side = 0.0;
	(*t)->clr = make_clr(0, 0, 0);
}

void	init_sp(t_sp **t)
{
	(*t)->c_crd = pnts_to_vec(0, 0, 0);
	(*t)->diam = 0.0;
	(*t)->clr = make_clr(0, 0, 0);
}

void	init_tr(t_tr **t)
{
	(*t)->c_crd = pnts_to_vec(0, 0, 0);
	(*t)->n_crd = pnts_to_vec(0, 0, 0);
	(*t)->clr = make_clr(0, 0, 0);
	(*t)->s_crd = pnts_to_vec(0, 0, 0);
	(*t)->t_crd = pnts_to_vec(0, 0, 0);
}
