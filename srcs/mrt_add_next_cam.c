/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_add_next_cam.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmogo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 10:47:05 by jmogo             #+#    #+#             */
/*   Updated: 2020/12/15 12:51:35 by jmogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	add_next_cam(t_scene **t, char **s)
{
	t_cams	*cam;

	if (!(cam = malloc(sizeof(t_cams))))
		mrt_doerr("Can't allocate memory for the new camera:\n", s[1], t);
	if (0 > (parse_coord(&(cam->c_crd), s[1])))
		mrt_doerr("Wrong camera's coordinates format:\n", s[1], t);
	if (0 > (parse_orient(&(cam->n_crd), s[2])))
		mrt_doerr("Wrong camera's orientation format:\n", s[2], t);
	if (0 > (parse_fov(&(cam->fov), s[3])))
		mrt_doerr("Wrong camera's FOV format:\n", s[3], t);
	cam->next = (*t)->cams;
	cam->prev = (*t)->cams->prev;
	cam->d = (*t)->res->x / (2 * tan(cam->fov * M_PI / 360));
	(*t)->cams->prev = cam;
	if ((*t)->cams->next == (*t)->cams)
		(*t)->cams->next = cam;
}
