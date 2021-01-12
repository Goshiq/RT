/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_clr_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:22:06 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/12 17:15:52 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	if (ans.r < c1.r / 3)
		ans.r = c1.r / 3;
	ans.g = c1.g + c2.g;
	if (ans.g > 255)
		ans.g = 255;
	if (ans.g < c1.g / 3)
		ans.g = c1.g / 3;
	ans.b = c1.b + c2.b;
	if (ans.b > 255)
		ans.b = 255;
	if (ans.b < c1.b / 3)
		ans.b = c1.b / 3;
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
	double	v_tmp;
	t_lght	*light;

	v_tmp = 0.0;
	light = (*t)->lghts;
	while (light)
	{
		if (ans->fig->type == SP)
			v_tmp = calc_col_sp(ans, light, &tmp);
		tmp = use_bright(tmp, (*t)->alght->bright);
		tmp = add_clr(tmp, (*t)->alght->clr);
		tmp = add_clr(tmp, use_bright(light->clr, v_tmp));
		light = light->next;
	}
	*clr = rgb_to_int(tmp);
}
