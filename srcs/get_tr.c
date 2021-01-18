/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:12:12 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/18 19:43:55 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	get_sign(t_coord fp, t_coord sp, t_coord tp)
{
	return (fp.x - tp.x) * (sp.y - tp.y) - (sp.x - tp.x) * (fp.y - tp.y);
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

void	check_n_tr(t_two d, t_coord *n, t_tr *tr)
{
	double	c_pl;
	t_coord	cp;

	cp = dots_to_vec(d.c1, tr->c_crd);
	c_pl = vec_scal_vec(cp, *n) / vec_len(cp);
	if (c_pl < -MIN)
		*n = vec_mult_scal(*n, -1);
}

int		in_tr(t_coord p, t_coord fp, t_coord sp, t_coord tp)
{
	double	d1;
	double	d2;
	double	d3;
	int		is_neg;
	int		is_pos;

	d1 = get_sign(p, fp, sp);
	d2 = get_sign(p, sp, tp);
	d3 = get_sign(p, tp, fp);
	is_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	is_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
	return (!(is_neg && is_pos));
}
