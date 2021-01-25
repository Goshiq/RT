/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_add_next_cam.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 10:47:05 by jmogo             #+#    #+#             */
/*   Updated: 2021/01/25 19:48:00 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	mrt_add_cam_back(t_cams *cams, t_cams *new)
{
	t_cams	*tmp;

	tmp = cams->next;
	while (tmp->next != cams)
		tmp = tmp->next;
	tmp->next = new;
}

void	add_next_cam(t_scene **t, char **s)
{
	t_cams	*cam;

	cam = 0x0;
	mrt_malloc((void **)(&cam), CAMS, t);
	if (0 > (parse_coord(&(cam->c_crd), s[1], t)))
		mrt_doerr("Wrong camera's coordinates format:\n", s[1], t);
	if (0 > (parse_orient(&(cam->n_crd), s[2], t)))
		mrt_doerr("Wrong camera's orientation format:\n", s[2], t);
	if (0 > (parse_fov(&(cam->fov), s[3], t)))
		mrt_doerr("Wrong camera's FOV format:\n", s[3], t);
	cam->next = (*t)->cams;
	cam->prev = (*t)->cams->prev;
	get_scr_param(cam, (*t)->res);
	if ((*t)->cams->next == (*t)->cams)
		(*t)->cams->next = cam;
	else
		mrt_add_cam_back((*t)->cams, cam);
	(*t)->cams->prev = cam;
}
