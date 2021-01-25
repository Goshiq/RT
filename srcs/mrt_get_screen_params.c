/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_get_screen_params.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 11:22:29 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/25 18:22:50 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_coord	loc_to_glob(int x, int y, t_cams *c)
{
	t_coord	ans;

	ans = vec_sum(vec_mult_scal(c->px, x), vec_mult_scal(c->py, y));
	ans = vec_sum(c->c_scr, ans);
	return (ans);
}

void	get_scr_param(t_cams *c, t_res *res)
{
	c->d = res->x / (2 * tan(c->fov * M_PI / 360));
	c->c_scr = mrt_get_c_screen(c);
	c->px = vec_mult_vec(c->n_crd, pnts_to_vec(0, 0, 1));
	if (c->px.x == 0 && c->px.y == 0 && c->px.z == 0)
		c->px = pnts_to_vec(1, 0, 0);
	else
		vec_norm(&(c->px));
	c->py = vec_mult_vec(c->px, c->n_crd);
	vec_norm(&(c->py));
}

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
