/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_get_angle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 10:24:20 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/24 04:18:52 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	get_angle(t_ans *ans, t_lght *light)
{
	double	res;

	res = 0.0;
	if (ans->fig->type == SP)
		res = calc_ang_sp(ans, light);
	if (ans->fig->type == PL)
		res = calc_ang_pl(ans, light);
	if (ans->fig->type == SQ)
		res = calc_ang_pl(ans, light);
	if (ans->fig->type == TR)
		res = calc_ang_pl(ans, light);
	if (ans->fig->type == CY)
		res = calc_ang_cy(ans, light);
	return (res);
}

t_coord	get_n_cy(t_cy *cy, t_coord s)
{
	double	cos;
	double	len;
	t_coord	vec;
	t_coord	ans;

	vec = dots_to_vec(cy->c_crd, s);
	cos = fabs(vec_scal_vec(cy->n_crd, vec) / vec_len(vec));
	len = cos * vec_len(vec);
	vec = vec_sum(cy->c_crd, vec_mult_scal(cy->n_crd, len));
	ans = dots_to_vec(vec, s);
	vec_norm(&ans);
	return (ans);
}

double	calc_ang_cy(t_ans *ans, t_lght *light)
{
	double	res;
	t_coord	n;
	t_coord	dl;

	res = 0.0;
	n = get_n_cy((t_cy *)(ans->fig->data), ans->s);
	dl = dots_to_vec(ans->s, light->c_crd);
	res = vec_scal_vec(n, dl) / vec_len(dl);
	return (res);
}

double	calc_ang_pl(t_ans *ans, t_lght *light)
{
	double	res;
	t_coord	dl;
	t_coord	n;

	res = 0.0;
	n = ((t_pl *)(ans->fig->data))->n_crd;
	vec_norm(&n);
	dl = dots_to_vec(ans->s, light->c_crd);
	res = vec_scal_vec(n, dl) / vec_len(dl);
	if (res < 0)
		res *= -1;
	return (res);
}

double	calc_ang_sp(t_ans *ans, t_lght *light)
{
	double	res;
	t_coord	dl;
	t_coord	n;

	res = 0.0;
	n = dots_to_vec(((t_sp *)(ans->fig->data))->c_crd, ans->s);
	vec_norm(&n);
	dl = dots_to_vec(ans->s, light->c_crd);
	vec_norm(&dl);
	res = vec_scal_vec(n, dl);
	return (res);
}
