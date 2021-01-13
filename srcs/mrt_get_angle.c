/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_get_angle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 10:24:20 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/13 10:26:42 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	get_angle(t_ans *ans, t_lght *light)
{
	double	res;

	res = 0.0;
	if (ans->fig->type == SP)
		res = calc_ang_sp(ans, light);
	return (res);
}

double	calc_ang_sp(t_ans *ans, t_lght *light)
{
	double	res;
	t_coord	dl;
	t_coord	n;

	n = dots_to_vec(((t_sp *)(ans->fig->data))->c_crd, ans->s);
	vec_norm(&n);
	dl = dots_to_vec(ans->s, light->c_crd);
	res = vec_scal_vec(n, dl) / vec_len(dl);
	return (res);
}
