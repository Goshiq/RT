/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_clr_fig.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:30:06 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/17 18:33:43 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_clr	get_clr_fig(t_ans *ans)
{
	t_clr	tmp;

	tmp = make_clr(0, 0, 0);
	if (ans->fig->type == SP)
		tmp = ((t_sp *)(ans->fig->data))->clr;
	if (ans->fig->type == PL)
		tmp = ((t_pl *)(ans->fig->data))->clr;
	if (ans->fig->type == CY)
		tmp = ((t_cy *)(ans->fig->data))->clr;
	if (ans->fig->type == SQ)
		tmp = ((t_sq *)(ans->fig->data))->clr;
	if (ans->fig->type == TR)
		tmp = ((t_tr *)(ans->fig->data))->clr;
	return (tmp);
}

t_clr	make_clr(int r, int g, int b)
{
	t_clr	res;

	res.r = r;
	res.g = g;
	res.b = b;
	return (res);
}
