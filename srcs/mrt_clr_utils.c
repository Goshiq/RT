/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_clr_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:22:06 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/13 18:30:15 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#define COEF 1

int		rgb_to_int(t_clr clr)
{
	int	ans;

	ans = clr.r << 16 | clr.g << 8 | clr.b;
	return (ans);
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

t_clr	use_bright(t_clr clr, double br)
{
	t_clr	ans;

	ans.r = clr.r * br;
	ans.g = clr.g * br;
	ans.b = clr.b * br;
	return (ans);
}

void	calc_col(t_scene **t, t_ans *ans, int *clr)
{
	t_clr	tmp;
	t_clr	tmp_lgt;
	double	v_tmp;
	t_lght	*light;

	tmp = make_clr(0, 0, 0);
	tmp_lgt = make_clr(0, 0, 0);
	v_tmp = 0.0;
	light = (*t)->lghts;
	tmp = get_clr_fig(ans);
	tmp = use_bright(tmp, (*t)->alght->bright);
	tmp = add_clr(tmp, (*t)->alght->clr);
	while (light)
	{
		v_tmp = get_angle(ans, light);
		tmp_lgt = add_clr(tmp_lgt, use_bright(light->clr, v_tmp));
		light = light->next;
	}
	tmp = add_clr(tmp, tmp_lgt);
	*clr = rgb_to_int(tmp);
}
