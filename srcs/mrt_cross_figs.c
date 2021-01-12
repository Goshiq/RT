/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_cross_figs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 19:30:05 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/12 19:41:32 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	cross_sp(t_scene **t, t_coord cd, t_sp *sp, t_ans *ans)
{
	t_coord	c;
	t_coord	cs;
	double	cross;
	double	rad;

	c = (*t)->cams->c_crd;
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
		ans->fig->data = (void *)sp;
		ans->fig->type = SP;
		ans->fig->next = 0x0;

	}
}
