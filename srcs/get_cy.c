/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 14:45:51 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/24 11:30:10 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
void	cross_cap(t_cy *cy, t_pl *pl, t_coord vec[2], t_ans *ans)
{
	double	num[3];

	(void)cy;
	num[0] = vec_scal_vec(dots_to_vec(vec[0], pl->c_crd), pl->n_crd);
	num[1] = vec_scal_vec(vec[1], pl->n_crd);
	if (num[1] == 0 || (num[0] > 0 && num[1] > 0) || (num[0] < 0 && num[1] < 0))
		return ;
	num[2] = -num[0] / num[1];
	if (num[2] < 0 || ans->d < num[2])
		return ;
	ans->d = num[2];
}
*/

t_ans	*check_pl(t_scene **t, t_pl *pl, t_two d, t_cy *cy)
{
	t_coord	vec;
	t_ans	*tmp;

	malloc_ans(t, &tmp);
	cross_pl(t, d, pl, tmp);
	vec = dots_to_vec(pl->c_crd, tmp->s);
	if (vec_len(vec) > (cy->diam / 2))
	{
		tmp->d = INFINITY;
		if (vec_scal_vec(vec, d.c2) > 0)
			tmp->d = -1;
	}
	return (tmp);
}

int		cross_cap(t_scene **t, t_cy *cy, t_two d, t_ans *ans)
{
	t_pl	*pl;
	t_ans	*tmp;

	if (!(pl = malloc(sizeof(t_pl))))
		mrt_doerr("Can't allocate memory!\n", 0x0, t);
	pl->c_crd = cy->c_crd;
	pl->n_crd = cy->n_crd;
	if (vec_scal_vec(d.c2, cy->n_crd) == 0)
		return (0);
	if (vec_scal_vec(d.c2, cy->n_crd) < 0)
		pl->c_crd = cy->top;
	tmp = check_pl(t, pl, d, cy);
	free(pl);
	if (ans->d > tmp->d)
	{
		if (tmp->d > 0)
		{
			ans->d = tmp->d;
			ans->s = tmp->s;
		}
		free_ans(&tmp);
		return (1);
	}
	free_ans(&tmp);
	return (0);
}

int		in_cy(t_cy *cy, t_two d, double dist)
{
	t_coord	vec;
	t_coord	n;
	double	tmp;

	vec = vec_sum(d.c1, vec_mult_scal(d.c2, dist));
	tmp = 0.0;
	n = cy->n_crd;
	get_proec(vec, cy->c_crd, n, &tmp);
	if (cy->height >= tmp)
		return (1);
	tmp = 0.0;
	n = cy->n_crd;
	get_proec(vec, cy->top, n, &tmp);
	if (cy->height > tmp)
		return (1);
	return (0);
}
