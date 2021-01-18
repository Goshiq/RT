/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_move_cam.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 18:47:02 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/18 19:35:55 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	move_cam_fwrd(t_cams *cam)
{
	cam->c_crd = vec_substr(cam->c_crd, vec_mult_scal(cam->n_crd, 10));
}

void	move_cam_back(t_cams *cam)
{
	cam->c_crd = vec_sum(cam->c_crd, vec_mult_scal(cam->n_crd, 10));
}
