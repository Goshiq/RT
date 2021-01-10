/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_clr_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:22:06 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/09 16:21:34 by jmogo            ###   ########.fr       */
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

int		calc_col(t_scene **t, t_sp *sp, t_coord d)
{
	int		ans;
	t_clr	tmp;

	(void)d;
	tmp = add_clr(sp->clr, (*t)->alght->clr);
	ans = tmp.r << 16 | tmp.g << 8 | tmp.b;
	return (ans);
}
