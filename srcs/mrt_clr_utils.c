/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_clr_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:22:06 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/25 18:56:40 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		control_cy(t_scene **t, t_two dd, t_ans *ans, t_ans *shad)
{
	t_coord	n;
	t_cy	*cy;

	(void)t;
	(void)shad;
	cy = (t_cy *)ans->fig->data;
	n = get_n_cy(cy, ans->s);
	if (vec_scal_vec(n, dd.c2) <= 0)
		return (1);
	return (0);
}

int		check_ans(t_scene **t, t_ans *ans, t_ans *shad, t_two dd)
{
	if (ans->fig->type == CY)
		return (control_cy(t, dd, ans, shad));
	if (shad->d < vec_len(dd.c2) && shad->d > MIN)
	{
		if (vec_scal_vec(dd.c2, dots_to_vec(shad->s, dd.c1)) < 0)
			return (0);
		return (1);
	}
	if (ans->fig->type == PL)
		if (vec_scal_vec(dd.c2, ((t_pl *)(ans->fig->data))->n_crd) >= 0)
			return (1);
	if (ans->fig->type == SQ)
		if (vec_scal_vec(dd.c2, ((t_sq *)(ans->fig->data))->n_crd) >= 0)
			return (1);
	if (ans->fig->type == TR)
		if (vec_scal_vec(dd.c2, ((t_tr *)(ans->fig->data))->n_crd) >= 0)
			return (1);
	if (ans->fig->type == SP)
		if (vec_scal_vec(dots_to_vec((*t)->cams->c_crd, ans->s),
			dots_to_vec(((t_sp *)(ans->fig->data))->c_crd, ans->s)) >= 0)
			return (1);
	return (0);
}

void	calc_br(t_scene **t, t_ans *ans, t_clr *clr)
{
	double	br;
	t_lght	*light;
	t_ans	*shad;
	t_two	dd;

	malloc_ans(t, &shad);
	light = (*t)->lghts;
	*clr = make_clr(0, 0, 0);
	while (light)
	{
		wrap_dd(&dd, ans, light, shad);
		find_cross(t, dd, shad);
		dd.c1 = light->c_crd;
		if (check_ans(t, ans, shad, dd))
		{
			light = light->next;
			continue ;
		}
		br = get_angle(ans, light) * light->bright;
		if (br > 0)
			*clr = add_clr(*clr, use_bright(light->clr, br));
		light = light->next;
	}
	free_ans(&shad);
}

t_clr	add_clr(t_clr c1, t_clr c2)
{
	t_clr	ans;

	ans.r = c1.r + c2.r;
	if (ans.r > 255)
		ans.r = 255;
	if (ans.r < c1.r / COEF)
		ans.r = c1.r / COEF;
	ans.g = c1.g + c2.g;
	if (ans.g > 255)
		ans.g = 255;
	if (ans.g < c1.g / COEF)
		ans.g = c1.g / COEF;
	ans.b = c1.b + c2.b;
	if (ans.b > 255)
		ans.b = 255;
	if (ans.b < c1.b / COEF)
		ans.b = c1.b / COEF;
	return (ans);
}

int		calc_col(t_scene **t, t_ans *ans, t_clr clr)
{
	t_clr	tmp;

	tmp = make_clr(0, 0, 0);
	tmp = get_clr_fig(ans);
	tmp = use_bright(tmp, (*t)->alght->bright);
	tmp = add_clr(tmp, (*t)->alght->clr);
	tmp = add_clr(tmp, clr);
	return (rgb_to_int(tmp));
}
