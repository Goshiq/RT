/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_get_c_screen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 11:22:29 by jmogo             #+#    #+#             */
/*   Updated: 2020/12/23 11:36:52 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_coord	mrt_get_c_screen(t_cams *cam)
{
	t_coord	ans;
	double	len;
	t_coord	c;
	t_coord	n;

	c = cam->c_crd;
	n = cam->n_crd;
	len = cam->d / vec_len(n);
	if (len)
	{
		ans = vec_mult_scal(n, len);
		ans = vec_sum(c, ans);
		return (ans);
	}
	else
		return (vec_mult_scal(c, 0));
}
