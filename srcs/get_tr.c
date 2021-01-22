/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:12:12 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/22 19:42:44 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		check_side(t_coord n, t_coord p_pl, t_coord d, t_coord p)
{
	double	ans;

	ans = (d.x - p_pl.x) * n.x + (d.y - p_pl.y) * n.y + (d.z - p_pl.z) * n.z;
	ans *= (p.x - p_pl.x) * n.x + (p.y - p_pl.y) * n.y + (p.z - p_pl.z) * n.z;
	if (ans >= 0)
		return (1);
	return (0);
}

t_coord	find_n_tr(t_tr *tr)
{
	t_coord	ans;
	t_coord	side1;
	t_coord	side2;

	side1 = dots_to_vec(tr->c_crd, tr->s_crd);
	side2 = dots_to_vec(tr->c_crd, tr->t_crd);
	ans = vec_mult_vec(side1, side2);
	vec_norm(&ans);
	return (ans);
}

int		in_tr(t_coord p, t_tr *tr)
{
	t_coord	plane;

	plane = vec_mult_vec(dots_to_vec(tr->c_crd, tr->s_crd), tr->n_crd);
	if (!check_side(plane, tr->c_crd, p, tr->t_crd))
		return (0);
	plane = vec_mult_vec(dots_to_vec(tr->c_crd, tr->t_crd), tr->n_crd);
	if (!check_side(plane, tr->c_crd, p, tr->s_crd))
		return (0);
	plane = vec_mult_vec(dots_to_vec(tr->s_crd, tr->t_crd), tr->c_crd);
	if (!check_side(plane, tr->s_crd, p, tr->c_crd))
		return (0);
	return (1);
}
