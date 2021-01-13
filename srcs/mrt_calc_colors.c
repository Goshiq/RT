/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_calc_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:43:08 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/13 08:50:07 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	calc_col_sp(t_ans *ans, t_lght *light, t_clr *tmp)
{
	double	col;
	t_coord	dl;
	t_coord	n;

	*tmp = ((t_sp *)(ans->fig->data))->clr;
	n = dots_to_vec(((t_sp *)(ans->fig->data))->c_crd, ans->s);
	vec_norm(&n);
	dl = dots_to_vec(ans->s, light->c_crd);
	col = vec_scal_vec(n, dl) / vec_len(dl);
	return (col);
}
