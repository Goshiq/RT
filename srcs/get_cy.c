/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 14:45:51 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/23 15:33:37 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	cross_cap(t_scene **t, t_cy *cy, t_ans *ans, t_two d)
{
	double	cosa;
	t_pl	*pl;
	int		top;

	init_pl(&pl);
	top = 0;
	pl->c_crd = cy->c_crd;
	pl->n_crd = cy->n_crd;
	pl->clr = cy->clr;
	if (0 > (cosa = vec_scal_vec(d.c2, cy->n_crd)))
	{
		pl->c_crd = cy->top;
		top = 1;
	}
	cross_pl(t, d, pl, ans);
	if (ans->d == INFINITY)
		return (0);
	if (vec_len(dots_to_vec(pl->c_crd, ans->s)) <= (cy->diam / 2))
	{
		cy->cap_top = 0;
		if (top)
			cy->cap_top = 1;
		return (1);
	}
	ans->d = INFINITY;
	return (0);
}
