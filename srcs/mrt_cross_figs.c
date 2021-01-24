/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_cross_figs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 19:30:05 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/24 14:04:08 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	cross_cy(t_scene **t, t_two d, t_cy *cy, t_ans *ans)
{
	t_coord	proec[3];
	t_coord	n[3];
	double	dist[6];

	(void)t;
	/*
	if (cross_cap(t, cy, d, ans))
		return ;*/
	n[0] = vec_mult_vec(d.c2, cy->n_crd);
	proec[0] = get_proec(cy->c_crd, d.c1, n[0], &(dist[0]));
	if (dist[0] > cy->diam / 2)
		return ;
	
	n[1] = vec_mult_vec(n[0], cy->n_crd);
	proec[1] = get_proec(proec[0], cy->c_crd, n[1], &(dist[1]));
	dist[2] = dist[1] / vec_scal_vec(d.c2, n[1]);
	dist[3] = sqrt(pow(cy->diam / 2, 2) - pow(dist[0], 2));
	dist[4] = dist[2] - dist[3];
	/*
	proec[1] = dots_to_vec(d.c1, proec[0]);
	vec_norm(&proec[1]);
	dist[1] = sqrt(1 - pow(vec_scal_vec(proec[1], cy->n_crd) /
										vec_len(proec[1]), 2));
	dist[2] = dist[1] * vec_len(proec[1]);
	dist[3] = dist[2] / sqrt(1 - pow(vec_scal_vec(d.c2, cy->n_crd), 2));
	dist[4] = sqrt(pow(cy->diam / 2, 2) - pow(dist[0], 2));
	dist[5] = dist[3] - dist[4];
	*/
	if (ans->d > dist[4] && in_cy(cy, d, dist[4]))
	{
		ans->d = dist[4];
		ans->s = vec_sum(d.c1, vec_mult_scal(d.c2, ans->d));
	}
}

void	cross_pl(t_scene **t, t_two d, t_pl *pl, t_ans *ans)
{
	t_coord	cp;
	double	co;
	double	c_pl;
	double	d_pl;

	(void)t;
	cp = dots_to_vec(d.c1, pl->c_crd);
	c_pl = vec_scal_vec(cp, pl->n_crd) / vec_len(cp);
	if (c_pl < -MIN)
	{
		pl->n_crd = vec_mult_scal(pl->n_crd, -1);
		c_pl *= -1;
	}
	d_pl = vec_scal_vec(d.c2, pl->n_crd) / vec_len(d.c2);
	if (d_pl <= 0)
		return ;
	co = vec_len(cp) * c_pl;
	ans->d = co / d_pl;
	c_pl = ans->d / vec_len(d.c2);
	cp = vec_mult_scal(d.c2, c_pl);
	ans->s = vec_sum(cp, d.c1);
}

void	cross_sp(t_scene **t, t_two d, t_sp *sp, t_ans *ans)
{
	t_coord	c;
	t_coord	cd;
	t_coord	cs;
	double	cross;
	double	rad;

	(void)t;
	c = d.c1;
	cd = d.c2;
	cs = dots_to_vec(c, sp->c_crd);
	if (vec_scal_vec(cs, cd) < 0)
		return ;
	rad = sp->diam / 2;
	cross = vec_len(vec_mult_vec(cs, cd)) / vec_len(cd);
	if (cross < rad)
	{
		ans->d = sqrt(pow(vec_len(cs), 2) - pow(cross, 2)) -
					sqrt(pow(rad, 2) - pow(cross, 2));
		rad = ans->d / vec_len(cd);
		cd = vec_mult_scal(cd, rad);
		ans->s = vec_sum(cd, c);
	}
}

void	cross_sq(t_scene **t, t_two d, t_sq *sq, t_ans *ans)
{
	double	d_pl;

	cross_pl(t, d, (t_pl *)sq, ans);
	if (ans->d == INFINITY)
		return ;
	d_pl = vec_scal_vec(d.c2, sq->n_crd) / vec_len(d.c2);
	if (d_pl <= 0 || (!in_sq(ans->s, sq)))
		ans->d = INFINITY;
}

void	cross_tr(t_scene **t, t_two d, t_tr *tr, t_ans *ans)
{
	double	d_pl;

	cross_pl(t, d, (t_pl *)tr, ans);
	if (ans->d == INFINITY)
		return ;
	d_pl = vec_scal_vec(d.c2, tr->n_crd) / vec_len(d.c2);
	if (d_pl <= 0 || (!in_tr(ans->s, tr)))
		ans->d = INFINITY;
}
