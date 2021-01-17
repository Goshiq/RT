/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_cross_figs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 19:30:05 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/17 18:51:02 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	cross_cy(t_scene **t, t_two cd, t_cy *cy, t_ans *ans)
{
	(void)t;
	(void)cd;
	(void)cy;
	(void)ans;
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
	if (c_pl < -0.005)
	{
		pl->n_crd = vec_mult_scal(pl->n_crd, -1);
		c_pl *= -1;
	}
	co = vec_len(cp) * c_pl;
	d_pl = vec_scal_vec(d.c2, pl->n_crd) / vec_len(d.c2);
	if (d_pl <= 0)
		return ;
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
	t_coord	line;
	double	side;

	cross_pl(t, d, (t_pl *)sq, ans);
	if (ans->d == INFINITY)
		return ;
	line = dots_to_vec(ans->s, sq->c_crd);
	side = sq->side;
	if (fabs(line.x) > side / 2 ||
		fabs(line.y) > side / 2 ||
		fabs(line.z) > side / 2)
		ans->d = INFINITY;
}

void	cross_tr(t_scene **t, t_two cd, t_tr *sq, t_ans *ans)
{
	(void)t;
	(void)cd;
	(void)sq;
	(void)ans;
}
