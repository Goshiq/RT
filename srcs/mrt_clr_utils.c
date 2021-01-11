/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_clr_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:22:06 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/11 13:45:56 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_clr	add_clr(t_clr c1, t_clr c2)
{
	t_clr	ans;

	ans.r = c1.r + c2.r;
	if (ans.r > 255)
		ans.r = 255;
	ans.g = c1.g + c2.g;
	if (ans.g > 255)
		ans.g = 255;
	ans.b = c1.b + c2.b;
	if (ans.b > 255)
		ans.b = 255;
	return (ans);
}

t_clr	use_bright(t_clr clr, double br)
{
	t_clr	ans;

	ans.r = clr.r * br;
	ans.g = clr.g * br;
	ans.b = clr.b * br;
	return (ans);
}

int		calc_col(t_scene **t, t_sp *sp, t_coord d)
{
	int		ans;
	t_clr	tmp;
	t_coord	dl;
	t_coord	n;
	double	v_tmp;
	t_lght	*light;

	tmp = add_clr(sp->clr, (*t)->alght->clr);
	light = (*t)->lghts;
	n = dots_to_vec(sp->c_crd, d);
	vec_norm(&n);
	while (light)
	{
		dl = dots_to_vec(d, light->c_crd);
		v_tmp = vec_scal_vec(n, dl) / vec_len(dl);
		if (v_tmp > 0)
			tmp = add_clr(tmp, use_bright(light->clr, v_tmp));
		light = light->next;
	}
	ans = tmp.r << 16 | tmp.g << 8 | tmp.b;
	return (ans);
}
