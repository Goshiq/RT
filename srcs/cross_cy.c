/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_cy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 04:34:34 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/24 20:19:03 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	control(double *t, t_cy *cy, t_two d)
{
	t_coord	vec[2];

	vec[0] = vec_sum(cy->c_crd, vec_mult_scal(cy->n_crd, cy->height));
	vec[1] = vec_sum(d.c1, vec_mult_scal(d.c2, *t));
	if (vec_scal_vec(cy->n_crd, vec_substr(vec[1], cy->c_crd)) <= 0)
		*t = -1;
	if (vec_scal_vec(cy->n_crd, vec_substr(vec[1], vec[0])) >= 0)
		*t = -1;
}

int		solve_cy(double *t, double *t1, t_cy *cy, t_two d)
{
	t_coord	vec[2];
	double	num[3];

	vec[0] = vec_substr(d.c2, vec_mult_scal(cy->n_crd,
								vec_scal_vec(d.c2, cy->n_crd)));
	num[0] = vec_scal_vec(vec[0], vec[0]);
	vec[1] = vec_substr(vec_substr(d.c1, cy->c_crd), vec_mult_scal(cy->n_crd,
				vec_scal_vec(vec_substr(d.c1, cy->c_crd), cy->n_crd)));
	num[1] = 2 * vec_scal_vec(vec[0], vec[1]);
	num[2] = vec_scal_vec(vec[1], vec[1]) - (cy->diam * cy->diam / 4);
	if (!have_res(num, t, t1))
		return (0);
	return (1);
}

void	cross_cy(t_two d, t_cy *cy, t_ans *ans)
{
	double	t[2];

	if (!solve_cy(&t[0], &t[1], cy, d))
		return ;
	if (t[0] > 0)
		control(&t[0], cy, d);
	if (t[1] > 0)
		control(&t[1], cy, d);
	if (t[0] < 0 && t[1] < 0)
		return ;
	if (t[1] < t[0])
		if (t[1] > 0)
			ans->d = t[1];
		else
			ans->d = t[0];
	else
	{
		if (t[0] > 0)
			ans->d = t[0];
		else
			ans->d = t[1];
	}
}
