/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_move_cam.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 18:47:02 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/23 10:55:06 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_coord	set_rate(t_cams *c, double rate)
{
	double	cosa;
	double	sina;
	t_coord	tmp;
	t_coord	n;

	cosa = cos(rate * M_PI / 180);
	tmp = vec_sum(c->c_scr, vec_mult_scal(vec_mult_scal(c->n_crd, -1), cosa));
	n = vec_mult_vec(c->py, c->n_crd);
	sina = sin(rate * M_PI / 180);
	tmp = vec_sum(tmp, vec_mult_scal(n, sina));
	tmp = dots_to_vec(c->c_scr, tmp);
	vec_norm(&tmp);
	return (vec_sum(c->c_scr, vec_mult_scal(tmp, c->d)));
}

void	move_cam_fwrd(t_cams *cam)
{
	cam->c_crd = vec_substr(cam->c_crd, vec_mult_scal(cam->n_crd, 50));
}

void	move_cam_back(t_cams *cam)
{
	cam->c_crd = vec_sum(cam->c_crd, vec_mult_scal(cam->n_crd, 50));
}

void	move_cam_right(t_cams *cam, t_res *res)
{
	cam->c_crd = set_rate(cam, TRATE);
	cam->n_crd = dots_to_vec(cam->c_crd, cam->c_scr);
	vec_norm(&(cam->n_crd));
	get_scr_param(cam, res);
}

void	move_cam_left(t_cams *cam, t_res *res)
{
	cam->c_crd = set_rate(cam, -TRATE);
	cam->n_crd = dots_to_vec(cam->c_crd, cam->c_scr);
	vec_norm(&(cam->n_crd));
	get_scr_param(cam, res);
}
