/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_cy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 04:34:34 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/24 07:11:01 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
void	pierce_cy(t_two d, t_cy *cy, t_ans *ans, double num[6])
{
	t_coord	vec[2];
	t_pl	*pl;
	double	dist;

	dist = INFINITY;
	pl = malloc(sizeof(t_pl));
	init_pl(&pl);
	if (num[4] >= 0 && ans->d > num[4])
		dist = num[4];
	if (num[5] >= 0 && ans->d > num[5])
		dist = num[5];
	if (dist == INFINITY)
		return ;
	vec_norm(&(d.c2));
	vec[0] = vec_sum(d.c1, vec_mult_scal(d.c2, dist));
	vec[1] = cy->n_crd;
	pl->n_crd = cy->n_crd;
	pl->c_crd = cy->c_crd;
		ans->d = INFINITY;
	cross_cap(cy, pl, vec, ans);
	if (ans->d < cy->height / 2)
	{
		ans->d = dist;
		ans->s = vec_sum(d.c1, vec_mult_scal(d.c2, dist));
	}
	vec[1] = vec_mult_scal(cy->n_crd, -1);
	cross_cap(cy, pl, vec, ans);
	if (ans->d < cy->height / 2)
	{
		ans->d = dist;
		ans->s = vec_sum(d.c1, vec_mult_scal(d.c2, dist));
	}
}

void	cross_cy(t_scene **t, t_two d, t_cy *cy, t_ans *ans)
{
	double	num[6];
	t_coord	vec[5];

	(void)t;
	vec[0] = vec_mult_vec(d.c2, cy->n_crd);
	vec[1] = dots_to_vec(d.c1, cy->c_crd);
	vec[2] = vec_mult_vec(vec[1], cy->n_crd);
	vec[3] = d.c1;
	vec[4] = d.c2;
	num[0] = vec_scal_vec(vec[0], vec[0]);
	num[1] = vec_scal_vec(vec[0], vec[2]) * 2;
	num[2] = vec_scal_vec(vec[2], vec[2]) - pow(cy->diam / 2, 2) *
											vec_scal_vec(cy->n_crd, cy->n_crd);
	num[3] = pow(num[1], 2) - 4 * num[0] * num[2];
	if (num[3] < 0)
		return ;
	num[0] = 2 * num[0];
	num[3] = sqrt(num[3]);
	num[4] = (-num[1] - num[3]) / num[0];
	num[5] = (-num[1] + num[3]) / num[0];
	pierce_cy(d, cy, ans, num);
}*/
